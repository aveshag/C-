#include <iostream>

using namespace std;

class Base
{
    int basePrivateData;
    static int baseStaticPrivateData;

    void basePrivateMethod()
    {
        cout << "Private base method" << endl;
    }

public:
    int basePublicData;
    static int baseStaticPublicData;

    Base(int a, int b) : basePrivateData(a), basePublicData(b)
    {
        cout << "basePrivateData: " << basePrivateData << endl;
        cout << "basePublicData: " << basePublicData << endl;
    }

    void basePublicMethod()
    {
        cout << "Public base method" << endl;
    }

    static void baseStaticMethod()
    {
        cout << "Public static method" << endl;
        cout << "baseStaticPrivateData: " << baseStaticPrivateData << endl;
        cout << "baseStaticPublicData: " << baseStaticPublicData << endl;
        baseStaticPrivateData++;
        baseStaticPublicData++;
    }
};

int Base::baseStaticPrivateData = 1;
int Base::baseStaticPublicData = 2;

class Derived : public Base
{
public:
    static int baseStaticPrivateData;
    Derived(int a, int b) : Base(a, b)
    {
    }
    static void derivedStaticMethod()
    {
        cout << "Public static method" << endl;
        cout << "baseStaticPrivateData: " << baseStaticPrivateData << endl;
        cout << "baseStaticPublicData: " << baseStaticPublicData << endl;
        baseStaticPrivateData++;
        baseStaticPublicData++;
    }
};

int Derived::baseStaticPrivateData = 50;

int main()
{
    Base b1(1, 2), b2(3, 4);
    // b1.basePrivateMethod();
    b1.basePublicMethod();
    b1.baseStaticMethod();
    Base::baseStaticMethod();
    b2.baseStaticMethod();

    cout << endl;

    Derived d1(8, 9);
    d1.baseStaticPublicData++;
    d1.basePublicMethod();
    d1.baseStaticMethod();
    Derived::baseStaticMethod();
    d1.derivedStaticMethod();
}