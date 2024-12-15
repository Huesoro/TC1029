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
    virtual bool withdrawal(double amount); // it has to be overridden in Commission Bank Account class
    virtual void print(); // it has to be overridden in the Commission Bank Account class
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
}

bool CommAcc::withdrawal(double amount) {
    if (BankAcc::withdrawal(amount + commission)) {
        return true;
    }
    else
        cout << "Insufficient funds" << endl;
        return false;
}
void CommAcc::print() {
    BankAcc::print();
    cout << "Commission: " << commission << endl;
}



int main()
{
    BankAcc *accList[20];
    int sizeAccList;
    char accType;
    int accId;
    double initialBalance, comm, amount;
    char option;
    cout << "How many bank accounts are there? ";
    cin >> sizeAccList;
    for (int c = 0; c < sizeAccList; c++)
    {
        cout << "Your account will be regular or commision? (r or c) ";
        cin >> accType;
        cout << "Account number? ";
        cin >> accId;
        cout << "Initial Balance? ";
        cin >> initialBalance;
    // TODO: Create the object according to the type of account
    // TODO: And put the object in the array of pointers to objects
        if (accType == 'c')
        {
        cout << "Commision fee for withdrawal? ";
        cin >> comm;
        accList[c] = new CommAcc(accId, initialBalance, comm);
        }
        else if(accType == 'r'){
            accList[c] = new BankAcc(accId, initialBalance);
        }
        
    }
    do
    {
        cout << "Options " << endl;
        cout << endl;
        cout << "a) deposit " << endl;
        cout << "b) withdrawal " << endl;
        cout << "c) display balance " << endl;
        cout << "d) exit " << endl;
        cout << "option ->";
        cin >> option;
        switch (option) {
        case 'a':
        {
        cout << "Account number? ";
        cin >> accId;
        cout << "Amount to deposit? ";
        cin >> amount;
        // TODO: Make the deposit to the correct account
        for (int c = 0; c < sizeAccList; c++)
        {
            if (accList[c]->getAccNumber() == accId)
            {
                accList[c]->deposit(amount);
            }
        }
        break;
        }
        case 'b':
        {
        cout << "Account number? ";
        cin >> accId;
        cout << " Amount to withdrawal? ";
        cin >> amount;
        // TODO: Make the withdrawal to the correct account
        for (int c = 0; c < sizeAccList; c++)
        {
            if (accList[c]->getAccNumber() == accId)
            {
                accList[c]->withdrawal(amount);
            }
        }
        break;
        }
        case 'c':
        {
        cout << "Account number? ";
        cin >> accId;
        // TODO: Display the balance of the account
        for (int c = 0; c < sizeAccList; c++)
        {
            if (accList[c]->getAccNumber() == accId)
            {
                accList[c]->print();
            }
        }
        break;
        }
    }
    } while (option != 'd');
    return 0;
}