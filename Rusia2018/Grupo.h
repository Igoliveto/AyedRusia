#ifndef _GRUPO_H
#define _GRUPO_H_
#ifndef NULL
#define NULL      0
#endif
#include <string>
using namespace std;
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
char id;
string nombre;
int idEquipo1;
int idEquipo2;
int idEquipo3;
int idEquipo4;
}Grupo;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo no debe haber sido creado.
  post: el grupo queda creado y preparado para ser usado.

  grupo : estructura de datos a ser creado.
*/
void crearGrupo(Grupo &grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el id del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  id: valor a cargar en el grupo.
*/
void setId(Grupo &grupo,char id);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el id del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: id obtenida del grupo.
*/
char getId(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el nombre del grupo creado pasado por parametro.

  jugador : estructura de datos a ser usada.
  nombre: valor a cargar en el grupo.
*/
void setNombre(Grupo &grupo,string nombre);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el nombre del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: nombre obtenido del grupo.
*/
string getNombre(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el id del equipo 1 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  id: valor del equipo 1 a cargar en el grupo.
*/
void setIdEquipo1(Grupo &grupo,int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el id del equipo 1 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: id del equipo 1 obtenida del grupo.
*/
int getIdEquipo1(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el id del equipo 2 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  id: valor del equipo 2 a cargar en el grupo.
*/
void setIdEquipo2(Grupo &grupo,int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el id del equipo 2 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: id del equipo 2 obtenida del grupo.
*/
int getIdEquipo2(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el id del equipo 3 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  id: valor del equipo 3 a cargar en el grupo.
*/
void setIdEquipo3(Grupo &grupo,int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el id del equipo 3 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: id del equipo 3 obtenida del grupo.
*/
int getIdEquipo3(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se setea el id del equipo 4 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  id: valor del equipo 4 a cargar en el grupo.
*/
void setIdEquipo4(Grupo &grupo,int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo debe haber sido creado.
  post: se obtiene el id del equipo 4 del grupo creado pasado por parametro.

  grupo : estructura de datos a ser usada.
  return: id del equipo 4 obtenida del grupo.
*/
int getIdEquipo4(Grupo grupo);
/*----------------------------------------------------------------------------*/
/*
  pre : el grupo  debe haber sido creado.
  post: el grupo queda destruido (iniciado a su origen).

  grupo : estructura de datos a ser destruido.
*/
void destructor(Grupo &grupo);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _GRUPO_H
