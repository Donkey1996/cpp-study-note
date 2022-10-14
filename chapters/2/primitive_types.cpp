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

    unsigned long a = -42949670960000;
    std::cout << "assigning signed value to unsigned type: " << a << std::endl;

    // dont mix up signed with unsigned
    signed si = -10;
    unsigned u = 9;
    std::cout << "unsigned: " << u << std::endl;
    std::cout << "signed value: " << si << std::endl;
    std::cout << "adding signed to unsigned type: " << u+si << std::endl;

    // cannot use >= here since unsigned will never be leff than 0
    for (unsigned u = 10; u > 0; u--)
    {
        std::cout << "Unsigned " << u << std::endl;
    }
    // generally just dont use unsigned

    //Literals
    int l_1 = 0x15; //hexadecimal
    int l_2 = 024; //octal
    std::cout << "Hexadecimal 0x15 is " << l_1 << " and Octal 024 is " << l_2 << std::endl;

    //strings
    std::string st = "abc";
    char ch = 'a';
    std::cout << "string is " << st << " and char is " << c << std::endl;

    //can just pass a string directly to io
    std::cout << "absolutely a string" << std::endl;

    //long string formatting
    std::cout << "hahahahhahahahahhahahahahahhahahahhaahhahahahahhaha "
    "im too long" << std::endl;

    //escapes
    //decorations to the strings to print
    std::cout << "new line? \nyes!" << std::endl;
    std::cout << "vertical tab? \v yes" << std::endl;
    std::cout << "backlash \\" << std::endl;
    std::cout << "carriage \r return" << std::endl;
    std::cout << "horizontal tab? \t yes" << std::endl;
    std::cout << "backspace \b yes" << std::endl;
    std::cout << "formfeed \f yes" << std::endl;
    std::cout << "alert \a bell" << std::endl;
    std::cout << "\"double quote.\"" << std::endl;

    //escape sequences
    std::cout << "what's in here? \x2B3349 ha" << std::endl;
    std::cout << "\tTabbed and new line\n" << std::endl;
    std::cout << "end of primitive types" << std::endl;
}