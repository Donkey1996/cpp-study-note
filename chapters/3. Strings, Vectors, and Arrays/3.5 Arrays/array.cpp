#include <array>
#include <iostream>
#include <string>
#include <vector>

using std::array;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  array<int, 5> arr = {1, 2, 3, 4, 5};

  // array size must be known at compile time. size has to be constexpr
  unsigned int array_size = 2;
  int arr1[2];
  int arr2[array_size];
  string arr3[array_size];

  for (auto i : arr1) {
    cout << i << endl;
  }
  // for (auto i: arr2){
  //     cout << i << endl;
  // }
  // for (auto i: arr3){
  //     cout << i << endl;
  // }

  // pointers
  string numbers[] = {
      "one",
      "two",
      "three",
  };
  string *p1 = &numbers[0]; // p1 points to the first element
  int *p2 = &arr[2];        // p2 points to third element of the the arr
  auto p3(numbers);         // p3 is a int* pointer to the first element of arr

  cout << *p1 << endl;
  cout << *p2 << endl;
  cout << typeid(p3).name() << endl;
  cout << *p3 << endl;

  p3 += 1;
  cout << *p3 << endl; // pointer to array element is an iterator

  // p3 += 2;
  // cout << *p3 << endl; //off-the-end

  // can use std::begin() to reference the start of the array
  cout << *std::begin(numbers) << endl;

  // pointer arithmetic
  // adding integer x to a pointer gives another pointer x elements behind
  string *ip = numbers;
  // string *ip2 = ip + 10; //error because number only has three elements
  // cout << *ip2 << endl;

  string *ip2 = ip + 2;
  cout << typeid(ip2 - ip).name() << endl; // an long integer

  // interaction between dereference and pointer
  int ia[] = {0, 2, 3, 4, 5};
  int *lastAddress = ia + 4; // this give a pointer to the last
  // The expression *(ia + 4) calculates the address four elements past ia and
  // dereferences the resulting pointer.
  //  This expression is equivalent to writing ia[4]
  cout << *lastAddress << endl;
  int lastValue = *(ia + 4);
  cout << lastValue << endl; // this gives the value of the last

  int *p4 = &ia[2];
  int p5 = p4[1]; // this is equivalend to *(p4 + 1)

  cout << *p4 << endl;
  cout << p5 << endl;

  cout << ia[0] << endl;

  return 0;
}