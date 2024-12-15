#include <iostream>
using namespace std;

#include "Teacher.h"

int main() {
    string name, dept;
    int age;
    char answer;
    
    // variable that holds the number of persons in the array of pointers to Person
    int sizeListPersons;
    
    // add information to the array of pointers
    cout << "How many persons are you going to add? ";
    cin >> sizeListPersons;
    
    // Creates the array of the size needed.
    // Be careful, this will only work if the variable sizeListPersons already has a value
    Person *ptrListPersons[sizeListPersons];
    
    for (int counter = 0; counter < sizeListPersons; counter++) {
        cout << "Type the name ";
        cin >> name;
        cout << "Type the age ";
        cin >> age;
        
        cout << "Is the person a teacher? (y/n) ";
        cin >> answer;
        if (answer == 'n') {
            // TODO: Creates an object Person and put it on the array
            
        }
        else {
            cout << "Type the department ";
            cin >> dept;
            // TODO: Creates an object Teacher and put it on the array
            
        }
    }
    
    // TODO: display the information in the array of pointers

    
    // TODO: check if a person is in the list
    cout << "Type the name of the person you want to look for ";
    cin >> name;
   
    
    
    return 0;
}
