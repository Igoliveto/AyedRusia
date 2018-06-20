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
}Partido;
/*----------------------------------------------------------------------------*/
//                                PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearPartido(Partido &partido);
int getId(Partido &partido);
int getIdEquipoL(Partido &partido);
int getIdEquipoV(Partido &partido);
int getGolesL(Partido &partido);
int getGolesV(Partido &partido);
void setId(Partido &partido,int id);
void setIdEquipoL(Partido &partido, int idEquipoL);
void setIdEquipoV(Partido &partido, int idEquipoV);
void setGolesL(Partido &partido, int golesL);
void setGolesV(Partido &partido, int golesV);
/*----------------------------------------------------------------------------*/
/******************************************************************************/
#endif // _PARTIDO_H
