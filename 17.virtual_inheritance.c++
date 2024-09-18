#include <iostream>

using namespace std;

// Introduce a default constructor for root base class Person
// Prefix every inheritance of Person with virtual
// Only one instance of base class object (Person) in a TA object!

class Person
{ // data members of person
public:
    Person(int x) { cout << "Person::Person(int)" << endl; }
    Person() { cout << "Person::Person()" << endl; } // Default ctor for virtual inheritance
    void display()
    {
        cout << "Base" << endl;
    }
};

class Faculty : virtual public Person
{ // data members of Faculty
public:
    Faculty(int x) : Person(x) { cout << "Faculty::Faculty(int)" << endl; }
};

class Student : virtual public Person
{ // data members of Student
public:
    Student(int x) : Person(x) { cout << "Student::Student(int)" << endl; }
};

class TA : public Faculty, public Student
{
public:
    TA(int x) : Student(x), Faculty(x), Person(x) { cout << "TA::TA(int)" << endl; }
};

int main()
{
    TA ta(30);
    ta.display();
}