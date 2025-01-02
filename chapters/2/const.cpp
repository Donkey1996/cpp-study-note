#include <iostream>
#include <memory>


constexpr int size(){
    return 10;
}


int main()
{
    //2.4 const qualifers
    // Const qualifier indicates a variable cannot be changed after creation
    const int bufSize = 512;
    // error modifying the const variable
    // bufSize = 123;

    // const int badConstVar;
    // error: initialization of badConstVar from itself

    int bufSizeCopy = bufSize; //can copy const var
    bufSizeCopy = 123; //allowed since it's a copy and doesn't modify the original

    std::cout << bufSizeCopy << std::endl;
    
    int i1 = 42;
    const int &r1 = i1; //r1 is a const reference to i
    // r1 = 24; //error: assignment of read-only reference 'r1'

    // const int i2 = 41;
    // int &r2 = i2; //error: cannot bind non-const lvalue
    
    int i2 = 1;
    const int &r2 = i2; //allowed since i2 is not const

    // const annd pointers 
    // modern c++ pointers

    const std::unique_ptr<int> ptr = std::make_unique<int>(42);

    std::cout << *ptr << std::endl;


    /* 
        A pointer to const.
        Defining a pointer as a pointer to
        const affects only what we can do with the pointer. It is important to remember
        that there is no guarantee that an object pointed to by a pointer to const won’t
        change.
    */
    *ptr = 1; // can change value in a const unique_ptr but not what it's referring to 
    std::cout << *ptr << std::endl;

    double pi = 3.14;
    const double *dptr = &pi;
    double dval = 3.15;
    // *dptr = 1.0; //not allowed to change values of aconst pointer but can change its ref
    dptr = &dval; //allowed to change the pointer itself

    std::cout << *dptr << std::endl;
    dval = 1.5;
    //can change the object that const point is pointing to
    //the const modifier on the pointer only means cannot modify 

    std::cout << *dptr << std::endl; 
    

    /*
        Const pointers.
        Like any other const object, a const
        pointer must be initialized, and once initialized, its value (i.e., the address that it
        holds) may not be changed. 
    */
    int errNumber = 1;
    int *const currentError = &errNumber; // currentError will always be a pointer to errNumber
    // currentError = &errNumber; //not allowed to change the value of a const pointer

    const double natural_log = 2.71;
    const double *const natural_log_ptr = &natural_log; // pointer to const and const pointer

    // *natrual_log_ptr = 2.70; // cannot change the value of a const pointer 

    // int i = -1, &r = 0; // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’

    // const int i3 = 1;
    // const int &const r3 = i3; // error: ‘const’ qualifiers cannot be applied to ‘const int&’


    /*
        Top level const
        We use the term top-level const to
        indicate that the pointer itself is a const. When a pointer can point to a const
        object, we refer to that const as a low-level const.
    */
    //in std::unique_ptr case, const to the left means it's low-level
    // if we want a top-level we need to make the type const int
    const std::unique_ptr<const int> topLevelConstPointer = std::make_unique<int>(42);

    std::cout << *topLevelConstPointer << std::endl;

    //In this setup, you cannot modify either value or address of the pointer
    // *topLevelConstPointer = 41; // Error
    // std::unique_ptr<const int> another = std::make_unique<int>(20);
    // ptr = std::move(another); // Error

    const int ci = 42; // const is top level and cannot change ci
    const int *p2 = &ci; // low level, we can change address of p2 not the ref value
    const int *const p3 = p2; //low level to the left and top level to the right
    const int &r = ci; // low level const in ref, cannot change r

    p2 = p3; // Copying ignores the top level const
    // int *p = p3; // error p3 has a low level const but not p
    const int *const p = p3; //allowed because p had both lower and top level like p3
    std::cout << *p <<std::endl;
    /*
        constexpr
        A constant expression is an expression whose value cannot change and that can
        be evaluated at compile time. A literal is a constant expression. A const object
        that is initialized from a constant expression is also a constant expression.
    */

    // static constexpr int mf = 29;
    // static constexpr int sz = size(); // can only do so if the fucntion returns a constexpr
    
    // constexpr with pointers
    // static constexpr int *q = nullptr; // q is a const pointer to int, top-level const
    // *q = 1; //this is allowed

    // static constexpr int cei = 42; // add static to make sure the address is constexpr
    // constexpr const int *cpi = &cei; // Works
    // std::cout << *cpi << std::endl;

    // // Declare `j` as constexpr if its address needs to be constexpr
    // static int j = 41;
    // constexpr int *pj = &j; // Works
    // std::cout << *pj << std::endl;
    return 0;
}