#include <iostream>

using namespace std;

class Singleton
{
private:
    static Singleton *instance;
    Singleton()
    {
        cout << "Singleton Created" << endl;
    }

public:
    ~Singleton()
    {
        cout << "Singleton Destructed" << endl;
    }

    static const Singleton &getInstance() // Returning constant reference
    {
        if (!instance)
        {
            instance = new Singleton();
        }
        return *instance;
    }

    void print() const
    {
        cout << "Hello World!" << endl;
    }
};

Singleton *Singleton::instance = nullptr;

int main()
{
    cout << &Singleton::getInstance() << endl;
    cout << &Singleton::getInstance() << endl;
    Singleton::getInstance().print();
    Singleton::getInstance().print();
    delete &Singleton::getInstance();
    return 0;
}