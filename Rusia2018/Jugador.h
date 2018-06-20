#ifndef _JUGADOR_H_
#define _JUGADOR_H_
#ifndef NULL
#define NULL      0
#endif
#include <string>
using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
int id;
string nombre;
int goles;
}Jugador;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearJugador(Jugador &jugador);
int getId(Jugador &jugador);
string getNombre(Jugador &jugador);
int getGoles(Jugador &jugador);
void setNombre(Jugador &jugador,string nombre);
void setId(Jugador &jugador, int id);
void setGoles(Jugador &jugador, int goles);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _JUGADOR_H_
