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
void crearGrupo(Grupo &grupo,char id, string nombre,int idEquipo1,int idEquipo2, int idEquipo3,int idEquipo4);
void setId(Grupo &grupo,int id);




#endif // _GRUPO_H
