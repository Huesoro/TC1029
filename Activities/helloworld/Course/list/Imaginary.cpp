#include <iostream>
#include <fstream>
using namespace std;

//Declarar la clase vector

class Complex {
    private:
    double Real;
    double Img;

    public:

    Complex();
    double getReal();
    double getImg();
    void setReal(double);
    void setImg(double);
    Complex(double,double);
    Complex sum(Complex);
    void muestraDatos();
    void print();

};

Complex::Complex() {
    Real = 0;
    Img = 0;
};

Complex::Complex(double _Real, double _Img) {
    Real = _Real;
    Img = _Img;
};



void Complex::muestraDatos() {
    cout << "El número imaginario es: " << Real << " + " << Img << "i" << endl;
};

Complex Complex::sum(Complex v2) {
    Complex result;
    result.Real = Real + v2.Real;
    result.Img = Img + v2.Img;
    return result;
};

void Complex::setReal(double _Real) {
    Real = _Real;
};

void Complex::setImg(double _Img) {
    Img = _Img;
};

double Complex::getReal() {
    return Real;
};

double Complex::getImg() {
    return Img;
};


void readFromFileToArray(string fileName, Complex list[], int &size) {
    ifstream file;
    file.open(fileName.c_str());
    int Real, Img;
    size = 0;
    while (file >> Real >> Img){
        Complex f(Real, Img);
        list[size] = f;
        size++;
    }
    file.close();
};

void addComplexList(Complex array1[], Complex arraySums[], int size1, int &sizeSums) {
    int i = size1;
    while (i > 0) {
        arraySums[i-1] = array1[i].sum(array1[i-1]);
        i--;
        sizeSums++;
    }
    cout << "Sum of all number: " << endl;
    arraySums[0].muestraDatos();
    cout << endl;
    i = 0;
    while (i < sizeSums) {
        arraySums[i].muestraDatos();
        i = i+1;
    };
};

int main()
{
	// write the code to complete the exercise
    Complex list1[10], list2[10];
    int size1, size2, sizeList;
    Complex A(3,5), B(4,6),C;

    C = A.sum(B);
    readFromFileToArray("file1.txt", list1, size1);
    cout << "Size of list1: " << size1 << endl;
    addComplexList(list1, list2, size1, size2);
    cout << "Size of list2: " << size2 << endl;
    //Read information from file1 to put it in list1
    
    return 0;
};