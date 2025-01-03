#include <iostream>
// extern int not_declared;
int i = 100;
int main()
{
    std::cout << "This is the study note for variables" << std::endl;
    /*
    two ways to initialize variables
    */
    int integerOne = 1;
    int integerTwo(2);
    std::cout << "Integer one: " << integerOne << std::endl;
    std::cout << "Integer two: " << integerTwo << std::endl;

    long double price = 101.998877, discountedPrice = price*0.88;
    std::cout << "Price: $" << price << std::endl;
    std::cout << "Didscounted Price: $" << discountedPrice << std::endl;

    std::cout.precision(10); //changing print precision
    std::cout << "After changing print precision \nPrice: $" << price << std::endl;
    std::cout << "Didscounted Price: $" << discountedPrice << std::endl;

    /*
        list initialization
    */
    int testOne = 1;
    int testTwo = {2};
    int testThree(3);
    int testFour{4};
    std::cout << "Test One: " << testOne << std::endl;
    std::cout << "Test Two: " << testTwo << std::endl;
    std::cout << "Test Three: " << testThree << std::endl;
    std::cout << "Test Four: " << testFour << std::endl;

    /*
        Cannot use {} initialization if there is a loss of information
    */
    double moreInfo = 9.997;
    int lessOne = {moreInfo}; //will get warnings for narrowing conversion
    int lessTwo = moreInfo;
    int lessThree{moreInfo}; //will get warnings for narrowing conversion
    int lessFour(moreInfo);
    std::cout << "Less One: " << lessOne << std::endl;
    std::cout << "Less Two: " << lessTwo << std::endl;
    std::cout << "Less Three: " << lessThree << std::endl;
    std::cout << "Less Four: " << lessFour << std::endl;

    //Defualt initialization
    std::string empty;
    std::cout << empty << std::endl;

    /*error
    int catch-22;
    std::cout << 'Error' << catch-22 << std::endl;
    */
    int declared;
    extern int not_declared;
    /*
    https://stackoverflow.com/questions/10422034/when-to-use-extern-in-c
    This comes in useful when you have global variables. 
    You declare the existence of global variables in a header, 
    so that each source file that includes the header knows about it, 
    but you only need to “define” it once in one of your source files.

    To clarify, using extern int x; tells the compiler that an object of type int 
    called x exists somewhere. It's not the compilers job to know where it exists, 
    it just needs to know the type and name so it knows how to use it. 
    Once all of the source files have been compiled, the linker will resolve all 
    of the references of x to the one definition that it finds in one of the compiled 
    source files. For it to work, the definition of the x variable needs to have 
    what's called “external linkage”, which basically means that it needs to be 
    declared outside of a function (at what's usually called “the file scope”) 
    and without the static keyword.
    */

    // std::cout << "Not Declared" << not_declared << std::endl; //error
    std::cout << "Declared: " << declared << std::endl;//no error
    // extern int declaredGlobal = 100;//an error if we declare initialization to a definition
    // std::cout << "Global: " << declaredGlobal << std::endl;

    int i = 10;//overwrites the declaration on top
    int j = 1;
    std::cout <<"ij: " << i << j<< std::endl;
}