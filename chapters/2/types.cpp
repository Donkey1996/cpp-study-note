#include <iostream>
#include <string>

struct Cordinate
{
    double x = 0.0;
    double y = 0.0;
    std::string getStringCordinate();
};

std::string Cordinate::getStringCordinate(){
    return std::to_string(x) + " " + std::to_string(y);
}

double fnc()
{
    return 0.1;
}

int main()
{
    /*
        2.5.1 type alias
    */
    //typedef is the traditional way
    typedef double wages;
    typedef wages base, *p;


    double *wage1 = new double(42.0);
    p wage2 = wage1;
    p wage3 = new double(43.9);

    //new standard is 'using'
    using C = Cordinate; 
    C c1;
    c1.x = 1.0;
    c1.y = 2.0;
    std::cout << c1.getStringCordinate() << std::endl;

    //const
    using pstring = char*;

    char ch = 'a';
    const pstring cstr1 = &ch; // top level const !
    *cstr1 = 'b'; // cstr1 is a const pointer to char 
    std::cout << *cstr1 << std::endl;
    // const char *cstr2 = 0; // low level const
    // *cstr2 = 'a'; // not allowed cstr is a pointer to a const char


    /*
        2.5.2 Auto
    */
    int va = int{4};
    double vb = double(3.1);
    auto sum = va + vb;
    std::cout << sum << std::endl;
    // auto x = 1.0, y = 1; //error - inconsistent types

    int i = 0, &r = i;
    auto a = r; // a is an lvalue reference

    //top level const is dropped when using auto
    const int ci = i, &cr = ci;
    auto b = ci; // b is an int (top-level const in ci is dropped)
    auto c = cr; // c is an int (cr is an alias for ci whose const is top-level)
    auto d = &i; // d is an int* (& of an int object is int*)
    auto e = &ci; // e is const int* (& of a const object is low-level const)

    const auto f = ci; // f is a top level const int
    std::cout << f << std::endl;

    const auto &j = 42; // can only bound a const auto ref to a literal
    // auto &j = 42; // error

    /*
        2.5.3 decltype
    */

    decltype(fnc()) fv;
    std::cout << fv << std::endl;

    //deceltype and reference

    int i2 = 42, *p2 = &i2, &r2 = i2;
    decltype(r2+0) b1; //r + 0 yields an int type that does not need to be initialized
    // decltype(*p2) c2; // error: ‘c2’ declared as reference but not initialized
    /*
        When we apply decltype to a variable without any
        parentheses, we get the type of that variable.
    */

    // decltype((i2)) d; // error - d has a type int& and must be initialized
}