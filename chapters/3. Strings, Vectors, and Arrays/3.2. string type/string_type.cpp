#include <string>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::isspace;
using std::isalpha;


int main() {

    /* 
        initialization of std::string type
    */
    string s1 = "hello world"; //direct initialization
    cout << s1 << endl;

    string *s2 = new string(); //initializing pointer to string
    *s2 = string(10, 'c');
    cout << *s2 << endl;
    
    string s3(10, 'b'); //direct initialization
    cout << s3 << endl;
    

    string s4(s3); // copy of s3
    cout << s4 << endl;

    /*
        Operations on string
    */
    //reads a line of input from is into s
    string s5;
    getline(cin, s5);
    cout << "Input string: " << s5 << endl;
    
    string line;
    while (getline(cin, line)) 
    {
        if (!line.empty() or line.size() != 0){
            cout << line << endl;
        }
        else
        {
            break;
        }
    }   

    // check if string is empty
    cout << s1.empty() << endl;

    // check number of character in string
    cout << s1.size() << endl;

    //reference to char at position n
    cout << s1[0] << endl;

    //concatination of two strings
    cout << s1 + *s2 << endl;

    // equivalent operator
    cout << (s3 == s4) << endl;

    //comparison of string
    cout << (s1 < s3) << endl;

    // string::size_type or auto
    string::size_type size1 = s1.size();
    cout << size1 << endl;
    
    // access each character in a string
    for (int i = 0; i <= s1.size(); i++)
    {
        cout << s1[i];
    }
    cout << endl;
    for (auto c : s1)
    {
        cout << c;
    }
    cout << endl;

    //check if char is a punctuation
    cout << "Is punctuation? " << std::ispunct(s1[0]) << endl;
    cout << std::ispunct(char('!')) << endl;

    //check digit
    cout << "Is digit? " << std::isdigit(s1[0]) << endl;

    //check letter
    cout << "Is letter? " << std::isalpha(s1[0]) << endl;

    // check control character
    cout << "Is control character? " << std::iscntrl(s1[0]) << endl;

    // check is lower 
    cout << "Is lower case? " << std::islower(s1[0]) << endl;

    // check is upper case
    cout << "Is upper case? " << std::isupper(s1[0]) << endl;

    // convert to lower case
    cout << std::tolower(s1[0]) << endl;

    // convert to upper case
    cout << std::toupper(s1[0]) << endl;

    // remove leading and trailing whitespace
    cout << "Trimmed string: " << s1.erase(0, s1.find_first_not_of(" \t\r\n")) << s1.erase(s1.find_last_not_of(" \t\r\n") + 1) << endl;

    // replace a character
    s1.replace(0, 1, "H");
    cout << "Replaced string: " << s1 << endl;

    for (auto &c : s1)
    {
        c = toupper(c);
    }
    cout << s1 << endl;

    // processing only some characters
    // can use [] subscript operator
    s1[0] = 'c';
    cout << s1[0] << endl;

    string s("some string");
    for (int i = 0; i != s.size() && !isspace(s[i]); ++i) //could use decltype(s.size()) i;
    {
        cout << "Index: " << i << s[i] << endl;
        s[i] = toupper(s[i]);
    }
    cout << s << endl;

    // using subscript for random access

    const string hexdigits = "0123456789ABCDEF"; // possible hex digits
    cout << "Enter a series of numbers between 0 and 15"
         << " separated by spaces. Hit ENTER when finished: "
         << endl;
    string result; // will hold the resulting hexify’d string
    string::size_type n; // hold numbers from the input
    string line;

    while (cin >> n)
        if (n < hexdigits.size()) // ignore invalid input
        result += hexdigits[n]; // fetch the indicated hex digit
    cout << "Your hex number is: " << result << endl;

    return 0;
}