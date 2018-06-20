#include <iostream>
#include "Equipo.h"
#include "ListaEquipo.h"
#include "ListaGrupo.h"
#include "ListaJugadores.h"
#include "ListaPartidos.h"
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;
void bateriaJugadores();
void administrarPartidos();
void cargarEquipos();
void cargarGrupos();
void cargarPartidos();
void cargarJugadores(Equipo &equipo);
void imprimirListaJugadores(ListaJugador  &lista);
int main()
{
    int menu=0;
    int submenu1=0,submenu2=0,submenu3=0;
    cargarEquipos();
    cargarGrupos();
    cargarPartidos();

    while(menu!=5){

     cout<<"1_Administrar equipos, jugadores, grupos y partidos(Altas, bajas y modificaciones)"<<endl;
     cout<<"2_Administrar partidos"<<endl;
     cout<<"3_Procesar reportes"<<endl;
     cout<<"4_Crear Datos de prueba"<<endl;
     cout<<"5_Salir"<<endl;

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
    case 4:
        bateriaJugadores();
        break;

     case 5:
        break;
    case 6://Test Interno(osea no le den  bola)
            Equipo* equipo = new Equipo;
            ListaJugador* listaJugador = new ListaJugador;
            Jugador* jugador = new Jugador;

            crearEquipo(*equipo);
            crearJugador(*jugador);

            adicionarDespues((*equipo).listaJugadores,*jugador,crearNodoListaJugador(*jugador));


        break;
     }
    }
    return 0;
}
void cargarEquipos(){
ListaEquipo listaEquipo;
crearListaEquipo(listaEquipo);
Equipo equipo;
crearEquipo(equipo);
ifstream archivo("equipos.txt"); // abrir el archivo en modo lectura//
int aux=0;
string linea;
if(archivo.is_open()){
    while(!archivo.eof()){        //mientras no sea el fin de archivo//
            getline(archivo,linea,';'); // leo desde el comienzo has ";" y lo guardo en linea//
            stringstream id(linea);  //Cargo en el stream "id", lo que esta en linea;
            id>>aux;                  // lo paso a aux;
            setId(equipo,aux);
            getline(archivo,linea,';');
            setNombre(equipo,linea);
            getline(archivo,linea,';');
            stringstream golA(linea);
            golA>>aux;
            setGolesAFavor(equipo,aux);
            getline(archivo,linea,';');
            stringstream golE(linea);
            golE>>aux;
            setGolesEnContra(equipo,aux);
            getline(archivo,linea);
            stringstream puntos(linea);
            puntos>>aux;
            setPuntos(equipo,aux);
            cout<<equipo.nombre<<endl;
            cargarJugadores(equipo);
            adicionarFinal(listaEquipo,equipo);
            destructor(equipo);

         }
        archivo.seekg(0); //Me posiciono al principio del archivo
}
archivo.close();
}

void cargarGrupos(){
ListaGrupo listaGrupo;
crearListaGrupo(listaGrupo);
Grupo grupo;
crearGrupo(grupo);
ifstream archivo("grupos.txt");
int aux=0;
char aux1;
string linea;
if(archivo.is_open()){

    while(!archivo.eof()){
         getline(archivo,linea,';');
         aux1=linea[0];
         setId(grupo,aux1);
         getline(archivo,linea,';');
         setNombre(grupo,linea);
         getline(archivo,linea,';');
         stringstream id1(linea);
         id1>>aux;
         setIdEquipo1(grupo,aux);
         getline(archivo,linea,';');
         stringstream id2(linea);
         id2>>aux;
         setIdEquipo2(grupo,aux);
         getline(archivo,linea,';');
         stringstream id3(linea);
         id3>>aux;
         setIdEquipo3(grupo,aux);
         getline(archivo,linea);
         stringstream id4(linea);
         id4>>aux;
         setIdEquipo4(grupo,aux);
         adicionarFinal(listaGrupo,grupo);


     }
      archivo.seekg(0); //Me posiciono al principio del archivo
}
archivo.close();
}

void bateriaJugadores(){
    int id =0;
    ofstream ficheroSalida;

    ficheroSalida.open ("Jugadores.txt",ios::trunc);
    ficheroSalida.close();

    ficheroSalida.open ("Jugadores.txt",ios::app);
    for (int i=0; i<32; i++){
        for (int u=0;u<23;u++){
          id++;
          ficheroSalida <<id<<";"<<"Equipo"<<i+1<< "JugadorNumero"<<u+1<<";"<<0<< ";"<<i+1 <<"\n";

     }
   }

    ficheroSalida.close();

}
void cargarPartidos(){
ListaPartido listaPartido;
crearListaPartido(listaPartido);
Partido partido;
crearPartido(partido);
ifstream archivo("partidos.txt");
int aux;
string linea;
if(archivo.is_open()){
    while(!archivo.eof()){
        getline(archivo,linea,';');
        stringstream id(linea);
        id>>aux;
        setId(partido,aux);
        getline(archivo,linea,';');
        stringstream el(linea);
        el>>aux;
        setIdEquipoL(partido,aux);
        getline(archivo,linea,';');
        stringstream ev(linea);
        ev>>aux;
        setIdEquipoV(partido,aux);
        getline(archivo,linea,';');
        stringstream gl(linea);
        gl>>aux;
        setGolesL(partido,aux);
        getline(archivo,linea);
        stringstream gv(linea);
        gv>>aux;
        setGolesV(partido,aux);
        adicionarFinal(listaPartido,partido);


    }
    archivo.seekg(0);
}
archivo.close();
}
void cargarJugadores(Equipo &equipo){
ListaJugador listaJugador;
crearListaJugador(listaJugador);
Jugador jugador;
crearJugador(jugador);
ifstream archivoJugadores("jugadores.txt");
int aux=0;
string linea;
int idEquipo=0;
idEquipo=getId(equipo);
cout<<idEquipo<<endl;
if(archivoJugadores.is_open()){

        while(!archivoJugadores.eof()){
        getline(archivoJugadores,linea,';');
        stringstream id(linea);
        id>>aux;
        setId(jugador,aux);

        getline(archivoJugadores,linea,';');
        setNombre(jugador,linea);

        getline(archivoJugadores,linea,';');
        stringstream goles(linea);
        goles>>aux;
        setGoles(jugador,aux);

        getline(archivoJugadores,linea);
        stringstream idE(linea);
        idE>>aux;
        setIdEquipo(jugador,aux);
        if(aux==idEquipo){
        adicionarFinal(equipo.listaJugadores,jugador);}

        }



archivoJugadores.seekg(0);

}
archivoJugadores.close();


}
void imprimirListaJugadores(ListaJugador  &lista){
    PtrNodoListaJugador cursor = primeroJugador(lista);
    Jugador jugador;

    while (cursor != finJugador()) {
        obtenerDato(lista, jugador, cursor);
        cout << jugador.nombre << endl;
        cursor = siguienteJugador(lista, cursor);
    }

    cout << endl;
}

