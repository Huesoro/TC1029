#include <iostream>

using namespace std;

// Declarar la clase Fecha
class Fecha {
    private:
    int anio;
    string mes;
    int dia;

    public:

    Fecha();
    Fecha(int, string ,int);
    void muestraFecha();

};

// Definir los metodos de la clase Fecha

Fecha::Fecha() {
    anio = 1984;
    mes = "Marzo";
    dia = 3;
}

Fecha::Fecha(int _anio, string _mes, int _dia) {
    anio = _anio;
    mes = _mes;
    dia = _dia;
}

void Fecha::muestraFecha() {
    cout << "Fecha de contratacion:" << endl;
    cout << "Fecha: " << dia << "/" << mes << "/" << anio << endl;
    cout << endl;
}

// Declarar la clase LineaTel
class LineaTel {
    private:

    string propietario;
    string plan;
    float limiteCredito;
    Fecha fechaContrato;


    public:
    LineaTel();
    LineaTel(string, string, float, Fecha);
    void muestraLinea();
};

// Definir los metodos de la clase LineaTel
LineaTel::LineaTel() {
    Fecha();
    propietario = "Sin propietario";
    plan = "Sin plan";
    limiteCredito = 0;
    fechaContrato = Fecha();
}

LineaTel::LineaTel(string _propietario, string _plan, float _limiteCredito, Fecha _fechaContrato) {
    propietario = _propietario;
    plan = _plan;
    limiteCredito = _limiteCredito;
    fechaContrato = _fechaContrato;
}

void LineaTel::muestraLinea() {
    cout << "Datos de la linea:" << endl;
    cout << endl << "Propietario: " << propietario << endl;
    cout << "Plan: " << plan << endl;
    cout << "Limite de credito: " << limiteCredito << "     mb" << endl;
    fechaContrato.muestraFecha();
    cout << "---------" << endl;
}

// Definir el metodo main
int main() {

    // Crear objetos de la clase Fecha
    Fecha fecha1, fecha2(2019, "Enero", 1), fecha3, fecha4(2019, "Marzo", 3), fecha5(2019, "Abril", 4);

    // Crear objetos de la clase LineaTel
    LineaTel linea1, linea2, linea3("Juan", "Sin limites", 0, fecha2), linea4("Ximena", "Basico", 3, fecha4), linea5("Carlos", "Premium", 5, fecha5);
    // Mostrar los objetos de la clase LineaTel
    linea1.muestraLinea();

    linea2.muestraLinea();
    linea3.muestraLinea();
    linea4.muestraLinea();
    linea5.muestraLinea();

    fecha1.muestraFecha();
    fecha2.muestraFecha();
    fecha3.muestraFecha();
    fecha4.muestraFecha();
    fecha5.muestraFecha();

    return 0;
}