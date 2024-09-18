#include <iostream>

using namespace std;

class Print
{
private:
    static int x; // Declaration

public:
    int get()
    {
        return x;
    }

    void set()
    {
        x += 10;
    }
};

int Print::x; // Definition/Intialization

int main()
{
    Print p1, p2;
    cout << p1.get() << endl;
    cout << p2.get() << endl;
    p1.set();
    cout << p1.get() << endl;
    p2.set();
    cout << p2.get() << endl;

    return 0;
}