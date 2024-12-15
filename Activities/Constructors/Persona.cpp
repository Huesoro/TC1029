#include <iostream>

using namespace std;

class Persona{
private:
//Declarar atributos
string nombre;
int edad;
float estatura;
float masa;
string nacionalidad;

public:

//Declarar constructores
Persona();
Persona(string, int, float, float, string);

// Declarar setters
void setNombre(string);
void setEdad(int);
void setEstatura(float);
void setMasa(float);
void setNacionalidad(string);

// Declarar getters
string getNombre();
int getEdad();
float getEstatura();
float getMasa();
string getNacionalidad();

//declarar el muestra datos
void muestraDatos();
void calculaIMC();
void calculaAgua();
};
//Definitr los metodos de la clase

//Definir los constructores
Persona::Persona(){
    nombre = "No definido";
    edad = 0;
    estatura = 1;
    masa = 0;
    nacionalidad = "Mex";
}

//Constructor con parametros
Persona::Persona(string _nombre, int _edad, float _estatura, float _masa, string _nacionalidad){
    nombre = _nombre;
    edad = _edad;
    estatura = _estatura;
    masa = _masa;
    nacionalidad = _nacionalidad;
}

void Persona::setNombre(string _nombre){
    nombre = _nombre;
}

void Persona::setEdad(int _edad){
    edad = _edad;
}

void Persona::setEstatura(float _estatura){
    estatura = _estatura;
}

void Persona::setMasa(float _masa){
    masa = _masa;
}

void Persona::setNacionalidad(string _nacionalidad){
    nacionalidad = _nacionalidad;
}

//Definir getters
string Persona::getNombre(){
    return nombre;
}

int Persona::getEdad(){
    return edad;
}

float Persona::getEstatura(){
    return estatura;
}

float Persona::getMasa(){
    return masa;
}

string Persona::getNacionalidad(){
    return nacionalidad;
};
//Definir muestra datos
void Persona::muestraDatos(){
    cout << endl << "****************************" << endl;
    cout << endl << "Nombre: " << nombre << endl;
    cout << endl << "Edad: " << edad << endl;
    cout << endl << "Estatura: " << estatura << "mts" << endl;
    cout << endl << "Peso: " << masa << "kgs" << endl;
    cout << endl << "Nacionalidad: " << nacionalidad << endl << endl;
}
void Persona::calculaIMC(){
    cout << nombre << " tu IMC es: " << (masa/(estatura*estatura)) << endl << endl;
};

void Persona::calculaAgua(){
    cout << nombre << " necesitas tomar: " << (masa * 5.035) << " litros de agua al dia" << endl << endl;
};

//Crear y manipular objetos

int main(){
    //Declarar objeto de la clase persona
    Persona persona1,persona2("Paty", 18, 1.6, 60, "USA"),persona3,persona4("Juan", 23, 1.85, 95, "CAN");

    cout << "Mostrando persona 1" << endl;
    persona1.muestraDatos();

    //Asignar valores a los atributos por medio de setters
    persona1.setNombre("Pancho");
    persona1.setEdad(30);
    persona1.setEstatura(1.70);
    persona1.setMasa(75.2);
    persona1.setNacionalidad("Mex");

    cout << endl << "Datos de todas las personas incluyendo persona 1 modificada por setter" << endl;

    //Mostrar datos del objeto
    persona1.muestraDatos();
    persona2.muestraDatos();
    persona3.muestraDatos();
    persona4.muestraDatos();

    //Llamar al metodo calcula IMC
    persona1.calculaIMC();
    persona1.calculaAgua();
    persona2.calculaIMC();
    persona2.calculaAgua();
    persona3.calculaIMC();
    persona3.calculaAgua();
    persona4.calculaIMC();
    persona4.calculaAgua();    
    

    return 0;
}