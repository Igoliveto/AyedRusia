#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#ifndef NULL
#define NULL      0
#endif
#include <string>
using namespace std;
typedef struct{
int id;
string nombre;
int goles;
}Jugador;


void crearJugador(Jugador &jugador, int id, string nombre);
int getId(Jugador &jugador);
string getNombre(Jugador &jugador);
void setNombre(Jugador &jugador,string nombre);
void setId(Jugador &jugador, int id);

#endif // _JUGADOR_H_
