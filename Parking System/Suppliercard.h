#include <iostream>
using namespace std;
#include "Parkingcard.h"
#include "Time.h"

class SupplierParkingCard : public ParkingCard
{
    public:
    SupplierParkingCard();
    SupplierParkingCard(int,string, string);
    string getCompany() {return company;}
    void setCompany(string c) {company = c;}
    int calculateHoursToPay(Time,Time);
    void print();
    
    private:
    string company;
};

SupplierParkingCard::SupplierParkingCard() : ParkingCard()
{
    company = "_";
}

SupplierParkingCard::SupplierParkingCard(int c, string n, string co) : ParkingCard(c,n)
{
    company = co;
}

int SupplierParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    int total = t2.elapsepTime(t1);
    int hours = total / 60;
    if (total % 60 != 0)
    {
        hours++;
    }
    hours --;
    return hours;
}

void SupplierParkingCard::print()
{
    cout <<"Supplier card -> ID: " << cardId << " ---- Owner: " << PersonName << " ---- Company: " << company << endl;
}
