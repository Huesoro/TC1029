#include <iostream>

using namespace std;

class LineaTel {
    private:

    string propietario;
    string plan;
    float limiteCredito;

    public:
    LineaTel();
    LineaTel(string, string, float);
    void muestraLinea();
};

LineaTel::LineaTel() {
    propietario = "Sin propietario";
    plan = "Sin plan";
    limiteCredito = 0;
}

LineaTel::LineaTel(string _propietario, string _plan, float _limiteCredito) {
    propietario = _propietario;
    plan = _plan;
    limiteCredito = _limiteCredito;
}

void LineaTel::muestraLinea() {
    cout << "Datos de la linea:" << endl;
    cout << "---------" << endl;
    cout << endl << "Propietario: " << propietario << endl;
    cout << endl << "Plan: " << plan << endl;
    cout << endl << "Limite de credito: " << limiteCredito << endl;
}

int main() {
    LineaTel linea1, linea2, linea3("Juan", "Sin limites", 0), linea4("Ximena", "Basico", 3), linea5("Carlos", "Premium", 5);
    linea1.muestraLinea();
    linea2.muestraLinea();
    linea3.muestraLinea();
    linea4.muestraLinea();
    linea5.muestraLinea();
    return 0;
}