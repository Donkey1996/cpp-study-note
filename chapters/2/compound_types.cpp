//a compound type is a type that consists of other types

#include <iostream>
using namespace std;

int main()
{
    // 2.3.1 References
    // A reference defines an alternative name for a variable
    // It is not a new object but simply a another name
    int i(1);
    int &referenceI = i;
    cout << i << endl;
    cout << "the value of the reference: " << referenceI << endl;
    cout << "the address: " << &referenceI << endl;
    int &referenceI2 = referenceI;
    cout << "Reference of reference: " << referenceI2 << endl;// yields same result as original variable
    cout << "Reference of reference: " << &referenceI2 << endl;// a different address than the first reference

    // cannot create an empty reference
    // int &emptyReference; 
    // will throw error: declared as reference but not initalized

    // reference must be initialized with an object
    /*
    int &intReference = 1;
    cout << intReference << endl;
    */
    
    // 2.3.2 Pointers
    // * can be used to create a pointer
    // * can also be used as a dereference operator
    string food = "Burger";
    cout << food << endl;
    cout << &food << endl;
    string *ptr = &food; // define the point ptr to food
    cout << ptr << endl; // pointer to the address
    cout << *ptr << endl; // dereference to get the original data


    // string *ptr2 = food; // error need & operator
    // cout << ptr2 << endl;

    // cannot assign different type to the pointer of type string
    double d;
    double *ptr2 = &d;
    double *ptr3 = ptr2;
    *ptr2 = 2.0;
    cout << ptr2 << endl;  
    cout << *ptr2 << endl;

    //null pointers
    int *nullPointer1 = 0;
    int *nullPointer2 = nullptr;
    // cout << *nullPointer1 << endl;
    // cout << *nullPointer2 << endl;
    // note: this will cause compiler error
    // but will produce a segmentation fault (core dumped)
    // namely, a specific kind of error caused by accessing memory that “does not belong to you.”
    // !!!UNINITIALIZED POINTERS ARE SOURCE OF RUNTIME ERRORS!
    // initialize all pointers at declaration

    // Assignments and pointers
    // Reference: once we define a reference, we cannot make the reference refer to a different object
    // Pointers: can be reassigned to point to a different location/object

    int i2 = 42;
    int *ptr4 = 0; //null pointer
    int *ptr5 = &i2; //pointer to the address of i
    int *ptr6; //uninitialzed pointer 

    // cout << "pointer 4 address: " << ptr4 << ", value: " << *ptr4 << endl; //seg fault null ptr
    cout << "pointer 5 address: " << ptr5 << ", value: " << *ptr5 << endl;
    // cout << "pointer 6 address: " << ptr6 << ", value: " << *ptr6 << endl; //segfault
    ptr6 = ptr5;
    ptr5 = 0; //now ptr 3 is null

    // cout << "pointer 5 address: " << ptr5 << ", value: " << *ptr5 << endl; // now seg fault too
    cout << "pointer 6 address: " << ptr6 << ", value: " << *ptr6 << endl; // will be the same address as previous ptr5
    
    *ptr6 = 0; //change value for ptr6, but not the address of storage
    cout << "pointer 6 address: " << ptr6 << ", value: " << *ptr6 << endl; 


    // can use pointers in condition clauses, loops, etc
    cout << ptr5 << endl;
    if (
        ptr5
    ) {
        cout << "pointer 5 address: " << ptr5 << ", value: " << *ptr5 << endl; //will not get called since ptr5 is null
    }

    if (ptr6) cout << "pointer 6 address: " << ptr6 << ", value: " << *ptr6 << endl; //will be called since ptr6 is not null
    
    // To summarize above
    // A pointer:
    // 1. can point to an object
    // 2. can point to the location just immediately past the end of an object
    // 3. can be a null pointer, which is not bounded by any object
    // 4. can be invalid if not 1-3

    // to get the address, print the pointer ptr itself; 
    // to get the value stored, print dereferenced pointer *ptr
    
    // Comparing pointers
    double val = 10.;
    double *comparable1 = &val;
    double *comparable2 = &val;
    string isEqual = comparable1 == comparable2 ? "Equal" : "Not Equal";
    cout << isEqual << endl;

    *comparable2 = 9.; // will change value of both pointers
    isEqual = comparable1 == comparable2 ? "Equal" : "Not Equal";
    cout << isEqual << endl;
    cout << "address of two pointers: " << comparable1 << " and " << comparable2 << endl;
    cout << "value of two pointers: " << *comparable1 << " and " << *comparable2 << endl;
    
    // void* pointers
    // special case for pointers, where void pointers only holds the address to some object
    // while we don't know the  type of object stored in that memory

    double dval = 100.;
    void *voidPtr = &dval;
    cout << "address of void pointer: " << voidPtr << endl;
    // cout << "value of void pointer: " << *voidPtr << endl; //error
    int ival = 100;
    int *iPtr = &ival;
    voidPtr = iPtr; // void pointer can however hold any pointer
    cout << "address of void pointer: " << voidPtr << endl;

    voidPtr = comparable1;
    cout << "address of void pointer: " << voidPtr << endl; // will notice change to the address


    // 2.3.3 Understanding Compound type declarations
    // You can define multiple compound types in a single definition
    int i3 = 1, *p = &i3, &r = i3;
    cout << "i3: " << i3 << ", p: " << *p << ", r: " << r << endl;
    // warnings: pointers need to be declared for each one

    //Pointer to pointers
    int **ptr7 = &ptr6;
    cout << "address of ptr7: " << ptr7 << endl;
    cout << "value of ptr7: " << *ptr7 << endl;
    cout << "value of pointer held at address of ptr7's value: " << **ptr7 << endl; //lol

    //Last but not least: reference to pointers
    // references are not objects, so we cannot have pointer poiting to a reference
    // but we can have reference to a pointer
    int *&ref1 = ptr6; //for decorators read from right to left
    cout << "ref1: " << ref1 << endl; // ref1
    cout << "addres of pointer: " << ptr6 << endl;
    cout << "ref1: " << &ref1 << endl; // address of the reference ref1
    cout << "ref1: " << *ref1 << endl; // value of the pointer
} 
