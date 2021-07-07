#include <string>
#include <iostream>
#include <cstring>

int main()
{
    const char a[] = "aaa";
    const char b[] = "bbb";
    char *pca = new char[strlen("aaa"
                                "bbb") +
                         1];

    std::strcat(pca, a);
    std::strcat(pca, b);
    std::cout << std::string(pca) << std::endl;
    std::cout << pca << std::endl;

    delete[] pca;

    std::string c = "ccc";
    std::string d = "ddd";
    std::string *ps = new std::string;

    *ps = c + d;
    std::cout << *ps << std::endl;
    delete ps;

    return 0;
}
