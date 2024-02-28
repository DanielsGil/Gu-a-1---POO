#include <iostream>
#include <string> 

using namespace std;

class Vehiculos {
protected:
    float kilometraje;
    string marca;

public:
    Vehiculos(float, string);
    virtual void mostrar();
};

Vehiculos::Vehiculos(float _kilometraje, string _marca) {
    kilometraje = _kilometraje;
    marca = _marca;
}

void Vehiculos::mostrar() {
    cout << "El kilometraje del auto es: " << kilometraje << endl;
    cout << "De la marca: " << marca << endl;
}

class Carro : public Vehiculos {
private:
    string placa;
    string color;

public:
    Carro(float, string, string, string); 
    void mostrar();
};

Carro::Carro(float _kilometraje, string _marca, string _placa, string _color) : Vehiculos(_kilometraje, _marca) {
    placa = _placa;
    color = _color;
}

void Carro::mostrar() {
    Vehiculos::mostrar();
    cout << "Placa: " << placa << endl;
    cout << "Color: " << color << endl;
}

int main() {
    Vehiculos* lista[2];
    lista[0] = new Carro(123454.0, "honda", "123-4f", "black"); 
    lista[1] = new Carro(124846.0, "toyota", "153-4k", "yellow"); 

    for (int i = 0; i < 2; i++) {
        lista[i]->mostrar();
    }


    for (int i = 0; i < 2; i++) {
        delete lista[i];
    }

    return 0;
}