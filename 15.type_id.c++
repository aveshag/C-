#include <iostream>
#include <typeinfo>
using namespace std;

// Polymorphic Hierarchy
class A
{
public:
    virtual ~A() {}
};
class B : public A
{
};

// Non-Polymorphic Hierarchy
class X
{
};
class Y : public X
{
};

int main()
{
    A a;
    cout << typeid(a).name() << ": " << typeid(&a).name() << endl; // Static
    A *p = &a;
    cout << typeid(p).name() << ": " << typeid(*p).name() << endl; // Dynamic
    B b;
    cout << typeid(b).name() << ": " << typeid(&b).name() << endl; // Static
    p = &b;
    cout << typeid(p).name() << ": " << typeid(*p).name() << endl; // Dynamic
    A &r1 = a;
    A &r2 = b;
    cout << typeid(r1).name() << ": " << typeid(r2).name() << endl; // Dynamic

    Y y;
    X *q = &y;
    cout << typeid(q).name() << ": " << typeid(*q).name() << endl; // Dynamic -- FAILS
}

// MSVC++
// class A: class A *
// class A *: class A
// class B: class B *
// class A *: class B
// class A: class B
// class X *: class X

// Onlinegdb
// 1A: P1A
// P1A: 1A
// 1B: P1B
// P1A: 1B
// 1A: 1B
// P1X: 1X
