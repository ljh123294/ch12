#ifndef TEXTQUERY_H_
#define TEXTQUERY_H_
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>
#include <fstream>
#include <make_plural.h>
using namespace std;
using line_no = vector<string>::size_type;

struct QueryResult;

struct TextQuery
{
private:
    shared_ptr<vector<string>> text;
    map<string, std::shared_ptr<set<line_no>>> m;

public:
    TextQuery(ifstream &);
    QueryResult query(string &) const;
};

TextQuery::TextQuery(ifstream &ifs) : text(new vector<string>)
{
    string line;
    while (getline(ifs, line))
    {
        text->push_back(line);
        int r = text->size() - 1;
        istringstream iss(line);
        string word;
        while (iss >> word)
        {
            auto &lines = m[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(r);
        }
    }
}

QueryResult TextQuery::query(string &s) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = m.find(s);
    if (loc == m.end())
        return QueryResult(s, nodata, text);
    else
        return QueryResult(s, loc->second, text);
}

struct QueryResult
{
    friend ostream &print(ostream &, const QueryResult &);

private:
    string word;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> text;

public:
    QueryResult(string s, shared_ptr<set<line_no>> lines_, shared_ptr<vector<string>> text_) : word(s), lines(lines_), text(text_) {}
};

ostream &print(ostream &os, const QueryResult &qr)
{
    os << qr.word << " occurs " << qr.lines->size() << " " << make_plural(qr.lines->size(), "time", "s") << endl;
    for (const auto &num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << (*qr.text)[num] << endl;
}

void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        print(cout, tq.query(s)) << endl;
    }
}

int main()
{
    ifstream ifs("txt");
}
#endif