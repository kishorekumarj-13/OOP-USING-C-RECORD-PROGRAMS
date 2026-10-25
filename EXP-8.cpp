
#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

/**
 * @brief Observer interface.
 */
class Observer
{
public:
    virtual void notify(const string& message) = 0;

    virtual ~Observer() {}
};

/**
 * @brief Email notification observer.
 */
class EmailNotification : public Observer
{
private:
    string email;

public:
    EmailNotification(string e)
    {
        email = e;
    }

    void notify(const string& message) override
    {
        cout << "Email sent to " << email
             << ": " << message << endl;
    }
};

/**
 * @brief SMS notification observer.
 */
class SMSNotification : public Observer
{
private:
    string phone;

public:
    SMSNotification(string p)
    {
        phone = p;
    }

    void notify(const string& message) override
    {
        cout << "SMS sent to " << phone
             << ": " << message << endl;
    }
};

/**
 * @brief Factory class for creating notifications.
 */
class NotificationFactory
{
public:
    static shared_ptr<Observer> createNotification(
        const string& type,
        const string& receiver)
    {
        if (type == "EMAIL")
        {
            return make_shared<EmailNotification>(receiver);
        }
        else if (type == "SMS")
        {
            return make_shared<SMSNotification>(receiver);
        }

        return nullptr;
    }
};

/**
 * @brief Singleton Event Manager.
 */
class EventManager
{
private:
    vector<shared_ptr<Observer>> observers;

    // Private constructor prevents external object creation
    EventManager()
    {
    }

public:
    // Prevent copying
    EventManager(const EventManager&) = delete;

    EventManager& operator=(const EventManager&) = delete;

    // Singleton access method
    static EventManager& getInstance()
    {
        static EventManager instance;
        return instance;
    }

    // Subscribe an observer
    void subscribe(shared_ptr<Observer> observer)
    {
        if (observer != nullptr)
        {
            observers.push_back(observer);
        }
    }

    // Trigger an event
    void triggerEvent(const string& message)
    {
        cout << "\nEvent Triggered: "
             << message << endl;

        cout << "Sending Notifications..." << endl;

        for (auto observer : observers)
        {
            observer->notify(message);
        }
    }
};

int main()
{
    // Access Singleton EventManager
    EventManager& manager = EventManager::getInstance();

    // Create observers using Factory Pattern
    shared_ptr<Observer> emailUser =
        NotificationFactory::createNotification(
            "EMAIL",
            "Kishore.Estudent@gmail.com");

    shared_ptr<Observer> smsUser =
        NotificationFactory::createNotification(
            "SMS",
            "9876593270");

    // Subscribe observers
    manager.subscribe(emailUser);
    manager.subscribe(smsUser);

    // Trigger event
    manager.triggerEvent(
        "University examination starts tomorrow!");

    return 0;
}
