#include <iostream>
using namespace std;

class Rectangulo {
private:
    float longitud;
    float ancho;

public:
    Rectangulo(float l, float a) {
        longitud = l;
        ancho = a;
    }

    // Métodos para establecer la longitud y el ancho
    void setLongitud(float l) {
        longitud = l;
    }

    void setAncho(float a) {
        ancho = a;
    }

    // Métodos para obtener la longitud y el ancho
    float getLongitud() {
        return longitud;
    }

    float getAncho() {
        return ancho;
    }

    // Método para calcular el área del rectángulo
    float calcularArea() {
        return longitud * ancho;
    }
};

int main() {
    Rectangulo rect(5.0, 3.0); 

    // Acceder a los métodos públicos para obtener la longitud y el ancho
    cout << "Longitud del rectangulo: " << rect.getLongitud() << endl;
    cout << "Ancho del rectangulo: " << rect.getAncho() << endl;

    // Calcular y mostrar el área del rectángulo
    cout << "Area del rectangulo: " << rect.calcularArea() << endl;

    // Modificar la longitud y el ancho del rectángulo
    rect.setLongitud(7.0);
    rect.setAncho(4.0);

    // Mostrar los nuevos valores de longitud y ancho
    cout << "Nueva longitud del rectangulo: " << rect.getLongitud() << endl;
    cout << "Nuevo ancho del rectangulo: " << rect.getAncho() << endl;
    cout << "Nueva area del rectangulo: " << rect.calcularArea() << endl;

    return 0;
}
