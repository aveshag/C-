#include <iostream>

using namespace std;

class Singleton
{
private:
    Singleton()
    {
        cout << "Singleton Created" << endl;
    }
    ~Singleton()
    {
        cout << "Singleton Destructed" << endl;
    }

public:
    static const Singleton &getInstance() // Returning constant reference
    {
        static Singleton mySingleton; // The Singleton -- constructed the first time
        return mySingleton;
    }

    void print() const
    {
        cout << "Hello World!" << endl;
    }
};

int main()
{
    cout << &Singleton::getInstance() << endl;
    cout << &Singleton::getInstance() << endl;
    Singleton::getInstance().print();
    Singleton::getInstance().print();
    return 0;
}