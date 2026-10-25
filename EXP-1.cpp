
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    int rollNo;
    string name;

public:
    // Constructor
    Student(int r, string n)
    {
        rollNo = r;
        name = n;

        cout << "Student object created" << endl;
    }

    // Display student details
    void display()
    {
        cout << "Roll Number: " << rollNo << endl;
        cout << "Name: " << name << endl;
    }
};

int main()
{
    Student s2(791, "Arun");

    s2.display();

    return 0;
}
