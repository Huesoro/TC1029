#include <iostream>

using namespace std;

// Declarar la clase Perro
class Perro{
    //Atributos
private:
    string nombre;
    string raza;
    string tamaño;
    int edad;

public:
    Perro();
    Perro(string, string, string, int);

    void muestradatos();
    void comer();
    void ladrar();
    void dormir();

};

//Definir los metodos de la clase Perro
//Constructores

Perro::Perro() {
    nombre = "Solovino";
    raza = "sin raza";
    tamaño = "Sin tamaño";
    edad = 0;
}

Perro::Perro(string _nombre, string _raza, string _tamaño, int _edad) {
    nombre = _nombre;
    raza = _raza;
    tamaño = _tamaño;
    edad = _edad;
}

//Muestradatos
void Perro::muestradatos() {
    cout << "Nombre: " << nombre << endl;
    cout << "Raza: " << raza << endl;
    cout << "Tamaño: " << tamaño << endl;
    cout << "Edad: " << edad << endl;
}

void Perro::comer() {
    cout << "Soy " << nombre << " y estoy comiendo carne asada"<< endl;
};

void Perro::ladrar() {
    cout << "GUA GUA soy " << nombre << endl;
};

void Perro::dormir() {
    cout << nombre << " Durmiendo ... ZZZZ" << endl;
};

int main() {
    Perro perrito1, perrito2("Firulais","Doberman","Grande",8), perrito3("Calcetin","Chihuahua","Pequeño",2), perrito4;
    perrito1.muestradatos();
    perrito2.muestradatos();
    perrito3.muestradatos();
    perrito4.muestradatos();

    perrito3.ladrar();
    perrito2.comer();
}