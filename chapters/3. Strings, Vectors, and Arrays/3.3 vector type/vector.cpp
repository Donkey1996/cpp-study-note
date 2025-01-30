#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using std::cout;
using std::endl;
using std::vector;
using std::map;
using std::unordered_map;
using std::string;

int main()
{
    /*
        A vector is a collection of objects, all of which have the same type. Every object in 
        the collection has an associated index, which gives access to that object. A vector
        is often referred to as a container because it “contains” other objects. 
    */

    // vector is a class template. It can be viewed as instruction to compiler
    // for generating classes.vector is a template, not a type. Types generated from vector must
    // include the element type, for example, vector<int>.

    map<string, vector<string>> vector_map; // elemetns are ordered by key

    // adding elements to vector
    vector_map["UK"] = {
        "LSE"
    }; 
    vector_map["US"] = {
        "CME",
        "NASDAQ"
    };


    for (const auto& [key, vector] : vector_map)
    {
        cout << "Exchanges in " << key << ": ";
        for (const auto& exchange : vector)
        {
            cout << exchange << " ";
        }
        cout << endl;
    }

    // 3.3.1 define and initialize vectors
    vector<string> somevec; //direct initialization, no element
    vector<int> ivec;
    vector<int> ivec2(ivec); //copy ivec into ivec2
    vector<int> ivec3 = ivec; //equivalent
    // vector<string> somevec2 = ivec; //error inconsistent type

    vector<string> somevec2 = {
        "Hello",
        "World"
    }; // list initilaizing a vector
    //equivalent to vector<string> somevec2{"HELLO", "WORLD"};

    vector<int> intVec(10); // a vector of int with length 10, default values 0

    cout << intVec.capacity() << endl;
    cout << intVec.size() << endl;

    intVec.push_back(10);
    cout << intVec.capacity() << endl; // the capacity got doubled 
    cout << intVec.size() << endl;

    vector<int> vec1(10, 1); // length 10 , values of 1
    for (auto &i : vec1)
    {
        cout << i << " ";
    }
    cout << endl;
    vector<int> vec2{10, 1}; // length 2, value of 10, 1
    for (auto &i: vec2)
    {
        cout << i << " ";
    }
    cout << endl;

    //add value to a vector

    vector<int> vector1(10, 5);
    vector1.push_back(10);
    for (auto &i : vector1)
    {
        cout << i << " ";
    }
    cout << endl;

    // 3.3.2 adding elements to a vector
    vector<int> vec3 = {1, 2, 3, 4, 5};
    cout << vec3[2] << endl; // access element at index 2
    vec3.push_back(6); // add 6 to the end of vector
    vec3.push_back(vec3[0]); // add first element to the end of vector
    for (auto &i : vec3)
    {
        cout << i << " ";
    }
    cout << endl;
    // 3.3.3 vector operations
    vector<unsigned int> grades{42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93}; 
    vector<unsigned int> grade_buckets(11, 0); // range of 0-9, 10-19,.., 90-99, 100

    // count the number of elements in each range
    for (auto grade : grades)
    {
        ++grade_buckets[grade / 10]; //increment the counter for the current cluster
    }

    // print the count for each range
    for (size_t i = 0; i < grade_buckets.size(); ++i)
    {
        cout << i * 10 << "-" << (i + 1) * 10 - 1 << ": " << grade_buckets[i] << endl;
    }

    return 0;
}