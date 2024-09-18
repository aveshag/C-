#include <iostream>
using namespace std;

class Root
{
public:
    void f(); // Non-Virtual Function
    // void f() = 0;
    virtual void g();     // Virtual Function
    virtual void h() = 0; // Pure Virtual Function
};


int main()
{
    return 0;
}