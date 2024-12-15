#include <iostream>
#include "Parkingcard.h"
#include "Employee.h"
#include "Time.h"
#include "Customer.h"
#include "Suppliercard.h"
#include "ParkingRegister.h"
#include <fstream>

using namespace std;

void readFromFile(ParkingCard * cards[], int &numberOfcards){
    char type;
    int id;
    string name, sup, emp;
    ifstream inputFile;
    inputFile.open("lista.txt");
    while(inputFile >> type){
        inputFile >> id >> name;
        if(type == 'S'){
            inputFile >> sup;
            SupplierParkingCard * supplier = new SupplierParkingCard(id, name, sup);
            cards[numberOfcards] = supplier;
        }
        else if(type == 'E'){
            inputFile >> emp;
            EmployeeParkingCard * employee = new EmployeeParkingCard(id, name, emp);
            cards[numberOfcards] = employee;
        }
        else{
            cards[numberOfcards] = new CustomerParkingCard(id, name);
        }
        numberOfcards++;
    }
    inputFile.close();
}

int main() {

    ParkingCard * cards[50];
    int numberOfcards, iD, hour, minute;  // number of cards in cardList
    char cardType, menuOption;
    string name, company, supplierName;
    double feeRate;
    ParkingRegister *register1[50];
    Time time;
    bool found = false;
    double y;
    


    readFromFile(cards, numberOfcards);
    cout << "Enter fee rate: " << endl;
    cin >> feeRate;

    for (int i = 0; i < numberOfcards; i++)
    {
    cards[i]->print();
    };

    //for (int i = 0; i < numberOfcards; i++)
    {
        //register1[i] = new ParkingRegister(cards[i]->getCardId(),Time(12,30));
        //Time t1(24,4);
        //register1[0]->setEntryTime(t1);
        //register1[i]->print();
    }   

    //register1[0]->print();


    for (int i = 0; i<numberOfcards; i++)
    {
        cards[i]->print();
        register1[i]->getEntryTime().print();
        cout << endl;
    }
    Time t3(15,4), t4(18,30);
    
    cout << cards[2]->calculatePayment(t3,t4,feeRate) << endl;
    return 0;
}
