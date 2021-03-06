#include "StrBlob_20.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream f("../ch08_The_IO_Library/data");
    StrBlob b1;

    for (std::string s; std::getline(f, s);)
        b1.push_back(s);

    for (StrBlobPtr beg = b1.begin(), ed = b1.end(); beg != ed; beg.incr())
        std::cout << beg.deref() << std::endl;

    return 0;
}
