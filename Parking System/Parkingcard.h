#ifndef Person_h
#define Person_h
using namespace std;
#include <iostream>
#include "Time.h"

class ParkingCard
{
    public:
    ParkingCard();
    ParkingCard(int,string);
    int getCardId() {return cardId;}
    string getPersonName() {return PersonName;}
    void setCardId(int c) {cardId = c;}
    void setPersonName(string n) {PersonName = n;}
    double calculatePayment(Time,Time,double);
    virtual int calculateHoursToPay(Time,Time) = 0;
    virtual void print() = 0;
    
    protected:
    int cardId;
    string PersonName;
};

ParkingCard::ParkingCard()
{
    cardId = 0;
    PersonName = "_";
}

ParkingCard::ParkingCard(int c, string n)
{
    cardId = c;
    PersonName = n;
}

double ParkingCard::calculatePayment(Time t1, Time t2, double rate)
{
    return calculateHoursToPay(t1,t2) * rate;

}

#endif