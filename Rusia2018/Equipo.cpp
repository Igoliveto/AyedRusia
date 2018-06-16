#include "Equipo.h"
#include <cstring>
#include <string>
#include <iostream>
#include "ListaJugadores.h"
void crearEquipo(Equipo &equipo,int id, string nombre){
equipo.id=id;
equipo.nombre=nombre;
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
