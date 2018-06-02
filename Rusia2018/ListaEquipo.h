#ifndef _LISTAEQUIPO_H
#define _LISTAEQUIPO_H
#include "Equipo.h"


struct NodoLista{
Equipo equipo;
NodoLista* siguiente;

};

typedef NodoLista* PtrNodoLista;

struct Lista{
PtrNodoLista primero;

};
/*-------------Primitivas-------------*/
void crearLista(Lista &lista);

bool listaVacia(Lista &lista);

PtrNodoLista listaPrimero(Lista &lista);

PtrNodoLista fin();

PtrNodoLista siguiente(Lista &lista, PtrNodoLista ptrNodo);

PtrNodoLista anterior(Lista &lista,PtrNodoLista ptrNodo);

PtrNodoLista ultimo(Lista &lista);

PtrNodoLista crearNodoLista(Equipo equipo);

PtrNodoLista adicionarAlPrincipio(Lista &lista, Equipo equipo);

PtrNodoLista adicionarDespues(Lista &lista, Equipo equipo, PtrNodoLista ptrNodo);

PtrNodoLista adicionarFinal(Lista &lista,Equipo equipo);

PtrNodoLista adicionarAntes(Lista &lista, Equipo equipo, PtrNodoLista ptrNodo);

void colocarDato(Lista &lista,Equipo equipo, PtrNodoLista ptrNodo);


#endif // _LISTAEQUIPO_H
