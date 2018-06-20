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
/*
  pre : el jugador no debe haber sido creado.
  post: el jugador queda creado y preparado para ser usado.

  jugador : estructura de datos a ser creado.
*/
void crearJugador(Jugador &jugador);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se obtiene el id del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  return: id obtenida del jugador.
*/
int getId(Jugador &jugador);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se obtiene el nombre del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  return: nombre obtenido del jugador.
*/
string getNombre(Jugador &jugador);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se obtiene los goles del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  return: goles obtenidos del jugador.
*/
int getGoles(Jugador &jugador);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se setea el nombre del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  nombre: valor a cargar en el jugador.
*/
void setNombre(Jugador &jugador,string nombre);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se setea el id del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  id: valor a cargar en el jugador.
*/
void setId(Jugador &jugador, int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el jugador debe haber sido creado.
  post: se setea los goles del jugador creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  goles: valor a cargar en el jugador.
*/
void setGoles(Jugador &jugador, int goles);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _JUGADOR_H_
