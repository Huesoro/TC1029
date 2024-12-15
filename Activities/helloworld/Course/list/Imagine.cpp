#include <iostream>
#include <fstream>
using namespace std;

//Clase
class Complex {
  private:
  double Real;
  double Img;

  public:

  Complex();
  Complex(double,double);
  double getReal();
  double getImg();
  void setReal(double);
  void setImg(double);
   
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
  cout << Real << " + " << Img << "i" << endl;
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
    //Display an error if the file is bigget than the list
    
    file.open(fileName.c_str());
    int Real, Img;
    size = 0;
    try
    {
        while (file >> Real >> Img){
        Complex f(Real, Img);
        list[size] = f;
        size++;
        if (size > 10) {
            throw std::overflow_error("File is bigger than the list");
        }
    }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    

    file.close();
};

void addComplexList(Complex array1[], int size1) {
    Complex sum(0,0);
    for(int i = 0; i < size1; i++){
      sum = sum.sum(array1[i]);
    };
    cout << "Sum of all number: " << endl;
    sum.muestraDatos();
    cout << "Values from list: " << endl;
    int i = 0;
    while (i < size1) {
        array1[i].muestraDatos();
        i = i+1;
    };
};

int main()
{
	// write the code to complete the exercise
  Complex list1[10];
  int size1;
  readFromFileToArray("complexNumbers.txt", list1, size1);
  cout << "Size of list1: " << size1 << endl;
  addComplexList(list1, size1);
  return 0;
}