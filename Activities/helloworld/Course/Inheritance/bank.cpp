#include <iostream>
using namespace std;

class BankAcc{
public:
    BankAcc();
    BankAcc(int n, double b);
    int getAccNumber() { return accNumber; }
    void setAccNumber(int n) { accNumber = n; }
    double getBalance() { return balance; }
    void setBalance(double b) { balance = b; }
    void deposit(double amount);
    bool withdrawal(double amount); // it has to be overridden in Commission Bank Account class
    void print(); // it has to be overridden in the Commission Bank Account class
private:
    int accNumber;
    double balance;
};
BankAcc::BankAcc() {
    accNumber = 0;
    balance = 0;
}
BankAcc::BankAcc(int n, double b) {
    accNumber = n;
    balance = b;
}
void BankAcc::deposit(double amount){
    balance += amount;
}
    // if there is enough money, subtracts the amount from the balance and returns true,
    //otherwise the balance remains unchanged and returns false.
bool BankAcc::withdrawal(double amount) {
    if (balance >= amount) {
        balance -= amount;
        return true;
    }
    else
        return false;
    }
void BankAcc::print() {
    cout << endl << "Account Number: " << accNumber << " balance: " << balance << endl;
}

// Commission Bank Account class
class CommAcc : public BankAcc {
public:
    CommAcc();
    CommAcc(int n, double b, double c);
    double getCommission() { return commission; }
    void setCommission(double c) { commission = c; }
    void deposit(double amount);
    bool withdrawal(double amount);
    void print();  
private:
    double commission;

};

CommAcc::CommAcc() : BankAcc() {
    commission = 0;
}
CommAcc::CommAcc(int n, double b, double c) : BankAcc(n, b) {
    commission = c;
}
void CommAcc::deposit(double amount) {
    BankAcc::deposit(amount);
    BankAcc::withdrawal(commission);
}
bool CommAcc::withdrawal(double amount) {
    if (BankAcc::withdrawal(amount + commission)) {
        BankAcc::withdrawal(commission);
        return true;
    }
    else
        return false;
}
void CommAcc::print() {
    BankAcc::print();
    cout << "Commission: " << commission << endl;
}


int main() {
    CommAcc cc;
    BankAcc cb;
    int accountNumber;
    double balance, comm;
    cout << "Type the account number for the bank account ";
    cin >> accountNumber;
    cb.setAccNumber(accountNumber);
    cout << "Type the initial balance for the bank account ";
    cin >> balance;
    cb.setBalance(balance);
    cout << "Type the account number for the commission account ";
    cin >> accountNumber;
    cc.setAccNumber(accountNumber);
    cout << "Type the initial balance for the commission account ";
    cin >> balance;
    cc.setBalance(balance);
    cout << "Type the amount of money that will be charged for each withdrawal ";
    cin >> comm;
    cc.setCommission(comm);
    cout << "The bank account information is " << endl;
    cb.print();
    cout << "The commission account information is " << endl;
    cc.print();
    cb.withdrawal(100);
    cc.withdrawal(100);
    cout << "after the withdrawal the bank account " << endl;
    cb.print();
    cout << "after the withdrawal the commission bank account " << endl;
    cc.print();
    return 0;
}