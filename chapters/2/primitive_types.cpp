#include <iostream>

int main()
{
    /*
    manipulate the cout to print the actual boolean not int
    */
    bool b = true;
    std::cout << "boolean before boolalpha: " << b << std::endl;
    // std::cout << std::boolalpha;
    // std::cout << "boolean after boolalpha: " << b << std::endl;

    int i = b;
    std::cout << "assigning boolean to int: " << i << std::endl;

    i = 3.14;
    std::cout << "assigning a double to existing int var: " << i << std::endl;

    double d = i;
    std::cout << "assigning int to double: " << d << std::endl;

    unsigned char c = -188;
    std::cout << "assigning a negative number to unsigned char: " << c << std::endl;

    signed char s = 74;
    std::cout << "assigning a negative number to signed char: " << s << std::endl;

}