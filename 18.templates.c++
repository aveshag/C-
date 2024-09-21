#include <iostream>
// #include <cstring>

using namespace std;

// template <typename T>
template <class T>
T Max(T x, T y)
{
    return x > y ? x : y;
}

template <> // Template specialization for ’char *’ type 
char *Max<char *>(char *x, char *y)
{
    return strcmp(x, y) > 0 ? x : y;
}

template <class T, int size> // Overloaded template function
T Max(T x[size])
{
    T t = x[0];
    for (int i = 0; i < size; ++i)
    {
        if (x[i] > t)
            t = x[i];
    }
    return t;
}

// Multiplication
template <class T>
int product(T p)
{
    T::count++;
    return T::count * p.sum();
}

// use of typename to distinguish Type and Multiplication
template <class T>
T pointer()
{
    typename T::name *p;
}

template <class T1 = int, class T2 = string> // Template with default parameters
class Student
{
};

template <class T1> // Partial Template Specialization
class Student<T1, char *>
{
};

class Complex
{
    double re_;
    double im_;

public:
    static int count;

    Complex(double re = 0.0, double im = 0.0) : re_(re), im_(im) {};
    double norm() const { return sqrt(re_ * re_ + im_ * im_); }
    int sum() { return re_ + im_; }
    // When Max is instantiated with class Complex, we need comparison operator for Complex
    friend bool operator>(const Complex &c1, const Complex &c2) { return c1.norm() > c2.norm(); }
    friend ostream &operator<<(ostream &os, const Complex &c)
    {
        os << "(" << c.re_ << ", " << c.im_ << ")";
        return os;
    }
};

int Complex::count = 1;

int main()
{
    char *s1 = new char[6], *s2 = new char[6];
    strcpy(s1, "black");
    strcpy(s2, "white");

    cout << "Max(" << s1 << ", " << s2 << ") = " << Max<char *>(s1, s2) << endl;
    // Output: Max(black, white) = white

    strcpy(s1, "white");
    strcpy(s2, "black");

    cout << "Max(" << s1 << ", " << s2 << ") = " << Max<char *>(s1, s2) << endl;
    // Output: Max(black, white) = white

    Complex c1(2.1, 3.2), c2(6.2, 7.2);
    cout << "Max(" << c1 << ", " << c2 << ") = " << Max(c1, c2) << endl;
    // Output: Max((2.1, 3.2), (6.2, 7.2)) = (6.2, 7.2)

    int arr[] = {2, 5, 6, 3, 7, 9, 4};
    cout << "Max(arr) = " << Max<int, 7>(arr) << endl; // Output: Max(arr) = 9

    Complex c3(1, 2);
    cout << "Product(" << c3 << ")" << " = " << product(c3) << endl;
}