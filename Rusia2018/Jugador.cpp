#include "Jugador.h"
#ifndef NULL
#define NULL      0
#endif
#include "string"
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearJugador(Jugador &jugador){
jugador.id=0;
jugador.nombre="-";
jugador.goles=0;
}
/*----------------------------------------------------------------------------*/
int getId(Jugador &jugador){
return jugador.id;
}
/*----------------------------------------------------------------------------*/
string getNombre(Jugador &jugador){
return jugador.nombre;
}
/*----------------------------------------------------------------------------*/
int getGoles(Jugador &jugador){
return jugador.goles;
}
/*----------------------------------------------------------------------------*/
void setNombre(Jugador &jugador,string nombre){
jugador.nombre=nombre;
}
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
void setId(Jugador &jugador, int id){
jugador.id=id;
}
/*----------------------------------------------------------------------------*/
void setGoles(Jugador &jugador, int goles){
jugador.goles=goles;
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/
