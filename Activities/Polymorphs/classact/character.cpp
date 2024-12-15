#include <iostream>
using namespace std;

class Character
{
public:
    Character();
    Character(string n, int d);
    void setName(string n) { name = n; }
    string getName() { return name; }
    void setDirection(int d) { direction = d; }
    int getDirection() { return direction; }
    virtual void print() = 0; // Note that this is a virtual method.
    // THEREFORE this is an abstract class.
protected:
    string name;
    int direction; // 1 means going right, 2 means going left
};
Character::Character() {
    name = "-";
    direction = 1; // 1 means going right
}
Character::Character(string n, int d) {
    name = n;
    direction = d;
}

class Good : public Character
{
public:
    Good();
    Good(string n, int d);
    void print();
};
Good::Good() : Character() {}
Good::Good(string n, int d) : Character(n, d) {}
void Good::print() {
    if (direction == 1)
        cout << endl << "I am good, my name is " << name << " and I'm moving to the right" << endl;
    else
        cout << endl << "I am good, my name is " << name << " and I'm moving to the left" << endl;
}

class Bad : public Character
{
public:
    Bad();
    Bad(string n, int d);
    void print();
};
Bad::Bad() : Character() {}
Bad::Bad(string n, int d) : Character(n, d) {}
void Bad::print() {
    if (direction == 1)
        cout << endl << "I'm bad, my name is " << name << " and I'm moving to the right" << endl;
    else
        cout << endl << "I'm bad, my name is " << name << " and I'm moving to the left" << endl;
}

int main(){
    Character *list[4];
    list[0] = new Good("Mario", 1);
    list[1] = new Bad("Bowser", 1);
    list[2] = new Good("Luigi", 2);
    list[3] = new Bad("Wario", 2);
    for (int counter = 0; counter < 4; counter ++)
    list[counter]->print();
    return 0;
}