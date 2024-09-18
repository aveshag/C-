#include<iostream>

using namespace std;

class Complex {
    int re, img;
    public:
    // Initializer list
    Complex(int a = 0.0, int b = 0.0): re(a), img(b) {
    }

    void print() {
        cout<<re<<"+"<<img<<"i"<<endl;
    }
};

int main() {
    Complex c(1, 2);
    Complex c2(c);
    c.print();
    c2.print();
}