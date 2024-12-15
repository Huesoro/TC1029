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
        if(numberOfcards >= 49){
            cout << "La lista esta llena" << endl;
            break;
        }
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
    numberOfcards = 0;
    


    readFromFile(cards, numberOfcards);
    for(int i = 0; i < numberOfcards; i++)
    {
        register1[i] = new ParkingRegister(0,Time(0,0));
    }

    
    cout << "Enter fee rate: " << endl;
    cin >> feeRate;


    do
    {
        cout << "Enter option: " << endl;
        cout << endl;
        cout << "a) Register Entrance" << endl;
        cout << "b) Register Exit" << endl;
        cout << "c) Display Parking Register" << endl;
        cout << "d) Display parking cards list" << endl;
        cout << "e) Exit" << endl;
        cin >> menuOption;
        switch (menuOption)
        {
            case 'a': {
                while (found != true)
                {
                    cout << "Enter card ID: " << endl;
                    cin >> iD;
                    for (int i = 0; i < numberOfcards; i++)
                        {
                            if (cards[i]->getCardId() == iD)
                            {
                                while (found != true)
                                {
                                    cout << "Enter hour" << endl;
                                    cin >> hour;
                                    cout << "Enter minute" << endl;
                                    cin >> minute;
                                    if(hour < 22 & hour > 8 & minute < 60 & minute >= 0)
                                    {
                                    time.setHour(hour);
                                    time.setMinute(minute);
                                    register1[i]->setEntryTime(time);
                                    register1[i]->setCardId(iD);
                                    found = true;
                                    break;
                                    }
                                    else
                                    {
                                        cout << "Invalid time" << endl;
                                    }
                                }

                            }

                        }
                }
                found = false;
                break;
                

            }
            case 'b': {
                cout << "Enter card ID: " << endl;
                cin >> iD;
                found = false;
                for(int i = 0; i< numberOfcards; i++)
                {
                    if(register1[i]->getCardId() == iD)
                    {
                        found = true;
                        cout << "Enter hour at leaving" << endl;
                        cin >> hour;
                        cout << "Enter minute at leaving" << endl;
                        cin >> minute;
                        time.setHour(hour);
                        time.setMinute(minute);
                        Time entrytime = register1[i]->getEntryTime();
                        if(hour < 22 & hour > 8 & minute < 60 & minute >= 0 & time > entrytime)
                        {

                            cout << "El carro entro a las: ";
                            entrytime.print();
                            cout << "El carro salio a las: ";
                            time.print();
                            cout << "El carro estuvo estacionado por: ";
                            int h = cards[i]->calculateHoursToPay(entrytime,time);
                            cout << h << " horas" << endl;
                            cout << "El costo es: " << cards[i]->calculatePayment(entrytime,time,feeRate) << endl;
                            break;
            
                        }
                        else
                        {
                            cout << "Invalid time" << endl;
                        }
                    }


                }
                if(found != true)
                    {
                        cout << "Card not found" << endl;
                    }
                break;

            }
            case 'c': {
                for (int i = 0; i < numberOfcards; i++)
                {
                    if(register1[i]->getCardId() != 0){
                    cards[i]->print();
                    register1[i]->getEntryTime().print();

                    }

                }
                break;

            }
            case 'd': {
                    for (int i = 0; i < numberOfcards; i++)
                        {
                            cards[i]->print();
                        };
                break;

            }
            break;
        }
    } while (menuOption != 'e');
    return 0;

    


}