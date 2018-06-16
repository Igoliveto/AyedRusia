#include "Grupo.h"
#include<string>
#include <iostream>

void crearGrupo(Grupo &grupo,char id, string nombre,int idEquipo1,int idEquipo2, int idEquipo3,int idEquipo4){
    grupo.id=id;
    grupo.nombre=nombre;
    grupo.idEquipo1=idEquipo1;
    grupo.idEquipo2=idEquipo2;
    grupo.idEquipo3=idEquipo3;
    grupo.idEquipo4=idEquipo4;

}

void setId(Grupo &grupo,int id){
    grupo.id=id;
}

