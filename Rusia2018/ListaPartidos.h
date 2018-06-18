#ifndef _LISTAEQUIPO_H
#define _LISTAEQUIPO_H
#include "Partido.h"
#ifndef NULL
#define NULL      0
#endif


struct NodoListaPartido{
Partido partido;
NodoListaPartido* siguiente;

};

typedef NodoPartido* PtrNodoPartido;

struct ListaPartido{
PtrNodoLista primero;
};
