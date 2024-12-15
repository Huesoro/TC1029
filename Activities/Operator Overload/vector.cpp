#include <iostream>

using namespace std;

//Declarar la clase vector

class Vector {
    private:
    double compX;
    double compY;

    public:

    Vector();
    double getCompX();
    double getCompY();
    void setCompX(double);
    void setCompY(double);
    Vector(double,double);

    void muestraDatos();

    //Sobrecarga de suma para Vectores
    Vector operator+(Vector);

};

Vector::Vector() {
    compX = 0;
    compY = 0;
}

Vector::Vector(double _compX, double _compY) {
    compX = _compX;
    compY = _compY;
}

void Vector::muestraDatos() {
    cout << "El vector es: " << compX << " + " << compY << "i" << endl;
}

Vector Vector::operator+(Vector v2) {
    
    double resX = compX + v2.compX;
    double resY = compY + v2.compY;

    Vector vectorResultante(resX,resY);
    return vectorResultante;
}

void Vector::setCompX(double _compX) {
    compX = _compX;
}

void Vector::setCompY(double _compY) {
    compY = _compY;
}

double Vector::getCompX() {
    return compX;
}

double Vector::getCompY() {
    return compY;
}

int main()
{
    Vector A(2,3), B(4,5), C;
    C.muestraDatos();
    B.muestraDatos();
    C = A + B;
    cout << "La suma de los vectores es: " << endl;
    C.muestraDatos();


    return 0;
}
