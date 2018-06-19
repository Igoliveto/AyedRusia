#include <iostream>
#include "Equipo.h"
#include "ListaEquipo.h"
#include "ListaGrupo.h"
#include "ListaJugadores.h"
#include "ListaPartidos.h"
#include <stdlib.h>
#include <string>
using namespace std;
void alta();
void administrarPartidos();
int main()
{
     int menu=0;
    int submenu1=0,submenu2=0,submenu3=0;


    while(menu!=4){
     cout<<"1_Administrar equipos, jugadores, rupos y partidos(Altas, bajas y modificaciones)"<<endl;
     cout<<"2_Administrar partidos"<<endl;
     cout<<"3_Procesar reportes"<<endl;
     cout<<"4_Salir"<<endl;
     cin>>menu;

     switch(menu){
     case 1://Administrar equipos, jugadores, rupos y partidos(Altas, bajas y modificaciones)

                 while(submenu1!=4){
                 cout<<"1_Altas"<<endl;
                 cout<<"2_Bajas"<<endl;
                 cout<<"3_Modificaciones"<<endl;
                 cout<<"4_Atras"<<endl;
                 cin>>submenu1;

                 switch(submenu1){

             case 1://altas
             case 2://bajas
             case 3://modificaciones
             case 4:break;



                 }
                 }
            break;


     case 2: //administrar partidos

            while(submenu2!=4){
                 cout<<"1-Registrar inicio de partidos"<<endl;
                 cout<<"2_Registrar goles ocurridos en cada partido"<<endl;
                 cout<<"3_Registrar fin de un partido"<<endl;
                 cout<<"4_Atras"<<endl;
                 cin>>submenu2;

                 switch(submenu2){

             case 1://Registrar inicio de partidos
             case 2://Registrar goles ocurridos en cada partido
             case 3://Registrar fin de un partido
             case 4:break;



                 }
                 }
                  break;
     case 3: //reportes

            while(submenu3!=6){
                 cout<<"1-Listado de goleadores"<<endl;
                 cout<<"2_Orden de equipos por Grupo"<<endl;
                 cout<<"3_Fixture"<<endl;
                 cout<<"4_Grupo de la muerte"<<endl;
                 cout<<"5_Porcentajes goles local o visitante"<<endl;
                 cout<<"6_Atras"<<endl;
                 cin>>submenu3;

                 switch(submenu3){

             case 1://Registrar inicio de partidos
             case 2://Registrar goles ocurridos en cada partido
             case 3://Registrar fin de un partido
             case 4:
             case 5:
             case 6:break;



                 }
                 }
                  break;
     case 4: break;



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
