// Kaleb Flores, Adrian Castro, Miguel Gonzalez, Luis Carlos Guerrero Aragón 

// Bazar

// librerias
#include <iostream>
using namespace std;

// declarar clase(s)
class Objeto {
private:
    string nombre; 
    string tipo; 
    string marca;
    double precio;

public:
    // declarar constuctores

    Objeto();
    Objeto(string,string,string,double);

    // declarar metodos

    void muestraDatos();
    void comprar();
    void vender();
    void intercambiar();
    void regresar();
};


class Sucursal {
private:
    
    string ubicacion;
    string horario;
    string telefono;
    string diasHabiles;
    Objeto objeto1;
    

  public:

    Sucursal();
    Sucursal(string, string, string, string);
    
    void muestraDatos();
  
    
};

// definir constructores

Objeto::Objeto() {
    nombre = "N/A";
    tipo = "N/A";
    marca = "N/A";
    precio = 0;
}

Objeto::Objeto(string _nombre, string _tipo, string _marca, double _precio) {
    nombre = _nombre;
    tipo = _tipo;
    marca = _marca;
    precio = _precio;
}

Sucursal::Sucursal(){
  ubicacion = "Muy muy Lejano";
  horario = "Hace mucho tiempo";
  telefono = "684587965";
  diasHabiles = "No soy habil, una disculpa";
}

Sucursal::Sucursal(string _ubicacion, string _horario, string _telefono, string _diasHabiles){
  ubicacion = _ubicacion;
  horario = _horario;
  telefono = _telefono;
  diasHabiles = _diasHabiles;
}

void Sucursal::muestraDatos(){
    cout << endl << "Sucursal" << endl;
    cout << "Ubicación: " << ubicacion << endl;
    cout << "Horario: " << horario << endl;
    cout << "Telefono: " << telefono << " solo en horario" << endl;
    cout << "Los días hábiles son: " << diasHabiles << endl;
    cout << "Tenemos en existencia: " << endl;
}




// definir metodos

void Objeto::muestraDatos() {
    cout << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: " << precio << endl;
}

void Objeto::comprar() {
    cout << endl << "Se compra el producto: " << nombre << ". Pagas $" << precio << "." << endl;
}

void Objeto::vender() {
    cout << endl << "Se vende el producto: " << nombre << ". El bazar lo compra al 80% de su costo original. Obtienes $" << precio*.8 << "." << endl;
}

void Objeto::intercambiar() {
    cout << endl << "Vas a intercambiar algo por este producto: " << nombre << "." << endl;

    cout << endl << "Escribe el nombre del producto que vas a intercambiar: " << endl;
    cin >> nombre;
    cout << endl << "Escribe que tipo de producto es: " << endl;
    cin >> tipo;
    cout << endl << "Escribe la marca del producto: " << endl;
    cin >> marca;
    cout << endl << "Escribe el precio del producto: " << endl;
    cin >> precio;

    cout << endl << "El producto intercambiado ahora tiene estas caracteristicas: " << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Tipo: " << tipo << endl;
    cout << "Marca: " << marca << endl;
    cout << "Precio: " << precio << endl;
}

void Objeto::regresar() {
    cout << endl << "Has regresado el producto: " << nombre << ". Obtienes $" << precio << "." << endl;
}

// manipular objetos de la clase establecida en funcion main
int main() 
{
    // declarar un objeto de la(s) clase(S) usando constructor
    Objeto producto1("playera", "vestimenta", "zara", 400), producto2("zapato","vestimenta","nike",500), producto3("camisa","vestienta","h&m",300), producto4();
    Sucursal suc1(), suc2("Calle 1", "8:00 a 18:00", "684587965", "Lunes a Viernes"), suc3(), suc4("Calle 2", "8:00 a 16:00", "N/A", "Lunes a Miercoles");
    
    
    cout << endl << "----------------------------------------------------" << endl;

    // llamar metodos
    suc1.muestraDatos();
    suc2.muestraDatos();
    suc3.muestraDatos();
    suc4.muestraDatos();
    
    producto1.muestraDatos();
    producto2.muestraDatos();
    producto3.muestraDatos();
    producto4.muestraDatos();

    producto1.comprar();
    producto2.vender();
    producto3.regresar();
    producto4.intercambiar();

    cout << endl << "----------------------------------------------------" << endl;
    return 0;
}
