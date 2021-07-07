#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> *create_vi()
{
    return new vector<int>;
}

void push_vi(vector<int> *p)
{
    int i;
    while (cin >> i)
        p->push_back(i);
}

void print_vi(vector<int> *p)
{
    for (const auto i : *p)
        cout << i << endl;
}

int main()
{
    auto p = create_vi();
    push_vi(p);
    print_vi(p);
    delete p;
    return 0;
}
