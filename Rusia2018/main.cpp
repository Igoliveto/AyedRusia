#include <iostream>
#include "Equipo.h"
#include "ListaEquipo.h"
#include "ListaGrupo.h"
#include "ListaJugadores.h"
#include <stdlib.h>
#include <string>
using namespace std;
void alta();
void administrarPartidos();
int main()
{
    int opcion=0;


    while(opcion!=3){
     cout<<"1_Altas, bajas y modificaciones"<<endl;
     cout<<"2_Administrar partidos"<<endl;
     cout<<"3_Salir"<<endl;
     cin>>opcion;

     switch(opcion){
     case 1: alta();
     case 2: administrarPartidos();




     }
     }
    return 0;
}

void alta(){
ListaEquipo listaEquipo;
crearListaEquipo(listaEquipo);
Equipo equipo;
string nombre;
int id=0;
cout<<"ingrese id :"<<endl;
cin>>id;
cout<<"ingrese nombre del equipo :"<<endl;
cin>>nombre;
crearEquipo(equipo,id,nombre);
adicionarAlPrincipio(listaEquipo,equipo);

};

void administrarPartidos(){

}
