#ifndef _EQUIPO_H
#define _EQUIPO_H
#ifndef NULL
#define NULL      0
#endif
#include "ListaJugadores.h"
#include <string>
using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct {
int id;
string nombre;
int golesAFavor;
int golesEnContra;
int puntos;
ListaJugador listaJugadores;
}Equipo;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo no debe haber sido creado.
  post: el equipo queda creado y preparado para ser usado.

  equipo : estructura de datos a ser creado.
*/
void crearEquipo(Equipo &equipo);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se obtiene el id del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  return: id obtenida del equipo.
*/
int getId(Equipo equipo);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se setea el id del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  id: valor a cargar en el equipo.
*/

void setId(Equipo &equipo, int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se obtiene el nombre del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  return:nombre obtenido del equipo.
*/
string getNombre(Equipo equipo);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se setea el nombre del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  nombre: valor a cargar en el equipo.
*/
void setNombre(Equipo &equipo,string nombre);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se setea los goles a favor del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  golesAFavor: valor a cargar en el equipo.
*/
void setGolesAFavor(Equipo &equipo,int goles);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se obtiene los goles a favor del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  return:goles a favor obtenidos del equipo.
*/
int getGolesAFavor(Equipo equipo);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se setea los goles en contra del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  golesEnContra: valor a cargar en el equipo.
*/
void setGolesEnContra(Equipo &equipo,int golesEnContra);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se obtiene los goles en contra del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  return:goles en contra obtenidos del equipo.
*/
int getGolesEnContra(Equipo equipo);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se setea puntos del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  puntos: valor a cargar en el equipo.
*/
void setPuntos(Equipo &equipo,int puntos);
/*----------------------------------------------------------------------------*/
/*
  pre : el equipo debe haber sido creado.
  post: se obtiene los puntos del equipo creado pasado por parametro.

  equipo : estructura de datos a ser usada.
  return:puntos obtenidos del equipo.
*/
int getPuntos(Equipo equipo);
/*----------------------------------------------------------------------------*/
ListaJugador getLista(Equipo equipo);
void destructor(Equipo &equipo);
/******************************************************************************/
#endif // _EQUIPO_H
