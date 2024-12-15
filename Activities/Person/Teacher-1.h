//
//  Teacher.h
//  personTeacherInheritanceCompositionFiles
//
//  Created by Yolanda Martínez Treviño on 01/06/23.
//

#ifndef Teacher_h
#define Teacher_h

#include "Person.h"
#include "Date.h"
#include <iostream>
using namespace std;

class Teacher : public Person {
public:
    Teacher();
    Teacher(string, Date, string);
    string getDept() { return dept; }
    void setDept(string d) { dept = d; }
    void print();
private:
    string dept;
};

Teacher::Teacher() : Person() {
    dept = "-";
}

Teacher::Teacher(string nam, Date bD, string dep) : Person(nam, bD) {
    dept = dep;
}


void Teacher::print() {
    cout<<"TEACHER Name: "<<name<<" Birth date " << birthDate.getDd() << "/" << birthDate.getMm() << "/" << birthDate.getYy() <<" dept: "<<dept << endl;
}
#endif /* Teacher_h */
