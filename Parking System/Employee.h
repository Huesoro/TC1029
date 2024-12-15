#include "Parkingcard.h"

class EmployeeParkingCard : public ParkingCard
{
    public:
    EmployeeParkingCard();
    EmployeeParkingCard(int, string, string);
    string getStoreName() {return storeName;}
    void setStoreName(string s) {storeName = s;}
    int calculateHoursToPay(Time,Time);
    void print();

    private:
    string storeName;
};

EmployeeParkingCard::EmployeeParkingCard() : ParkingCard()
{
    storeName = "_";
}

EmployeeParkingCard::EmployeeParkingCard(int c, string n, string s) : ParkingCard(c,n)
{
    storeName = s;
}

int EmployeeParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    int hours = 0;
    return hours;
}

void EmployeeParkingCard::print()
{
    cout << "Employee card -> ID: " << cardId << " ---- Owner: " << PersonName << " ---- Store Name: " << storeName << endl;
}

