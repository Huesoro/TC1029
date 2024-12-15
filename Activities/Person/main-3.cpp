//
//  main.cpp
//  personTeacherInheritanceCompositionFiles
//
//  Created by Yolanda Martínez Treviño on 01/06/23.
//

#include <iostream>
using namespace std;

#include "Teacher.h"
#include "Person.h"
#include "Date.h"
#include <fstream>
void readFromFile(string inputFile,Person *personsList[], int &numberOfPersons){
    char type;
    int dd, mm,yy;
    string name, dept;
    ifstream inputFile;
    inputFile.open("persons.txt");
    while(inputFile >> type){
        inputFile >> name >> dd >> mm >> yy;
        if(type == 'T'){
            inputFile >> dept;
            Teacher *teach = new Teacher(name, Date(dd,mm,yy), dept);
            personsList[numberOfPersons] = teach;
        }
        else{
            personsList[numberOfPersons] = new Person(name, Date(dd,mm,yy));
        }
        numberOfPersons++;
    }

}
int main() {
    
    Person *personsList[20];
    int numberOfPersons;  // number of persons in personsList
    char personChoice, menuOption;
    int dd, mm, yy, age;
    string name, depart;
    
    cout << "Number of persons? ";
    cin >> numberOfPersons;
    
    for (int c = 0; c < numberOfPersons; c++) {
        cout << "Is the person a teacher? (y/n)" << endl;
        cin >> personChoice;
        cout << "Name? ";
        cin >> name;
        cout << "Age? ";
        cin >> age;
        if (personChoice == 'y') {
            cout << "Department? ";
            cin >> depart;
            Teacher *teach = new Teacher(name, Date, depart);
            personsList[c] = teach;
            }
        else {
            personsList[c] = new Person(name, Date);
        }
    }
    
    do
    {
        cout << "Options " << endl;
        cout << endl;
        cout << "a) display all the persons " << endl;
        cout << "b) display the persons of certain age " << endl;
        cout << "c) finish " << endl;
        cout << "option -> " << endl;
        cin >> menuOption;
        
        switch (menuOption) {
            case 'a':  {
                for (int c = 0; c < numberOfPersons; c++)
                    personsList[c]->print();
                break;
            }
                
            case 'b':  {
                int tmpAge;
                cout << "initial age of the range? ";
                cin >> initialAge;
                cout << "end age of the range? ";
                cin >> endAge;
                for (int c = 0; c < numberOfPersons; c++) {
                    tmpAge = personsList[c]->getAge();
                    if (tmpAge >= initialAge && tmpAge <= endAge)
                        personsList[c]->print();
                }
                break;
            }
        }
        
    } while (menuOption != 'c');  // finish
    
    return 0;
}
