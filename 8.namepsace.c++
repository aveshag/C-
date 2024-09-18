// using or using namespace hides some of the names

#include <iostream>

using namespace std;

int data = 0; // Global Data

namespace name1
{
    int data = 1; // Namespace Data
}

int main()
{
    using name1::data;
    // int data = 2; // error: declaration conflicts with target of using declaration already in scope
    cout << data << endl;        // 1 // name1::data -- Hides global data
    cout << name1::data << endl; // 1
    cout << ::data << endl;      // 0 // ::data -- global data
}
