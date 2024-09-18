#include <iostream>
using namespace std;
class B
{
public:
    virtual void f()
    {
        cout << "B::f" << endl;
    }
    void f(const char *a)
    {
        cout << "D::f_" << a << endl;
    }
    void g() // **** Try commenting this method ****
    {
        cout << "B::g" << endl;
    }
};
class D : public B
{
public:
    using B::f;
    void f(int a)
    {
        cout << "D::f_" << a << endl;
    }
    void g()
    {
        cout << "D::g" << endl;
    }
};
int main()
{
    B b;
    D d;
    B *p;

    d.f();
    d.f(2);
    char a[10] = "string";
    d.f(a);

    p = &b;
    p->f(); // B::f()
    p->g(); // B::g()
    p = &d;
    p->f(); // D::f()
    p->g(); // B::g() ******** Important ********
    B &r = d;
    r.f();
}
