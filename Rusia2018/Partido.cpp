#include "partido.h"
#ifndef NULL
#define NULL      0
#endif
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearPartido(Partido &partido){
partido.id=0;
partido.idEquipoL=0;
partido.idEquipoV=0;
partido.golesL=0;
partido.golesV=0;
}
/*----------------------------------------------------------------------------*/
int getId(Partido &partido){
return partido.id;
}
/*----------------------------------------------------------------------------*/
int getIdEquipoL(Partido &partido){
return partido.idEquipoL;
}
/*----------------------------------------------------------------------------*/
int getIdEquipoV(Partido &partido){
return partido.idEquipoV;
}
/*----------------------------------------------------------------------------*/
int getGolesL(Partido &partido){
return partido.golesL;
}
/*----------------------------------------------------------------------------*/
int getGolesV(Partido &partido){
return partido.golesV;
}
/*----------------------------------------------------------------------------*/
void setId(Partido &partido,int id){
partido.id=id;
}
/*----------------------------------------------------------------------------*/
void setIdEquipoL(Partido &partido, int idEquipoL){
partido.idEquipoL=idEquipoL;
}
/*----------------------------------------------------------------------------*/
void setIdEquipoV(Partido &partido, int idEquipoV){
partido.idEquipoV=idEquipoV;
}
/*----------------------------------------------------------------------------*/
void setGolesL(Partido &partido, int golesL){
partido.golesL=golesL;
}
/*----------------------------------------------------------------------------*/
void setGolesV(Partido &partido, int golesV){
partido.golesV=golesV;
}
/*----------------------------------------------------------------------------*/
void destructor(Partido &partido){
partido.id=0;
partido.idEquipoL=0;
partido.idEquipoV=0;
partido.golesL=0;
partido.golesV=0;
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/
