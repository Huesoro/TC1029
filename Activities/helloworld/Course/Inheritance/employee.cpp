#include <iostream>
using namespace std;

class Employee {
    public:
        Employee();
        Employee(int ide, double sal);
        void setIdent(int ide) { ident = ide; }
        void setSalary(double sal) { salary = sal; }
        int getIdent() { return ident; }
        double getSalary() { return salary; }
        double calculatePayment();
        void print();
    protected:
        int ident;
        double salary;
};

Employee :: Employee() {
    ident = 0;
    salary = 0;
}
Employee :: Employee(int ide, double sal) {
    ident = ide;
    salary = sal;
}
// the payment of an employee is his salary
double Employee :: calculatePayment() {
    return salary;
}
void Employee::print() {
    cout << "Employee id " << ident;
    cout << " salary $" << salary << endl;
}

// Seller inherit class

class Seller : public Employee {
    public:
        Seller();
        Seller(int ide, double sal, double comperc, double sells);
        void setCommission(double comperc) { commission = comperc; }
        double getCommission() { return commission; }

        double calculatePayment();
        void print();
    private:
        double commission;
        double sales;
};

Seller::Seller() : Employee() {
    commission = 0;
    sales = 0;
}

Seller::Seller(int ide, double sal, double comperc, double sells) : Employee(ide, sal) {
    commission = comperc;
    sales = sells;
}

// the payment of a seller is his salary plus his commission per sales
double Seller::calculatePayment() {
    return salary + commission * sales;
}

void Seller::print() {
    Employee::print();
    cout << " Commision Percentage " << commission;
    cout << " sales " << sales << endl;
}

    int main() {
    Employee emp1(129, 12000);
    Employee emp2(231, 13500);
    Seller vend1(146, 8500, 0.03, 155000);
    Seller vend2(275, 5500, 0.05, 132500);
    cout << "Employee 1 " << endl;
    emp1.print();
    cout << "Payment " << emp1.calculatePayment() << endl;
    cout << "Employee 2 " << endl;
    emp2.print();
    cout << "Payment " << emp2.calculatePayment() << endl;
    cout << "Seller 1 " << endl;
    vend1.print();
    cout << "Payment " << vend1.calculatePayment() << endl;
    cout << "Seller 2 " << endl;
    vend2.print();
    cout << "Payment " << vend2.calculatePayment() << endl;
    return 0;
}