#include <iostream>
#include "data_structures.hpp"
/*
    enums/structs/classes
    - Enums are great for representing a fixed set of values, like states, directions, or modes.
    - Structs are suitable for simple objects that primarily encapsulate data without requiring heavy encapsulation or inheritance.
    - Classes are ideal for representing complex entities with encapsulated data and behavior. They are used extensively in OOP for abstraction, inheritance, and polymorphism.
*/

int main()
{
    using sd = Sales_data*; //use alias for Sales_data struct
    sd newSales = &trans; //pointer to the trans object we defined above


    std::cout << newSales->bookNumber << std::endl;
    std::cout << newSales->units_sold << std::endl;

    sd data1 = new Sales_data; //make a new pointer to the Sales_data object

    double price = 0.0;
    std::cin >> data1->bookNumber >> data1->units_sold >> price;
    data1->revenue = data1->units_sold * price;

    std::cout << "Book number " << data1->bookNumber << "sold " << data1->units_sold << " units. Revenue: " << data1->revenue << std::endl;

    return 0;
}