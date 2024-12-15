//
//  Teacher.h
//  personStudentTeacherFJ23
//
//  Created by Yolanda Martínez Treviño on 21/05/23.
//

#ifndef Teacher_h
#define Teacher_h

#include <iostream>
#include <string>
using namespace std;

#include "Person.h"

class Teacher : public Person {
public:
    Teacher();
    Teacher(string, int, string);
    string getDept() { return dept; }
    void setDept(string d) { dept = d; }
    void print();
private:
    string dept;
};

Teacher::Teacher() : Person() {
    dept = "-";
}

Teacher::Teacher(string nam, int ag, string dep) : Person(nam, ag) {
    dept = dep;
}


void Teacher::print() {
     cout<<"Name: "<<name<<" age: "<<age<<" dept: "<<dept << endl;
}

#endif /* Teacher_h */
