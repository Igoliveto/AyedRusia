#include "Jugador.h"
#include "string"

void crearJugador(Jugador &jugador, int id, string nombre){
jugador.id=id;
jugador.nombre=nombre;
jugador.goles=0;

}
int getId(Jugador &jugador){
return jugador.id;
}
string getNombre(Jugador &jugador){
return jugador.nombre;
}
void setNombre(Jugador &jugador,string nombre){
jugador.nombre=nombre;
}
void setId(Jugador &jugador, int id){
jugador.id=id;
}
