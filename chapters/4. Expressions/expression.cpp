#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <bitset>

using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(){
    // unary operator and binary operators
    //unary operator operates on one operand. e.g. &, *
    //binary operator operates on two
    // * for example is overloaded depending on different context
    // unary operator have higher precedence

    //grouping operators

    //lvalue and rvalue
    //an assignment has lvalue on the left and rvalue on the right
    //lvalue is mostly a type or definition; rvalue is the value
    // this changes when we are using decltype() and right hand side turns into a type

    //order of evaluation
    //say int i = f() + g()*h() + j(); 
    //g()*h() will be evaulated and gh, f, j will be added. but no gaurantee which on gets evaluated first
    

    //logical operators
    //The right side of an && is evaluated if and only if the left side is true.
    //The right side of an || is evaluated if and only if the left side is false.

    int val = -2;
    if (val){ // this will be true for any integral value non-zero
        std::cout << "condition is true" << std::endl;
    }

    //assignment is right associative
    // int i, j;
    // i = j = 0;
    //Because assignment is right associative, the right-most assignment, jval = 0, is 
    // the right-hand operand of the left-most assignment operator. Because assignment
    // returns its left-hand operand, the result of the right-most assignment (i.e., jval) is 
    // assigned to ival

    //compound assignment 
    // +=, -=, *=, /=, %= arithmetic
    //bitwise operators <<=，>>=, &=, ^=, |=

    //Incremental
    int i = 0, j;
    j = ++i; //prefix yields the incremented value
    std::cout << j << std::endl;
    j = i++; //postfix yields the unincremented value
    std::cout << j << std::endl;


    // combining dereference and increment
    std::vector<int> v(5, 1);
    auto pbeg = v.begin();
    while (pbeg != v.end() && *pbeg >=0){
        std::cout << *pbeg ++ << std::endl; //print and advance pointer
        //The precedence of postfix increment is higher than that of the dereference oper-
        // ator, so *pbeg++ is equivalent to *(pbeg++)
    }

    // member access operators
    std::string s1 = "hello";
    std::string *p = &s1;
    std::cout << (*p).size() << std::endl; //equivalent
    std::cout << p->size() << std::endl;

    //Bitwise
    unsigned int bi = 1;//32bit int 
    assert(bi == 0b00000000000000000000000000000001); 
    assert(~bi == 0b11111111111111111111111111111110); 
    assert(~bi >> 1 == 0b01111111111111111111111111111111);
    assert(bi << 1 == 0b0010);
    assert(bi & !bi == 0);

    //example
    //set bit 27 to one
    unsigned long quiz1 = 1UL << 27; 
    cout << std::bitset<32>(quiz1) << endl;

    //check if a bit is set
    cout << ((quiz1 >> 27) & 1) << endl;

    //set a bit (or)
    cout << std::bitset<32>((quiz1 | (1 << 26))) << endl;
    //flip a bit (xor)
    cout << std::bitset<32>(quiz1 ^ (1 << 27)) << endl;

    //check if a bit is set
    cout << "Check if 27th bit is set: " << (quiz1 == (1 << 27)) << endl;
    //alternatively better
    cout << "Check if 27th bit is set: " << ((quiz1 >> 27) & 1) << endl;

    //check if number is power of 2
    cout << "Check if number is power of 2: " << (quiz1 && (!(quiz1 & (quiz1-1)))) << endl;

    //check if number is divisible by 2^k
    //==check if n&(2^k-1) = 0
    cout << "Check if divisble by 2^5: " << !(quiz1 & (1<<5 - 1)) << endl;

    //sizeof() return the size in bytes

    //this does not print out the size of the entire vector
    //but the size of the vector object itself
    std::vector<int> vec(10000, 1);
    cout << sizeof(vec) << endl; 
    cout << "Total size (bytes): " << vec.size() * sizeof(int) << endl;

    //https://cp-algorithms.com/algebra/bit-manipulation.html
    //check for more details

    //different for arrays
    int *ia[10];
    cout << sizeof(ia) << endl; //size of the entire array
    cout << sizeof(*ia) << endl; //size of first element

    //comma
    vector<int> ivec(10, 1);
    vector<int>::size_type cnt = ivec.size();
    //The comma operator takes two operands, which it evaluates from left to right. 
    for(vector<int>::size_type ix=0; ix!= ivec.size(); ++ix, --cnt){
        ivec[ix] = cnt;
    }
    for (auto iv:ivec){
        cout << iv << endl;
    }

    //type conversions
    //integral promotions converts small integral types to larger
    bool flag; char cval;
    short sval; unsigned short usval;
    int ival; unsigned int uival;
    long lval; unsigned long ulval;
    float fval; double dval;
    3.14159L + 'a'; // ’a’ promoted to int, then that int converted to long double
    dval + ival; // ival converted to double
    dval + fval; // fval converted to double
    ival = dval; // dval converted (by truncation) to int
    flag = dval; // if dval is 0, then flag is false, otherwise true
    cval + fval; // cval promoted to int, then that int converted to float
    sval + cval; // sval and cval promoted to int
    cval + lval; // cval converted to long
    ival + ulval; // ival converted to unsigned long
    usval + ival; // promotion depends on the size of unsigned short and int
    uival + lval; // conversion depends on the size of unsigned int and long

    //explicit conversion
    double d = 3.14;
    int pi = static_cast<int>(d);
    cout << pi << endl;

    //const cast
    const char *pc;
    char *pc1 = const_cast<char*>(pc);

    //operator precedence
    //page 166
    return 0;
}