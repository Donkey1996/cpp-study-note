#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::iterator;
int main()
{
    string s("hello world");
    cout << *s.begin() << " " << *s.end() << endl; //must use dereference because .begin() returns a pointer 

    // Iterator types
    vector<int>::iterator it;
    vector<int> vec = {1, 2, 3, 4, 5};
    it = vec.begin();
    cout << *it << endl; 
    
    // const iterator
    vector<int>::const_iterator cit;
    cit = vec.cbegin();
    cout << *cit << endl;
    
    // combining dereference and member access

    vector<string> names = {"Alice", "Bob", "Charlie"};
    vector<string>::const_iterator sit = names.begin();

    cout << (*sit).empty() << endl;
    cout << sit->empty() << endl; //equivalent

    vector<string> text{
        "Hello", "", "World", "!"
    };
    for (auto it = text.cbegin(); it != text.cend() && !it->empty(); ++it) 
    // use cbegin because it's the const iterator
    {
        cout << *it << " "; 
    }
    //3.4.2 Iterator arithmetric
    // iternator + n
    vector<int> numbers = {1, 2, 3, 4, 5};
    vector<int>::iterator it2 = numbers.begin();
    it2 += 2; // move to the third element
    cout << *it2 << endl;

    // iterator1 - iterator2
    vector<int>::iterator it3 = numbers.begin();
    cout << it3 - it2 << endl;
    
    auto mid = numbers.begin() + numbers.size() / 2;
    cout << numbers.size() / 2 << endl;
    cout << *mid << endl;

    //using iterator arithmetics
    // binary search
    auto beg = numbers.begin(), end = numbers.end();
    mid = beg + (end - beg) / 2;
    auto sought = 2;
    while (mid != end && *mid != sought) {
        if (sought < *mid) {
            end = mid;
        } else {
            beg = mid + 1;
        }
        mid = beg + (end - beg) / 2;
    }
    cout << (*mid == sought) << endl;


    // a modern way to do binary search
    int target = 2;
    beg = numbers.begin();
    end = numbers.end();
    bool found = std::binary_search(beg, end, target);
    if (found) {
        cout << "Found " << target << endl;
    } else {
        cout << "Not found " << target << endl;
    }

    return 0;
}