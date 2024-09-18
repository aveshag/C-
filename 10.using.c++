#include <iostream>

using namespace std;

class B
{
public: // Base Class
    void f()
    {
        cout << "B::f" << endl;
    }

    void f(int i)
    {
        cout << "B::f_int" << endl;
    }

    void g(int i)
    {
        cout << "B::g" << endl;
    }
};
class D : public B
{
public: // Derived Class
    // Inherits B::f(int)

    void f(int i) // Overrides B::f(int)
    {
        cout << "D::f_int" << endl;
    }
    // To overload, rather than hide the base class function f(int),
    // it is introduced into the scope of B with a using declaration

    using B::f; // **** Experiment with commenting this line ****

    void f(const char *x) // Overloads B::f(int)
    {
        cout << "D::f_str" << endl;
    }

    // Inherits B::g(int)

    void h(int i) // Adds D::h(int)
    {
        cout << "D::h" << endl;
    }
};

int main()
{
    B b;
    D d;
    b.f();  // Calls B::f()
    b.f(1); // Calls B::f(int)
    b.g(2); // Calls B::g(int)
    d.f();
    d.f(3);     // Calls D::f(int) if uncomment line 28 to 33
    d.g(4);     // Calls B::g(int)
    d.f("red"); // Calls D::f(string&)
    d.h(5);     // Calls D::h(int)
}