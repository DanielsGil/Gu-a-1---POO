#include <iostream>
#include <cmath>
#include <string>
#include <sstream>  // Incluir encabezado para std::stringstream
#include <stdexcept>

using namespace std;

class Punto2D {
public:
    Punto2D(double x = 0.0, double y = 0.0) : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    string toString() const {
        stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return ss.str();
    }

private:
    double x, y;
};

class Vector2D {
public:
    Vector2D() : x(0.0), y(0.0) {}
    Vector2D(const Punto2D& p) : x(p.getX()), y(p.getY()) {}
    Vector2D(const Punto2D& p1, const Punto2D& p2) : x(p2.getX() - p1.getX()), y(p2.getY() - p1.getY()) {}

    double getX() const { return x; }
    double getY() const { return y; }

    double modulo() const {
        return sqrt(x * x + y * y);
    }

private:
    double x, y;
};

class Triangulo2D {
public:
    Triangulo2D() : p1(0.0, 0.0), p2(1.0, 1.0), p3(0.0, 1.0) {
        calcularAngulos();
    }

    Triangulo2D(const Punto2D& p1, const Punto2D& p2, const Punto2D& p3) : p1(p1), p2(p2), p3(p3) {
        if (!esValido())
            throw invalid_argument("Los puntos ingresados no forman un triangulo valido.");
        calcularAngulos();
    }

    Triangulo2D(const Punto2D& p1, const Vector2D& v) : p1(p1), p2(p1.getX() + v.getX(), p1.getY() + v.getY()), p3(p1.getX(), p1.getY() + v.modulo()) {
        if (!esValido())
            throw invalid_argument("Los puntos ingresados no forman un triangulo valido.");
        calcularAngulos();
    }

    double area() const {
        double a = p1.getX() * (p2.getY() - p3.getY());
        double b = p2.getX() * (p3.getY() - p1.getY());
        double c = p3.getX() * (p1.getY() - p2.getY());
        return abs(a + b + c) / 2.0;
    }

    double perimetro() const {
        double a = sqrt(pow(p2.getX() - p1.getX(), 2) + pow(p2.getY() - p1.getY(), 2));
        double b = sqrt(pow(p3.getX() - p2.getX(), 2) + pow(p3.getY() - p2.getY(), 2));
        double c = sqrt(pow(p1.getX() - p3.getX(), 2) + pow(p1.getY() - p3.getY(), 2));
        return a + b + c;
    }

    string toString() const {
        stringstream ss;
        ss << "Triangulo: " << p1.toString() << ", " << p2.toString() << ", " << p3.toString() << "\nAngulos: " << angulos[0] << ", " << angulos[1] << ", " << angulos[2] << "";
        return ss.str();
    }

private:
    Punto2D p1, p2, p3;
    double angulos[3];

    bool esValido() const {
        Vector2D v1(p1, p2);
        Vector2D v2(p2, p3);
        Vector2D v3(p3, p1);
        return (v1.modulo() + v2.modulo() > v3.modulo()) && (v2.modulo() + v3.modulo() > v1.modulo()) && (v3.modulo() + v1.modulo() > v2.modulo());
    }

    void calcularAngulos() {
        Vector2D v1(p1, p2);
        Vector2D v2(p2, p3);
        Vector2D v3(p3, p1);

        angulos[0] = acos((pow(v2.getX(), 2) + pow(v2.getY(), 2) + pow(v3.getX(), 2) + pow(v3.getY(), 2) - pow(v1.modulo(), 2)) / (2 * v2.modulo() * v3.modulo())) * 180.0 / M_PI;
        angulos[1] = acos((pow(v1.getX(), 2) + pow(v1.getY(), 2) + pow(v3.getX(), 2) + pow(v3.getY(), 2) - pow(v2.modulo(), 2)) / (2 * v1.modulo() * v3.modulo())) * 180.0 / M_PI;
        angulos[2] = 180.0 - angulos[0] - angulos[1];
    }
};

int main() {
    try {
        Triangulo2D t1(Punto2D(0, 0), Punto2D(1, 1), Punto2D(0, 1));
        cout << "Triangulo 1: " << t1.toString() << endl;
        cout << "Area: " << t1.area() << endl;
        cout << "Perimetro: " << t1.perimetro() << endl;

        Triangulo2D t2(Punto2D(0, 0), Vector2D(3, 4));
        cout << "\nTriangulo 2: " << t2.toString() << endl;
        cout << "Area: " << t2.area() << endl;
        cout << "Perimetro: " << t2.perimetro() << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
