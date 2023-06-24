#include <iostream>
#include <memory>
using namespace std;

class PersonException : public exception {
public:
    const char* what() const noexcept override {
        return "PersonException: Invalid data for person";
    }
};

class Person {
private:
    string name;
    int age;
    int id;
public:
    Person(string name, int age, int id) : name(name), age(age), id(id) {
        if (name.empty() || age < 0 || id < 0) {
            throw PersonException();
        }
    }
    void printInfo() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    try {
        string name;
        int age, id;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;
        cout << "Enter ID: ";
        cin >> id;
        unique_ptr<Person> person(new Person(name, age, id));
        person->printInfo();
    }
    catch (PersonException& e) {
        cerr << e.what() << endl;
    }
    catch (exception& e) {
        cerr << e.what() << endl;
    }
    return 0;
}