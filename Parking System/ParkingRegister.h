#include "Time.h"

class ParkingRegister{
    public:
    ParkingRegister();
    ParkingRegister(int,Time);
    int getCardId() {return Id;}
    Time getEntryTime() {return entryTime;}
    void setCardId(int c) {Id = c;}
    void setEntryTime(Time t) {entryTime = t;}
    void print();

    private:
    int Id;
    Time entryTime;

};

ParkingRegister::ParkingRegister()
{
    Id = 0;
    entryTime = Time();
}

ParkingRegister::ParkingRegister(int c, Time t)
{
    Id = c;
    entryTime = t;
}

void ParkingRegister::print()
{
    cout << "Card ID: " << Id << " --- Entry Time: ";
    entryTime.print();
}

