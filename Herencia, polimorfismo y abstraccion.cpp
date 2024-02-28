#include <iostream>
using namespace std;

class Animal // Clase generalizada
{
  protected:
    bool comer;  // Variables de la clase madre Animal
    bool dormir;

  public:
    Animal(bool c, bool d)  
    {
        comer = c;
        dormir = d;
    }
    virtual void estado(); // Variable virtual para el polimorfismo y uso de funciones
};

void Animal::estado()
{
  {
      if(comer){cout<<"Ya comio"<<endl;} 
      else {cout<<"No ha comido :c"<<endl;}

      if(dormir){cout<<"Esta durmiendo"<<endl;}
      else{cout<<"Esta activo";}
  }
} // Funcion estado para Animal

class Perro : public Animal   // Clase hija de Animal, hereda sus variables, clase especializada
{
    private:
        string nombre;
    public:
        Perro(string n, bool c, bool d) : Animal(c,d) // Indentación de las variables clase Perro
        {  
            nombre = n;
            comer = c;
            dormir = d;
        } // Abstraccion de la realidad
    void estado(); 
};
void Perro::estado() //Reusabilidad de las variables
{
    cout<<"El estado de "<<nombre<<" es:"<<endl;
    Animal::estado();
} // Polimorfismo

    

int main() {
  
  Perro p1 = Perro("Firulais", true, false);
  p1.estado();
  
  return 0;
}
