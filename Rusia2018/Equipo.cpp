#include "Equipo.h"
#include <cstring>
#include <string>
#include <iostream>
#include "ListaJugadores.h"
void crearEquipo(Equipo &equipo){
equipo.id=0;
equipo.nombre="-";
equipo.golesAFavor=0;
equipo.golesEnContra=0;
equipo.puntos=0;
crearLista(equipo.listaJugadores);
}

int getId(Equipo equipo){
    return equipo.id;
}

string getNombre(Equipo equipo){
return equipo.nombre;
}

void setNombre(Equipo &equipo,string nombre){
equipo.nombre=nombre;
}

void setId(Equipo &equipo, int id){
equipo.id=id;
}

void setGolesAFavor(Equipo &equipo,int goles){
equipo.golesAFavor=goles;
}

int getGolesAFavor(Equipo equipo){
return equipo.golesAFavor;}

void setGolesEnContra(Equipo &equipo,int golesEnContra){
equipo.golesEnContra=golesEnContra;
}
int getGolesEnContra(Equipo equipo){
return equipo.golesEnContra;
}
void setPuntos(Equipo &equipo,int puntos){
equipo.puntos=puntos;
}
int getPuntos(Equipo equipo){
return equipo.puntos;
}
