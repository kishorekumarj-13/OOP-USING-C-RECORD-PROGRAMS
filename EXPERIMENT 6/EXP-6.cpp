
#include <iostream>
#include <memory>
using namespace std;

// Resource class
class Resource
{
public:
    Resource()
    {
        cout << "Resource acquired" << endl;
    }

    ~Resource()
    {
        cout << "Resource released" << endl;
    }

    void use()
    {
        cout << "Resource is being used" << endl;
    }
};

// Manual Smart Pointer using RAII
class MySmartPointer
{
private:
    Resource* ptr;

public:
    MySmartPointer(Resource* p)
    {
        ptr = p;
    }

    ~MySmartPointer()
    {
        delete ptr;
    }

    Resource* operator->()
    {
        return ptr;
    }
};

int main()
{
    cout << "Manual Smart Pointer:" << endl;

    {
        MySmartPointer myPtr(new Resource());
        myPtr->use();
    }

    cout << "\nShared Smart Pointer:" << endl;

    {
        shared_ptr<Resource> sharedPtr1 =
            make_shared<Resource>();

        shared_ptr<Resource> sharedPtr2 = sharedPtr1;

        sharedPtr1->use();

        cout << "Shared Pointer Count: "
             << sharedPtr1.use_count() << endl;
    }

    cout << "\nProgram completed successfully." << endl;

    return 0;
}
