#ifndef _GRUPO_H
#define _GRUPO_H_
#ifndef NULL
#define NULL      0
#endif
#include <string>
#include <iostream>
using namespace std;
typedef struct{
char id;
string nombre;
int idEquipo1;
int idEquipo2;
int idEquipo3;
int idEquipo4;
}Grupo;
void crearGrupo(Grupo &grupo);

void setId(Grupo &grupo,char id);

char getId(Grupo grupo);

void setNombre(Grupo &grupo,string nombre);

string getNombre(Grupo grupo);

void setIdEquipo1(Grupo &grupo,int id);

int getIdEquipo1(Grupo grupo);

void setIdEquipo2(Grupo &grupo,int id);

int getIdEquipo2(Grupo grupo);

void setIdEquipo3(Grupo &grupo,int id);

int getIdEquipo3(Grupo grupo);

void setIdEquipo4(Grupo &grupo,int id);

int getIdEquipo4(Grupo grupo);




#endif // _GRUPO_H
