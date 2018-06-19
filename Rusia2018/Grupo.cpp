#include "Grupo.h"
#include<string>
#include <iostream>

void crearGrupo(Grupo &grupo){
    grupo.id='-';
    grupo.nombre="-";
    grupo.idEquipo1=0;
    grupo.idEquipo2=0;
    grupo.idEquipo3=0;
    grupo.idEquipo4=0;

}

void setId(Grupo &grupo,char id){
    grupo.id=id;
}

char getId(Grupo grupo){
return grupo.id;
}
void setNombre(Grupo &grupo,string nombre){
grupo.nombre=nombre;
}
string getNombre(Grupo grupo){
return grupo.nombre;}

void setIdEquipo1(Grupo &grupo,int id){
grupo.idEquipo1=id;
}
int getIdEquipo1(Grupo grupo){
return grupo.idEquipo1;
}
void setIdEquipo2(Grupo &grupo,int id){
grupo.idEquipo2=id;
}
int getIdEquipo2(Grupo grupo){
return grupo.idEquipo2;
}
void setIdEquipo3(Grupo &grupo,int id){
grupo.idEquipo3=id;
}
int getIdEquipo3(Grupo grupo){
return grupo.idEquipo3;
}
void setIdEquipo4(Grupo &grupo,int id){
grupo.idEquipo4=id;
}
int getIdEquipo4(Grupo grupo){
return grupo.idEquipo4;
}


