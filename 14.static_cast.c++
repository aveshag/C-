#include <iostream>

using namespace std;

// Un-related Types
class B;
class A
{
public:
    A(int i = 0) { cout << "A::A(i)\n"; }
    A(const B &) { cout << "A::A(B&)\n"; } // Single-argument constructor
};
class B
{
};

// Un-related Types
class D;
class C
{
    int i_;

public:
    C(int i = 0) : i_(i) { cout << "C::C(i)\n"; }
    operator int() // To convert C to int, as we can't add constructor in int class
    {
        cout << "C::operator int()\n";
        return i_;
    }
};
class D
{
public:
    operator C() // Conversion operator
    {
        cout << "D::operator C()\n";
        return C();
    }
};

int main()
{
    A a;
    B b;
    int i = 5;

    // B ==> A
    a = b;                 // Uses A::A(B&)
    a = static_cast<A>(b); // Uses A::A(B&)
    a = (A)b;              // Uses A::A(B&)

    // int ==> A
    a = i;                 // Uses A::A(int)
    a = static_cast<A>(i); // Uses A::A(int)
    a = (A)i;              // Uses A::A(int)

    C c;
    D d;
    int j = 5;
    // D ==> C
    c = d;                 // D::operator C()
    c = static_cast<C>(d); // D::operator C()
    c = (C)d;              // D::operator C()

    // C ==> int
    j = c;                   // C::operator int()
    j = static_cast<int>(c); // C::operator int()
    j = (int)c;              // C::operator int()
}