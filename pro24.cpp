#include <iostream>
int main()
{
    std::cout << "how long do you want the string? ";
    int size(0);
    std::cin >> size;
    char *input = new char[size + 1]();
    std::cin.ignore();
    std::cout << "input the string: ";
    std::cin.get(input, size + 1);
    std::cout << input;
    delete[] input;
}