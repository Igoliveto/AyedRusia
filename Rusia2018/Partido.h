#ifndef _PARTIDO_H
#define _PARTIDO_H
#ifndef NULL
#define NULL      0
#endif
/*----------------------------------------------------------------------------*/
//                                ESTRUCTURAS
/*----------------------------------------------------------------------------*/
typedef struct{
    int id;
    int idEquipoL;
    int idEquipoV;
    int golesL;
    int golesV;
    bool finalizado;
}Partido;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
/*
  pre : el partido no debe haber sido creado.
  post: el partido queda creado y preparado para ser usado.

  partido : estructura de datos a ser creado.
*/
void crearPartido(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se obtiene el id del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  return: id obtenida del partido.
*/
int getId(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se obtiene el id del equipoL del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  return: id del equipoL obtenido del partido.
*/
int getIdEquipoL(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se obtiene el id del equipoV del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  return: id del equipoV obtenido del partido.
*/
int getIdEquipoV(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se obtiene los golesL del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  return: golesL obtenidos del partido.
*/
int getGolesL(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se obtiene los golesV del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  return: golesV obtenidos del partido.
*/
int getGolesV(Partido &partido);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se setea el id del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  id: valor a cargar en el partido.
*/
void setId(Partido &partido,int id);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se setea el id del equipoL del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  idEquipoL: valor a cargar en el partido.
*/
void setIdEquipoL(Partido &partido, int idEquipoL);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se setea el id del equipoV del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  idEquipoV: valor a cargar en el partido.
*/
void setIdEquipoV(Partido &partido, int idEquipoV);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se setea los golesL del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  golesL: valor a cargar en el partido.
*/
void setGolesL(Partido &partido, int golesL);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido debe haber sido creado.
  post: se setea los golesV del partido creado pasado por parametro.

  partido : estructura de datos a ser usada.
  golesV: valor a cargar en el partido.
*/
void setGolesV(Partido &partido, int golesV);
/*----------------------------------------------------------------------------*/
/*
  pre : el partido  debe haber sido creado.
  post: el partido queda destruido (iniciado a su origen).

  partido : estructura de datos a ser destruido.
*/
void destructor(Partido &partido);
void finalizarPartido(Partido &partido);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _PARTIDO_H
