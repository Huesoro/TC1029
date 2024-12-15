
using namespace std;
#include <iostream>

#ifndef Time_h
#define Time_h

class Time{
    public:
    Time();
    Time(int,int);
    int getHour() {return hour;}
    int getMinute() {return minute;}
    void setHour(int h) {hour = h;}
    void setMinute(int m) {minute = m;}
    int elapsepTime(Time);
    bool operator>(Time);
    void print();
    
    private:
    int hour;
    int minute;
};

Time::Time()
{
    hour = 0;
    minute = 0;
}

Time::Time(int h, int m)
{
    hour = h;
    minute = m;
}

int Time::elapsepTime(Time t)
{
    int total = 0;
    hour = hour - t.hour;
    minute = minute - t.minute;
    total = hour * 60 + minute;
    return total;

}

bool Time::operator>(Time t)
{
    if (hour > t.hour)
    {
        return true;
    }
    else if (hour == t.hour)
    {
        if (minute > t.minute)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

void Time::print()
{
    cout << hour << ":" << minute << endl;
}


#endif