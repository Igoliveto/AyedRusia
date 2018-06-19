#ifndef _EQUIPO_H
#define _EQUIPO_H
#ifndef NULL
#define NULL      0
#endif
#include "ListaJugadores.h"
#include <string>
#include <iostream>
using namespace std;
typedef struct {
int id;
string nombre;
int golesAFavor;
int golesEnContra;
int puntos;
Lista listaJugadores;
}Equipo;

void crearEquipo(Equipo &equipo,int id, string nombre);

int getId(Equipo &equipo);
string getNombre(Equipo &equipo);
void setNombre(Equipo &equipo,string nombre);
void setId(Equipo &equipo, int id);

#endif // _EQUIPO_H
