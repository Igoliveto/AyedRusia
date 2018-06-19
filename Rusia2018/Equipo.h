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

void crearEquipo(Equipo &equipo);

int getId(Equipo equipo);

void setId(Equipo &equipo, int id);

string getNombre(Equipo equipo);

void setNombre(Equipo &equipo,string nombre);

void setGolesAFavor(Equipo &equipo,int goles);

int getGolesAFavor(Equipo equipo);

void setGolesEnContra(Equipo &equipo,int golesEnContra);

int getGolesEnContra(Equipo equipo);

void setPuntos(Equipo &equipo,int puntos);

int getPuntos(Equipo equipo);
#endif // _EQUIPO_H
