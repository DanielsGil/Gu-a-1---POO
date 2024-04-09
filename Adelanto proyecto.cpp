#include <iostream>
#include <vector>
using namespace std;


int contadorVotos = 0;
class Persona
{
  public:
    string nombre;
    int edad;
  public:
    Persona(string _nombre,int _edad)
    {
    nombre = _nombre;
    edad = _edad;
    }
   
    virtual void informacion_candidatos(){}
};

Persona *votantes[1];

class Candidato : public Persona{
  public:
    int valor_campaña;
    int votos_obtenidos;
    float porcentaje_votos;
    int id_Candidato;
    string partido_politico;

    Candidato(string _nombre , int _edad, int _id_Candidato, string _partido_politico): Persona(_nombre ,_edad)
    {
      id_Candidato = _id_Candidato;
      partido_politico = _partido_politico;
    }
  

    


float porcentajeDevotos(){
  
}
    void informacion_candidatos()
    {
      cout<<"Nombre: "<<nombre<<endl;
      cout<<"Edad: "<<edad<<endl;
      cout<<"Partido politico: "<<partido_politico;
      cout<<endl<<endl;
    }
};

    

class Votante : public Persona{
  public:

    int idVotante;
    string genero;
    int influenciaVoto;
    int candidatoID;
    Votante(string _nombre, int _edad, int id, string _genero, int infVoto) : Persona(_nombre,_edad)
    {
      idVotante = id;
      genero = _genero;
      influenciaVoto = infVoto;
    }

};

void costoDeCampana(vector<Votante*> votantes) {
    int costoTotal = 0;
    for (auto& votante : votantes) {
        if (votante != nullptr && votante->candidatoID == this->id_Candidato) {
            switch (votante->influenciaVoto) {
                case 1: // Televisión
                    costoTotal += 1000;
                    break;
                case 2: // Radio
                    costoTotal += 500;
                    break;
                case 3: // Internet
                    costoTotal += 100;
                    break;
                default:
                    break;
            }
        }
    }
    int valor_campaña = costoTotal;
}

void Candidato::calculoDeVotos(vector<Votante*> votantes) {

  votos_obtenidos = 0;

  for (auto& votante : votantes) {
      if (votante->candidatoID == this->id_Candidato) {
          votos_obtenidos++; 
      }
  }
{

//----------------------------------------------------------------------------------------------//

void crear_candidatos()
{
  
    
}
//-------------------------------------------------------------------------//

//------------------------------------------------------------------------------------------------//

void interfaz_administrador()
{
      int opcion;

      cout << "                            Bienvenido administrador" << endl<<endl;

      cout<<"---------------------------------Digite la opcion deseada--------------------------"<<endl;
      cout<<" 1. Ingresar candidatos"<<endl;
      cout<<" 2. Ver estadisticas"<<endl<<endl;
      cout<<"Opcion: "; cin>>opcion;
}

  


//-----------------------------------------------------------------------------------//
void votar()
  {
    int _idVotante;
    string _nombre;
    int _edad;
    string _genero;
    int _influenciaVoto;
    
    cout<<"Ingrese su id: "; cin>>_idVotante; cout<<endl;
    cout<<"Ingrese su nombre: "; cin>> _nombre; cout<<endl;
    cout<<"Ingrese su edad: "; cin>>_edad; cout<<endl;
    cout<<"Ingrese su genero: "; cin>> _genero; cout<<endl;
    cout<<"Ingrese por cual medio decidio influencia de voto:"<<endl;
    cout<<"1. Television"<<endl;
    cout<<"2. Radio"<<endl;
    cout<<"3. Internet"<<endl;
    cout<<"3. Ninguno"<<endl;
    cout<<"Opcion: "; cin>>_influenciaVoto; cout<<endl;

    contadorVotos++;

    votantes[contadorVotos] = new Votante( _nombre, _edad, _idVotante, _genero, _influenciaVoto);
  }

//-----------------------------------------------------------------------------------//
  
int main()
{
    Persona *candidatos[3];
    candidatos[0] = new Candidato("Juan",30,1,"Partido A");
    candidatos[1] = new Candidato("Pedro",45,2,"Partido B");
    candidatos[2] = new Candidato("Antonio",60,3,"Partido C");
    int opcion;
    cin>>opcion;

    cout << "                      Bienvenido al sistema de votacion" << endl<<endl;
  
    for(int i=0; i==0;)
    {
      cout << "                            Bienvenido votante" << endl<<endl;

      cout<<"---------------------------------Digite la opcion deseada--------------------------"<<endl;
      cout<<" 1. Ver informacion de los candidatos"<<endl;
      cout<<" 2. Votar"<<endl<<endl;
      cout<<"Opcion: "; cin>>opcion;

      switch(opcion){

        case 1:
          cout<<"Candidato 1: "<<endl;
          candidatos[0]->informacion_candidatos();
           cout<<"Candidato 2"<<endl;
          candidatos[1]->informacion_candidatos();
           cout<<"Candidato 3"<<endl;
          candidatos[2]->informacion_candidatos();
          
          break;
        case 2:
            votar();
          break;
        case 1234:
          interfaz_administrador();
         
          break;
        default:
          cout<<"Opcion no valida."<<endl;
          break;
      }
    }
    return 0;
}