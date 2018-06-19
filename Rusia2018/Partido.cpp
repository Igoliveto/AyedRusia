#include "partido.h"


void crearPartido(Partido &partido, int id, int idEquipoL, int idEquipoV){
partido.id=id;
partido.idEquipoL=idEquipoL;
partido.idEquipoV=idEquipoV;
partido.golesL=0;
partido.golesV=0;

}
int getId(Partido &partido){
return partido.id;
}
int getIdEquipoL(Partido &partido){
return partido.idEquipoL;
}
int getIdEquipoV(Partido &partido){
return partido.idEquipoV;
}
void setId(Partido &partido,int id){
partido.id=id;
}
void setIdEquipoL(Partido &partido, int idEquipoL){
partido.idEquipoL=idEquipoL;
}
void setIdEquipoV(Partido &partido, int idEquipoV){
partido.idEquipoV=idEquipoV;
}

