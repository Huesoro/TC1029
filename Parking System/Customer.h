#include "Parkingcard.h"

class CustomerParkingCard : public ParkingCard
{
    public:
    CustomerParkingCard();
    CustomerParkingCard(int, string);
    int calculateHoursToPay(Time,Time);
    void print();
};

CustomerParkingCard::CustomerParkingCard() : ParkingCard()
{
    
}

CustomerParkingCard::CustomerParkingCard(int c, string n) : ParkingCard(c,n)
{
    
}

int CustomerParkingCard::calculateHoursToPay(Time t1, Time t2)
{
    int total = t2.elapsepTime(t1);
    int hours = total / 60;
    if (total % 60 != 0)
    {
        hours++;
    }
    return hours;
}

void CustomerParkingCard::print()
{
    cout << "Customer Card -> ID: " << cardId << " ---- Owner: " << PersonName << endl;
}