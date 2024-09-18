#include <iostream>

using namespace std;

class Complex
{
    double re, im;

public:
    // No implicit conversion is allowed
    explicit Complex(double r = 0, double i = 0) : re(r), im(i) {}

    void disp()
    {
        cout << re << " + j" << im << endl;
    }

    // Overload 1
    friend Complex operator+(const Complex &a, const Complex &b)
    {
        return Complex(a.re + b.re, a.im + b.im);
    }

    // Overload 2
    friend Complex operator+(const Complex &a, double d)
    {
        Complex b(d); // Create temporary object
        return a + b; // Use Overload 1
    }

    // Overload 3
    friend Complex operator+(double d, const Complex &b)
    {
        Complex a(d); // Create temporary object
        return a + b; // Use Overload 1
    }
};

int main()
{
    Complex d1(2.5, 3.2), d2(1.6, 3.3), d3;

    d3 = d1 + d2;
    d3.disp(); // d3 = 4.1 + j6.5. Overload 1

    d3 = d1 + 6.2;
    d3.disp(); // d3 = 8.7 + j3.2. Overload 2

    d3 = 4.2 + d2;
    d3.disp(); // d3 = 5.8 + j3.3. Overload 3
}
