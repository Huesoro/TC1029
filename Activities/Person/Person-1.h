//
//  Person.h
//  personTeacherInheritanceCompositionFiles
//
//  Created by Yolanda Martínez Treviño on 01/06/23.
//

#ifndef Person_h
#define Person_h
#include "Date.h"
using namespace std;
#include <iostream>


class Person {
public:
    Person();
    Person(string, Date);
    string getName() { return name; }
    void setName(string n) { name = n; }
    Date getDate() { return birthDate; }
    void setDate(Date a) { birthDate = a; }
    virtual void print();
    int calcAge();
protected:
    string name;
    Date birthDate;
};

Person::Person() {
    name = "_";
    Date tmpDate(1,1,2000);
    birthDate = tmpDate;
}

Person::Person(string nam, Date bD) {
    name = nam;
    birthDate = bD;
}

void Person::print() {
    cout << "PERSON Name: " << name << " Birth date " << birthDate.getDd() << "/" << birthDate.getMm() << "/" << birthDate.getYy() << endl;
}

int Person::calcAge() {
    return 2023- birthDate.getYy();
}

#endif /* Person_h */
