//
//  Person..h
//  personStudentTeacherFJ23
//
//  Created by Yolanda Martínez Treviño on 21/05/23.
//

#ifndef Person__h
#define Person__h

#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    Person();
    Person(string, int);
    string getName() { return name; }
    void setName(string n) { name = n; }
    int getAge() { return age; }
    void setAge(int a) { age = a; }
    void print();
private:
    string name;
    int age;
};

Person::Person() {
    name = "_";
    age = 0;
}

Person::Person(string nam, int ag) {
    name = nam;
    age = ag;
}

void Person::print() {
    cout << "Name: " << name << " age " << age << endl;
}

#endif /* Person__h */
