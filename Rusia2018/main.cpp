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
Equipo validarEquipoEncontrado(ListaEquipo listaEquipo, Equipo equipo);
PtrNodoPartido validarPartidoEncontrado (ListaPartido listaPartido, Partido partido);
ListaEquipo cargarEquipos();
ListaGrupo cargarGrupos();
ListaPartido cargarPartidos();
void cargarJugadores(Equipo &equipo);
void imprimirListaJugadores(ListaJugador  &lista);
void imprimirListaPartidos(ListaPartido  &lista);
PtrNodoListaJugador traerJugador(ListaEquipo lista,int idEquipo,int idJugador);
PtrNodoListaJugador traerJugador(ListaJugador listaJugador,int idJugador);
PtrNodoListaEquipo traerEquipo(ListaEquipo listaEquipo,int idEquipo);
PtrNodoPartido traerNodoPartido(ListaPartido listaPartido,int idPartido);
PtrNodoGrupo traerGrupo(ListaGrupo listaGrupo,char idGrupo);
void guardarDatos(ListaEquipo listaEquipo,ListaGrupo listaGrupo,ListaPartido listaPartido);
void calcularOctavos(ListaEquipo listaEquipo,ListaGrupo listaGrupo,ListaPartido &listaPartido);
PtrNodoListaEquipo primero(Grupo grupo,ListaEquipo listaEquipo);
PtrNodoListaEquipo segundo(Grupo grupo,ListaEquipo listaEquipo);
void calcularCuartos(ListaPartido &listaPartido);
int traerIdGanador(PtrNodoPartido ptrNodoPartido);
void calcularSemi(ListaPartido &listaPartido);
void calcularFinal(ListaPartido &listaPartido);
bool partidosActivos(ListaPartido &listaPartido);
void registrarInicio(ListaPartido &listaPartido, ListaPartido &listaAux);
void registrarGoles(ListaPartido &listaPartido, ListaEquipo &listaEquipo);
void registrarFindePartido(ListaPartido &listaPartido,ListaEquipo &listaEquipo,ListaGrupo &listaGrupo,ListaPartido &listaAux);
void ordenDeEquipos(ListaGrupo &listaGrupo,ListaEquipo &listaEquipo);
int main()
{

    int menu=0;
    int submenu2=0,submenu3=0;
    //bateriaJugadores();
    ListaEquipo listaEquipo=cargarEquipos();
    ListaGrupo listaGrupo=cargarGrupos();
    ListaPartido listaPartido;
    crearListaPartido(listaPartido);
    listaPartido=cargarPartidos();
    PtrNodoPartido ptrCursor;
    //Equipo equipoAuxiliar;
    ListaPartido listaAux;
    crearListaPartido(listaAux);


    while(menu!=3){
     cout<<"1_Administrar partidos"<<endl;
     cout<<"2_Procesar reportes"<<endl;
     cout<<"3_Guardar y salir"<<endl;

     cin>>menu;
    if(menu==3){
            if(partidosActivos(listaAux)==true){       //busco en la lista de partidos iniciados si hay alguno sin finalizar//
        while(menu!=1){
        cout<<"Hay partidos sin finalizar."<<endl;
        cout<<"1_Administrar partidos"<<endl;
        cin>>menu;}
        }
    }
     switch(menu){

     case 1: //administrar partidos
            submenu2=0;
            while(submenu2!=4){
                 cout<<"1-Registrar inicio de partidos"<<endl;
                 cout<<"2_Registrar goles ocurridos en cada partido"<<endl;
                 cout<<"3_Registrar fin de un partido"<<endl;
                 cout<<"4_Atras"<<endl;
                 cin>>submenu2;

                 switch(submenu2){

             case 1:{ registrarInicio(listaPartido, listaAux);
                     }
                     break;


             case 2:{registrarGoles(listaPartido, listaEquipo);
                     }
                     break;



             case 3:{registrarFindePartido(listaPartido,listaEquipo,listaGrupo,listaAux);
                     }
                     break;

             case 4:break;
                 }
                 }
                  break;
    case 2: //reportes
             submenu3=0;
            while(submenu3!=3){
                 cout<<"1_Orden de equipos por Grupo"<<endl;
                 cout<<"2_Grupo de la muerte"<<endl;
                 cout<<"3_Atras"<<endl;
                 cin>>submenu3;

                 switch(submenu3){

             case 1:{ordenDeEquipos(listaGrupo,listaEquipo);
                    }
                    break;


                    //grupo de la muerte
             case 2:{

                 int cantidadGrupos=0;
                    int golesParciales=0;
                    int golesParcialesMuerte=9999;
                    string grupoMuerteNombre;

                    PtrNodoGrupo cursor = primeroListaGrupo(listaGrupo);
                    Grupo grupoAux;
                    while (cursor != finGrupo()) {
                    obtenerDato(listaGrupo, grupoAux, cursor);

                    cantidadGrupos=cantidadGrupos+1;
                    golesParciales=traerEquipo(listaEquipo,grupoAux.idEquipo1)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo2)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo3)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo4)->equipo.golesAFavor;

                    if(golesParcialesMuerte==9999){
                        golesParcialesMuerte=golesParciales;
                        grupoMuerteNombre=grupoAux.nombre;
                    }
                    if(golesParcialesMuerte>=golesParciales){
                        golesParcialesMuerte=golesParcialesMuerte;
                        grupoMuerteNombre=grupoMuerteNombre;
                    }
                    if(golesParcialesMuerte<golesParciales){
                        golesParcialesMuerte=golesParciales;
                        grupoMuerteNombre=grupoAux.nombre;
                    }

                    cursor = siguienteListaGrupo(listaGrupo, cursor);
                     if(cantidadGrupos==8){
                        cursor=finGrupo();
                    }
                    }
                    cout<< "GRUPO MUERTE:"<<grupoMuerteNombre<<endl;
                    cout<< "GOLES PARCIALES MUERTE:"<<golesParcialesMuerte<<endl;
                    cout << endl;






             }break;




             case 3:break;



                 }
                 }
                  break;


     case 3:
                     /*calcularOctavos(listaEquipo,listaGrupo,listaPartido);
                     calcularCuartos(listaPartido);
                     calcularSemi(listaPartido);
                     calcularFinal(listaPartido);*/

            guardarDatos(listaEquipo,listaGrupo,listaPartido);
            exit(1);
        break;

     case 4:
        bateriaJugadores();
        break;
     }
    }
    return 0;
}

ListaEquipo cargarEquipos(){
ListaEquipo listaEquipo;
crearListaEquipo(listaEquipo);
Equipo equipo;
crearEquipo(equipo);
ifstream archivo("equipos.txt"); // abrir el archivo en modo lectura//
int aux=0;
string linea;
bool fallos=false;
if(archivo.is_open()){
    while(!archivo.eof()){        //mientras no sea el fin de archivo//
            getline(archivo,linea,';'); // leo desde el comienzo has ";" y lo guardo en linea//
            stringstream id(linea);  //Cargo en el stream "id", lo que esta en linea;
            id>>aux;                  // lo paso a aux;
              if(traerEquipo(listaEquipo,aux)!=finEquipo()){
           cout<<"Informe de errores: Equipos"<<endl;
           cout<<"El id"<< aux<< "ya esta cargado"<<endl;
              fallos=true;
        }
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
            cargarJugadores(equipo);
            adicionarFinal(listaEquipo,equipo);
            destructor(equipo);

         }
        archivo.seekg(0); //Me posiciono al principio del archivo
}
archivo.close();
if(fallos)
   exit(1);
return listaEquipo;
}

ListaGrupo cargarGrupos(){
ListaGrupo listaGrupo;
crearListaGrupo(listaGrupo);
Grupo grupo;
crearGrupo(grupo);
ifstream archivo("grupos.txt");
int aux=0;
char aux1;
string linea;
bool fallos=false;
if(archivo.is_open()){

    while(!archivo.eof()){
         getline(archivo,linea,';');
         aux1=linea[0];
          if(traerGrupo(listaGrupo,aux1)!=finGrupo()){
           cout<<"Informe de errores: Grupos"<<endl;
           cout<<"El id"<< aux1<< "ya esta cargado"<<endl;
              fallos=true;
        }
         setId(grupo,aux1);
         getline(archivo,linea,';');
         setNombre(grupo,linea);
         getline(archivo,linea,';');
         stringstream id1(linea);
         id1>>aux;
         if (aux <0 || aux> 32 ){
             cout<< "Equipo inexistente"<<aux<<endl;
         }
         setIdEquipo1(grupo,aux);
         getline(archivo,linea,';');
         stringstream id2(linea);
         id2>>aux;
         if (aux <0 || aux> 32 ){
             cout<< "Equipo inexistente"<<aux<<endl;
         }
         setIdEquipo2(grupo,aux);
         getline(archivo,linea,';');
         stringstream id3(linea);
         id3>>aux;
         if (aux <0 || aux> 32 ){
             cout<< "Equipo inexistente"<<aux<<endl;
         }
         setIdEquipo3(grupo,aux);
         getline(archivo,linea);
         stringstream id4(linea);
         id4>>aux;
         if (aux <0 || aux> 32 ){
            cout<< "Equipo inexistente"<<aux<<endl;
         }

         setIdEquipo4(grupo,aux);

         adicionarFinal(listaGrupo,grupo);


     }
      archivo.seekg(0); //Me posiciono al principio del archivo
}
archivo.close();
if(fallos)
    exit(1);
return listaGrupo;
}

void bateriaJugadores(){//bateria  de jugadores carga  todo en 0
    int id =0;
    ofstream ficheroSalida;

    ficheroSalida.open ("jugadores.txt",ios::trunc);
    ficheroSalida.close();

    ficheroSalida.open ("jugadores.txt",ios::app);
    for (int i=0; i<32; i++){
        for (int u=0;u<23;u++){
          id++;
          ficheroSalida <<id<<";"<<"Equipo"<<i+1<< "JugadorNumero"<<u+1<<";"<<0<< ";"<<i+1 <<"\n";
          //cout <<id<<";"<<"Equipo"<<i+1<< "JugadorNumero"<<u+1<<";"<<0<< ";"<<i+1 <<"\n";
     }
   }

    ficheroSalida.close();

}
ListaPartido cargarPartidos(){//Levanta los partidos de los  txt y los pone en una lista
ListaPartido listaPartido;

crearListaPartido(listaPartido);
Partido partido;
crearPartido(partido);
ifstream archivo("partidos.txt");
int aux;
string linea;
bool fallos=false;
if(archivo.is_open()){
    while(!archivo.eof()){
        getline(archivo,linea,';');
        stringstream id(linea);
        id>>aux;
        if(traerNodoPartido(listaPartido,aux)!=finListaPartido()){
           cout<<"Informe de errores: Partidos"<<endl;
           cout<<"El id"<< aux<< "ya esta cargado"<<endl;
              fallos=true;
        }
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
if(fallos)
    exit(1);

return listaPartido;
}

void cargarJugadores(Equipo &equipo){
ListaJugador listaJugador;
crearListaJugador(listaJugador);
Jugador jugador;
crearJugador(jugador);
ifstream archivoJugadores("jugadores.txt");
int aux=0;
string linea;
bool fallos=false;
int idEquipo=0;
idEquipo=getId(equipo);
if(archivoJugadores.is_open()){

        while(!archivoJugadores.eof()){
        getline(archivoJugadores,linea,';');
        stringstream id(linea);
        id>>aux;
        if(traerJugador(listaJugador,aux)!=finJugador()){
           cout<<"Informe de errores: Jugadores"<<endl;
           cout<<"El id "<< aux<< " ya esta cargado"<<endl;
              fallos=true;
        }
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
        if (aux >32 || aux <1){
            cout<<"Informe de errores: Jugadores"<<endl;
            cout<<"El id "<< aux<< " no corresponde a ningun equipo enlistado"<<endl;
            fallos=true;
        }
        setIdEquipo(jugador,aux);
        if(aux==idEquipo){
            adicionarFinal(equipo.listaJugadores,jugador);
            adicionarFinal(listaJugador,jugador);}

        }



archivoJugadores.seekg(0);

}
archivoJugadores.close();
//if(fallos)
    //exit(1);

}
void imprimirListaJugadores(ListaJugador  &lista){
    PtrNodoListaJugador cursor = primeroJugador(lista);
    Jugador jugador;

    while (cursor != finJugador()) {
        obtenerDato(lista, jugador, cursor);
        if(jugador.goles>0){
        cout << jugador.nombre << endl;
        cout<<jugador.goles<<endl;}
        cursor = siguienteJugador(lista, cursor);
    }

    cout << endl;
}
void imprimirListaPartidos(ListaPartido  &lista){
    PtrNodoPartido cursor = primeroPartido(lista);
    Partido partido;
    cout<<"probando"<<endl;
    while (cursor != finListaPartido()) {
        obtenerDato(lista, partido, cursor);
        cout << partido.id << endl;
        cout << partido.idEquipoL << endl;
        cout <<"-----"<<endl;
        cursor = siguientePartido(lista, cursor);
    }

    cout << endl;
}
PtrNodoListaJugador traerJugador(ListaEquipo lista,int idEquipo,int idJugador){

PtrNodoListaEquipo ptrNodo=traerEquipo(lista,idEquipo);
Jugador jugador;
crearJugador(jugador);
setId(jugador,idJugador);
PtrNodoListaJugador ptrNodoJugador = localizarDato(ptrNodo->equipo.listaJugadores,jugador);

return ptrNodoJugador;
}

PtrNodoListaEquipo traerEquipo(ListaEquipo listaEquipo,int idEquipo){
Equipo equipo;
crearEquipo(equipo);
setId(equipo,idEquipo);
PtrNodoListaEquipo ptrNodo= localizarDato(listaEquipo,equipo);

return ptrNodo;
}
PtrNodoPartido traerNodoPartido(ListaPartido listaPartido,int idPartido){
Partido partido;
crearPartido(partido);
setId(partido,idPartido);
PtrNodoPartido ptrNodo = localizarDato(listaPartido,partido);

return ptrNodo;
}


PtrNodoGrupo traerGrupo(ListaGrupo listaGrupo,char idGrupo){
Grupo grupo;
crearGrupo(grupo);
setId(grupo,idGrupo);
PtrNodoGrupo ptrNodo = localizarDato(listaGrupo,grupo);
return ptrNodo;
}


void guardarDatos(ListaEquipo listaEquipo,ListaGrupo listaGrupo,ListaPartido listaPartido){
ofstream archivoP("partidos.txt");
PtrNodoPartido ptrNodo= primeroPartido(listaPartido);
Partido partido;
int indice=0;
if(archivoP.is_open()){
    while(ptrNodo!=finListaPartido() && indice!=64){
        indice++;
        obtenerDato(listaPartido,partido,ptrNodo);
        archivoP<<partido.id;
        archivoP<<";";
        archivoP<<partido.idEquipoL;
        archivoP<<";";
        archivoP<<partido.idEquipoV;
        archivoP<<";";
        archivoP<<partido.golesL;
        archivoP<<";";
        archivoP<<partido.golesV;
        if(ptrNodo->siguiente!=finListaPartido())
        archivoP<<endl;

        ptrNodo=siguientePartido(listaPartido,ptrNodo);


    }
    }
indice=0;
archivoP.close();
ofstream archivoG("grupos.txt");
PtrNodoGrupo ptrNodoGrupo=primeroListaGrupo(listaGrupo);
Grupo grupo;

if(archivoG.is_open()){
    while(ptrNodoGrupo!=finGrupo() && indice!=8){
        indice++;
        obtenerDato(listaGrupo,grupo,ptrNodoGrupo);
        archivoG<<ptrNodoGrupo->grupo.id;
        archivoG<<";";
        archivoG<<ptrNodoGrupo->grupo.nombre;
        archivoG<<";";
        archivoG<<ptrNodoGrupo->grupo.idEquipo1;
        archivoG<<";";
        archivoG<<ptrNodoGrupo->grupo.idEquipo2;
        archivoG<<";";
        archivoG<<ptrNodoGrupo->grupo.idEquipo3;
        archivoG<<";";
        archivoG<<ptrNodoGrupo->grupo.idEquipo4;
        if(ptrNodoGrupo->siguiente != finGrupo())
        archivoG<<endl;

        ptrNodoGrupo=siguienteListaGrupo(listaGrupo,ptrNodoGrupo);

    }

}
indice=0;
archivoG.close();
ofstream archivoE("equipos.txt");
PtrNodoListaEquipo ptrNodoEquipo = primeroEquipo(listaEquipo);
Equipo equipo;
ofstream archivoJ("jugadores.txt");
Jugador jugador;
if(archivoE.is_open() && archivoJ.is_open()){
    while(ptrNodoEquipo!=finEquipo()){
        archivoE<<ptrNodoEquipo->equipo.id;
        archivoE<<";";
        archivoE<<ptrNodoEquipo->equipo.nombre;
        archivoE<<";";
        archivoE<<ptrNodoEquipo->equipo.golesAFavor;
        archivoE<<";";
        archivoE<<ptrNodoEquipo->equipo.golesEnContra;
        archivoE<<";";
        archivoE<<ptrNodoEquipo->equipo.puntos;
        PtrNodoListaJugador ptrNodoJugador=primeroJugador(ptrNodoEquipo->equipo.listaJugadores);
        while(ptrNodoJugador!=finJugador() && indice!=736){
            indice++;
            archivoJ<<ptrNodoJugador->jugador.id;
            archivoJ<<";";
            archivoJ<<ptrNodoJugador->jugador.nombre;
            archivoJ<<";";
            archivoJ<<ptrNodoJugador->jugador.goles;
            archivoJ<<";";
            archivoJ<<ptrNodoJugador->jugador.idEquipo;
            if(indice!=736)
            archivoJ<<endl;

            ptrNodoJugador=siguienteJugador(ptrNodoEquipo->equipo.listaJugadores,ptrNodoJugador);

        }
        if(ptrNodoEquipo->siguiente!=finEquipo()){
        archivoE<<endl;}
        ptrNodoEquipo=siguienteEquipo(listaEquipo,ptrNodoEquipo);
    }
}
indice=0;
archivoJ.close();
archivoE.close();

cout<<"datos guardados"<<endl;
}
PtrNodoListaJugador traerJugador(ListaJugador listaJugador,int idJugador){
PtrNodoListaJugador ptrNodoJugador= primeroJugador(listaJugador);
Jugador jugador;
crearJugador(jugador);
setId(jugador,idJugador);
ptrNodoJugador=localizarDato(listaJugador,jugador);

return ptrNodoJugador;

}
void calcularOctavos(ListaEquipo listaEquipo,ListaGrupo listaGrupo,ListaPartido &listaPartido){
PtrNodoGrupo ptrNodoGrupoA=traerGrupo(listaGrupo,'A');
PtrNodoGrupo ptrNodoGrupoB=traerGrupo(listaGrupo,'B');
PtrNodoGrupo ptrNodoGrupoC=traerGrupo(listaGrupo,'C');
PtrNodoGrupo ptrNodoGrupoD=traerGrupo(listaGrupo,'D');
PtrNodoGrupo ptrNodoGrupoE=traerGrupo(listaGrupo,'E');
PtrNodoGrupo ptrNodoGrupoF=traerGrupo(listaGrupo,'F');
PtrNodoGrupo ptrNodoGrupoG=traerGrupo(listaGrupo,'G');
PtrNodoGrupo ptrNodoGrupoH=traerGrupo(listaGrupo,'H');


PtrNodoListaEquipo ptrPrimeroGA=primero(ptrNodoGrupoA->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGA=segundo(ptrNodoGrupoA->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGB=primero(ptrNodoGrupoB->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGB=segundo(ptrNodoGrupoB->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGC=primero(ptrNodoGrupoC->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGC=segundo(ptrNodoGrupoC->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGD=primero(ptrNodoGrupoD->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGD=segundo(ptrNodoGrupoD->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGE=primero(ptrNodoGrupoE->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGE=segundo(ptrNodoGrupoE->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGF=primero(ptrNodoGrupoF->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGF=segundo(ptrNodoGrupoF->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGG=primero(ptrNodoGrupoG->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGG=segundo(ptrNodoGrupoG->grupo,listaEquipo);

PtrNodoListaEquipo ptrPrimeroGH=primero(ptrNodoGrupoH->grupo,listaEquipo);
PtrNodoListaEquipo ptrSegundoGH=segundo(ptrNodoGrupoH->grupo,listaEquipo);

PtrNodoPartido ptrPartido= traerNodoPartido(listaPartido,49);
if(ptrPartido==finListaPartido()){

         Partido partido;
         crearPartido(partido);
         setId(partido,49);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}

ptrPartido->partido.idEquipoL=ptrPrimeroGA->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGB->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,50);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,50);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGC->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGD->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,51);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,51);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGB->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGA->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,52);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,52);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGD->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGC->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,53);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,53);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGE->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGF->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,54);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,54);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGG->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGH->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,55);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,55);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGF->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGE->equipo.id;

ptrPartido=traerNodoPartido(listaPartido,56);
if(ptrPartido==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,56);
         ptrPartido=crearNodoListaPartido(partido);
         ptrPartido->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrPartido->partido.idEquipoL=ptrPrimeroGH->equipo.id;
ptrPartido->partido.idEquipoV=ptrSegundoGG->equipo.id;



}

PtrNodoListaEquipo primero(Grupo grupo,ListaEquipo listaEquipo){
PtrNodoListaEquipo nodo1= traerEquipo(listaEquipo,grupo.idEquipo1);
PtrNodoListaEquipo nodo2= traerEquipo(listaEquipo,grupo.idEquipo2);
PtrNodoListaEquipo nodo3= traerEquipo(listaEquipo,grupo.idEquipo3);
PtrNodoListaEquipo nodo4= traerEquipo(listaEquipo,grupo.idEquipo4);
PtrNodoListaEquipo primero=finEquipo();
ListaEquipo nuevaLista;
crearListaEquipo(nuevaLista);
adicionarAlPrincipio(nuevaLista,nodo1->equipo);
adicionarAlPrincipio(nuevaLista,nodo2->equipo);
adicionarAlPrincipio(nuevaLista,nodo3->equipo);
adicionarAlPrincipio(nuevaLista,nodo4->equipo);
reordenar(nuevaLista);
primero=primeroEquipo(nuevaLista);

return primero;

}

PtrNodoListaEquipo segundo(Grupo grupo,ListaEquipo listaEquipo){
PtrNodoListaEquipo nodo1= traerEquipo(listaEquipo,grupo.idEquipo1);
PtrNodoListaEquipo nodo2= traerEquipo(listaEquipo,grupo.idEquipo2);
PtrNodoListaEquipo nodo3= traerEquipo(listaEquipo,grupo.idEquipo3);
PtrNodoListaEquipo nodo4= traerEquipo(listaEquipo,grupo.idEquipo4);
PtrNodoListaEquipo segundo=finEquipo();
ListaEquipo nuevaLista;
crearListaEquipo(nuevaLista);
adicionarAlPrincipio(nuevaLista,nodo1->equipo);
adicionarAlPrincipio(nuevaLista,nodo2->equipo);
adicionarAlPrincipio(nuevaLista,nodo3->equipo);
adicionarAlPrincipio(nuevaLista,nodo4->equipo);
reordenar(nuevaLista);
segundo=primeroEquipo(nuevaLista)->siguiente;
return segundo;
}

void calcularCuartos(ListaPartido &listaPartido){
int idL=0,idV=0;
PtrNodoPartido ptrNodoPartido=traerNodoPartido(listaPartido,49);
idL=traerIdGanador(ptrNodoPartido);
PtrNodoPartido ptrNodoPart=traerNodoPartido(listaPartido,50);
idV=traerIdGanador(ptrNodoPart);
PtrNodoPartido ptrProximo = traerNodoPartido(listaPartido,57);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,57);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}

ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;

ptrNodoPartido=traerNodoPartido(listaPartido,53);
idL=traerIdGanador(ptrNodoPartido);
ptrNodoPart=traerNodoPartido(listaPartido,54);
idV=traerIdGanador(ptrNodoPart);
ptrProximo=traerNodoPartido(listaPartido,58);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,58);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;

ptrNodoPartido=traerNodoPartido(listaPartido,51);
idL=traerIdGanador(ptrNodoPartido);
ptrNodoPart=traerNodoPartido(listaPartido,52);
idV=traerIdGanador(ptrNodoPart);
ptrProximo=traerNodoPartido(listaPartido,59);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,59);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;

ptrNodoPartido=traerNodoPartido(listaPartido,55);
idL=traerIdGanador(ptrNodoPartido);
ptrNodoPart=traerNodoPartido(listaPartido,56);
idV=traerIdGanador(ptrNodoPart);
ptrProximo=traerNodoPartido(listaPartido,60);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,60);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;


}
int traerIdGanador(PtrNodoPartido ptrNodoPartido){
    int idGanador=-1;
    if(ptrNodoPartido->partido.golesL>-1 && ptrNodoPartido->partido.golesV>-1 ){

    if(ptrNodoPartido->partido.golesL > ptrNodoPartido->partido.golesV){
       idGanador=ptrNodoPartido->partido.idEquipoL;
    }
    else{
        idGanador=ptrNodoPartido->partido.idEquipoV;
    }
    }

    return idGanador;

}
void calcularSemi(ListaPartido &listaPartido){
int idL=0,idV=0;
PtrNodoPartido ptrNodoPartido=traerNodoPartido(listaPartido,57);
idL=traerIdGanador(ptrNodoPartido);
PtrNodoPartido ptrNodoPart=traerNodoPartido(listaPartido,58);
idV=traerIdGanador(ptrNodoPart);
PtrNodoPartido ptrProximo=traerNodoPartido(listaPartido,61);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,61);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;

ptrNodoPartido=traerNodoPartido(listaPartido,59);
idL=traerIdGanador(ptrNodoPartido);
ptrNodoPart=traerNodoPartido(listaPartido,60);
idV=traerIdGanador(ptrNodoPart);
ptrProximo=traerNodoPartido(listaPartido,62);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,62);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;



}

void calcularFinal(ListaPartido &listaPartido){
int idL=0,idV=0;
PtrNodoPartido ptrNodoPartido=traerNodoPartido(listaPartido,61);
idL=traerIdGanador(ptrNodoPartido);

PtrNodoPartido ptrNodoPart = traerNodoPartido(listaPartido,62);
idV=traerIdGanador(ptrNodoPart);

PtrNodoPartido ptrProximo=traerNodoPartido(listaPartido,64);
if(ptrProximo==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,64);
         ptrProximo=crearNodoListaPartido(partido);
         ptrProximo->partido=partido;
         adicionarFinal(listaPartido,partido);

}
ptrProximo->partido.idEquipoL=idL;
ptrProximo->partido.idEquipoV=idV;
PtrNodoPartido ptrTercerPuesto=traerNodoPartido(listaPartido,63);
if(ptrTercerPuesto==finListaPartido()){
         Partido partido;
         crearPartido(partido);
         setId(partido,63);
         ptrTercerPuesto=crearNodoListaPartido(partido);
         ptrTercerPuesto->partido=partido;
         adicionarFinal(listaPartido,partido);

}

if(ptrNodoPartido->partido.idEquipoL==idL){
    ptrTercerPuesto->partido.idEquipoL=ptrNodoPartido->partido.idEquipoV;
}
else {
        ptrTercerPuesto->partido.idEquipoL=ptrNodoPartido->partido.idEquipoL;
   }
if(ptrNodoPart->partido.idEquipoV==idV){
    ptrTercerPuesto->partido.idEquipoV=ptrNodoPart->partido.idEquipoL;
}
else{
    ptrTercerPuesto->partido.idEquipoV=ptrNodoPart->partido.idEquipoV;

}


}

PtrNodoPartido validarPartidoEncontrado (ListaPartido listaPartido, Partido partido){
    bool encontrado = false;
    int auxId;
    auxId = partido.id;
    PtrNodoPartido ptrPartidoAux;

    while(encontrado==false){

        if( localizarDato(listaPartido,partido)==finListaPartido()){
            cout<<"Informe de errores: Adminitrar Partido"<<endl;
            cout<<"El id: |"<< auxId<< "|no existe en la lista de partidos enlistados"<<endl;
            cout<<"Reintente por favor"<<endl;
            cout<<"Ingrese id del partido a iniciar"<<endl;
            cin>>auxId;
            partido.id= auxId;
            if( localizarDato(listaPartido,partido)!=finListaPartido())
                ptrPartidoAux = localizarDato(listaPartido,partido);
                encontrado = true;

            }
    }
    return ptrPartidoAux;
}

Equipo validarEquipoEncontrado(ListaEquipo listaEquipo, Equipo equipo){
    bool encontrado = false;
    int auxId;
    while (encontrado == false){
         if( localizarDato(listaEquipo,equipo)==finEquipo()){
            cout<<"Informe de errores: Adminitrar Partido"<<endl;
            cout<<"El id: |"<< auxId<< "|no existe en la lista de equipos enlistados"<<endl;
            cout<<"Reintente por favor ingresar el id"<<endl;

            cin>>auxId;
            equipo.id= auxId;
            if( localizarDato(listaEquipo,equipo)!= finEquipo())
                encontrado = true;

            }else {encontrado = true;}
    }
    return equipo;
}
bool partidosActivos(ListaPartido &listaPartido){
PtrNodoPartido ptrPartido=primeroPartido(listaPartido);
PtrNodoPartido ptrCursor = primeroPartido(listaPartido);
bool encontrado=false;
while(ptrCursor!=finListaPartido() && !encontrado){

    if(ptrPartido->partido.golesL>=0 && ptrPartido->partido.golesV>=0){
        if(ptrPartido->partido.finalizado==false){
                encontrado=true;
        }
    }

    ptrPartido=siguientePartido(listaPartido,ptrPartido);
    ptrCursor=ptrPartido;
   // ptrPartido=ptrCursor;
}
return encontrado;
}
void registrarInicio(ListaPartido &listaPartido, ListaPartido &listaAux){
bool partidoIniciado=false;
                    int auxId=999;
                    cout<<"Ingrese id del partido a iniciar"<<endl;
                    cin>>auxId;
                    Partido partidoAux ;
                    partidoAux.id= auxId;
                    PtrNodoPartido ptrCursorAux;


                    // comprobar q exista partido
                    if( localizarDato(listaPartido,partidoAux)==finListaPartido())
                      ptrCursorAux=validarPartidoEncontrado(listaPartido,partidoAux);// comprobar q exista partido

                    ptrCursorAux=localizarDato(listaPartido,partidoAux);



                    if (ptrCursorAux->partido.golesV!=-1 && ptrCursorAux->partido.golesL!=-1){
                        while (partidoIniciado==false){
                            cout<<"El partido esta iniciado"<<endl;
                            cout<<"Ingrese id del partido a iniciar (Ingreesar 0 para salir)"<<endl;
                            cin>>auxId;
                            if (auxId==0){
                                break;
                            }
                            partidoAux.id=auxId;
                            cout<<auxId<<endl;
                            if( localizarDato(listaPartido,partidoAux)==finListaPartido()){
                                ptrCursorAux=validarPartidoEncontrado(listaPartido,partidoAux);
                            }else{ptrCursorAux=localizarDato(listaPartido,partidoAux);}


                            if (ptrCursorAux->partido.golesV==-1 && ptrCursorAux->partido.golesL==-1){
                                partidoIniciado=true;
                            }
                        }
                    }
                    if(auxId!=0){
                        cout<<"Comenzo el partido con id: "<<ptrCursorAux->partido.id<<endl;
                        if(auxId<49){
                        //----------TEST---
                        //cout<< "id del equipo  traigo"<<ptrCursorAux->partido.idEquipoL<<endl;
                       // PtrNodoListaEquipo ptrNodoEquipoAux;
                        //ptrNodoEquipoAux=traerEquipo(listaEquipo, 1);
                        //cout<<"Nombre equipo"<<ptrNodoEquipoAux->equipo.nombre<<endl;
                        //----------TEST---

                        ptrCursorAux->partido.golesL =  0;
                        ptrCursorAux->partido.golesV = 0;
                        adicionarFinal(listaAux,ptrCursorAux->partido);        // agrego los partidos inicados a la lista//
                        }
                        else{
                            ptrCursorAux->partido.golesL =  0;// Para q esta esto???
                            ptrCursorAux->partido.golesV = 0;
                            adicionarFinal(listaAux,ptrCursorAux->partido);         // agrego los partidos inicados a la lista//
                        }
                        }

}
void registrarGoles(ListaPartido &listaPartido, ListaEquipo &listaEquipo){
                int auxId=9999;
                int idJugador=0;
                bool partidoIniciado=false;

                PtrNodoPartido ptrCursor;
                Partido partidoAux;



               while (auxId != 0){
                cout<<"ingrese id del partido a cargar los goles(Ingresar 0 para salir)"<<endl;
                cin>>auxId;
                partidoAux.id=auxId;
                if(auxId==0){
                    break;
                }

                if( localizarDato(listaPartido,partidoAux)==finListaPartido()){
                    ptrCursor=validarPartidoEncontrado(listaPartido,partidoAux);
                }else{ptrCursor=localizarDato(listaPartido,partidoAux);}

                cout<<"Id partido"<<ptrCursor->partido.id<<endl;


                // esto valida q el partido este iniciado
                if (ptrCursor->partido.golesV==-1 && ptrCursor->partido.golesL==-1){
                    while (partidoIniciado==false){
                        cout<<"El partido no esta iniciado"<<endl;
                        cout<<"Ingrese id del partido a cargar los goles (Ingreesar 0 para salir)"<<endl;
                        cin>>auxId;
                        if (auxId==0){
                            break;
                        }
                        partidoAux.id=auxId;
                        cout<<auxId<<endl;
                        if( localizarDato(listaPartido,partidoAux)==finListaPartido()){
                            ptrCursor=validarPartidoEncontrado(listaPartido,partidoAux);
                        }else{ptrCursor=localizarDato(listaPartido,partidoAux);}


                        if (ptrCursor->partido.golesV!=-1 && ptrCursor->partido.golesL!=-1){
                            partidoIniciado=true;
                        }
                    }
                }



                if(auxId!=0){

                    cout<<"Ingrese id del jugador que hizo el gol:"<<endl;
                    cin>>idJugador;
                    PtrNodoListaJugador ptrANodoJugador = traerJugador(listaEquipo,ptrCursor->partido.idEquipoL,idJugador);

                    if (ptrANodoJugador ==  NULL){
                        ptrANodoJugador = traerJugador(listaEquipo,ptrCursor->partido.idEquipoV,idJugador);

                    }

                   if(ptrANodoJugador == NULL){
                        cout<< "El jugador no pertenece a los equipos q estan jugando"<<endl;//Hay q  hacer  un validador de jugadores
                    }


                    if (ptrANodoJugador->jugador.idEquipo==ptrCursor->partido.idEquipoL){
                        //Asigno gol a  local
                        ptrCursor->partido.golesL =ptrCursor->partido.golesL+1;
                        ptrANodoJugador->jugador.goles=ptrANodoJugador->jugador.goles+1;
                    }else{//Asigno gol a visitante
                            ptrCursor->partido.golesV =ptrCursor->partido.golesV+1;
                            ptrANodoJugador->jugador.goles=ptrANodoJugador->jugador.goles+1;
                        }

                    cout<<"Goles local: |"<<ptrCursor->partido.golesL<<"|"<<endl;
                    cout<<"Goles Vistinate: |"<<ptrCursor->partido.golesV<<"|"<<endl;
                    cout<<"Goles echos por el jugador: |"<<ptrANodoJugador->jugador.goles<<"|"<<endl;



                }


               }
}
void registrarFindePartido(ListaPartido &listaPartido,ListaEquipo &listaEquipo,ListaGrupo &listaGrupo,ListaPartido &listaAux){
                     PtrNodoPartido auxPartido;
                     int id=0;


                     cout<<"Ingrese id del partido a finalizar"<<endl;
                     cin>>id;
                     cout<<"Id del partido:"<<id;
                        auxPartido->partido.id=id;
                        auxPartido= localizarDato (listaPartido,auxPartido->partido);


                      if( auxPartido->partido.golesL == -1){
                        cout<<"El partido no se ha iniciado"<<endl;
                        exit(1);
                      }

                     PtrNodoPartido ptrNodoPartido = traerNodoPartido(listaPartido,id);
                        cout<< "Datos del partido a cerrar"<< auxPartido->partido.id<<";"<<auxPartido->partido.idEquipoL<<endl;
                        //Todo Hasta aca parece estar  bien el problema parece ser a  partir de  aca

                     PtrNodoListaEquipo ptrNodoEquipoL = traerEquipo(listaEquipo,ptrNodoPartido->partido.idEquipoL);
                     PtrNodoListaEquipo ptrNodoEquipoV = traerEquipo(listaEquipo,ptrNodoPartido->partido.idEquipoV);

                     setGolesAFavor(ptrNodoEquipoL->equipo,ptrNodoEquipoL->equipo.golesAFavor+ptrNodoPartido->partido.golesL);
                     setGolesEnContra(ptrNodoEquipoL->equipo,ptrNodoEquipoL->equipo.golesEnContra+ptrNodoPartido->partido.golesV);

                     setGolesAFavor(ptrNodoEquipoV->equipo,ptrNodoEquipoV->equipo.golesAFavor+ptrNodoPartido->partido.golesV);
                     setGolesEnContra(ptrNodoEquipoV->equipo,ptrNodoEquipoV->equipo.golesEnContra+ptrNodoPartido->partido.golesL);

                     if(ptrNodoPartido->partido.golesL > ptrNodoPartido->partido.golesV ){
                        setPuntos(ptrNodoEquipoL->equipo,ptrNodoEquipoL->equipo.puntos+3);
                     }
                     else if(ptrNodoPartido->partido.golesL < ptrNodoPartido->partido.golesV){
                        setPuntos(ptrNodoEquipoV->equipo,ptrNodoEquipoV->equipo.puntos+3);
                     }
                     else{
                        setPuntos(ptrNodoEquipoL->equipo,ptrNodoEquipoL->equipo.puntos+1);
                        setPuntos(ptrNodoEquipoV->equipo,ptrNodoEquipoV->equipo.puntos+1);
                     }
                     PtrNodoPartido ptrAux=traerNodoPartido(listaAux,id);          //Busco por ID, en la lista de partidos iniciados//
                     finalizarPartido(ptrAux->partido);
                     cout<<"Datos guardados"<<endl;

                     calcularOctavos(listaEquipo,listaGrupo,listaPartido);

                     calcularCuartos(listaPartido);

                     calcularSemi(listaPartido);

                     calcularFinal(listaPartido);
}
void ordenDeEquipos(ListaGrupo &listaGrupo,ListaEquipo &listaEquipo){
                    int cantidadGrupos=0;
                    int golesParciales=0;
                    int golesTotales=0;

                    PtrNodoGrupo cursor = primeroListaGrupo(listaGrupo);
                    Grupo grupoAux;

                    while (cursor != finGrupo()) {
                    obtenerDato(listaGrupo, grupoAux, cursor);
                    cout << grupoAux.nombre<<endl;
                    cout <<traerEquipo(listaEquipo,grupoAux.idEquipo1)->equipo.nombre<<traerEquipo(listaEquipo,grupoAux.idEquipo1)->equipo.golesAFavor<<traerEquipo(listaEquipo,grupoAux.idEquipo1)->equipo.puntos<<endl;
                    cout <<traerEquipo(listaEquipo,grupoAux.idEquipo2)->equipo.nombre<<traerEquipo(listaEquipo,grupoAux.idEquipo2)->equipo.golesAFavor<<traerEquipo(listaEquipo,grupoAux.idEquipo2)->equipo.puntos<<endl;
                    cout <<traerEquipo(listaEquipo,grupoAux.idEquipo3)->equipo.nombre<<traerEquipo(listaEquipo,grupoAux.idEquipo3)->equipo.golesAFavor<<traerEquipo(listaEquipo,grupoAux.idEquipo3)->equipo.puntos<<endl;
                    cout <<traerEquipo(listaEquipo,grupoAux.idEquipo4)->equipo.nombre<<traerEquipo(listaEquipo,grupoAux.idEquipo4)->equipo.golesAFavor<<traerEquipo(listaEquipo,grupoAux.idEquipo4)->equipo.puntos<<endl;
                    cout << endl;
                    cantidadGrupos=cantidadGrupos+1;
                    golesParciales=traerEquipo(listaEquipo,grupoAux.idEquipo1)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo2)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo3)->equipo.golesAFavor+traerEquipo(listaEquipo,grupoAux.idEquipo4)->equipo.golesAFavor;
                    cout<< "Cantidad Goles Parciales:"<<golesParciales<<endl;
                    golesTotales=golesTotales+golesParciales;
                    cursor = siguienteListaGrupo(listaGrupo, cursor);
                     if(cantidadGrupos==8){
                        cursor=finGrupo();
                    }
                    }
                    cout<< "Cantidad GRUPOS:"<<cantidadGrupos<<endl;
                    cout<< "Cantidad GOLES TOTALES:"<<golesTotales<<endl;
                    cout << endl;
}
