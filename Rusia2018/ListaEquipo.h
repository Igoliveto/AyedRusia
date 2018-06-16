#ifndef _LISTAEQUIPO_H
#define _LISTAEQUIPO_H
#include "Equipo.h"


struct NodoListaEquipo{
Equipo equipo;
NodoListaEquipo* siguiente;

};

typedef NodoListaEquipo* PtrNodoListaEquipo;

struct ListaEquipo{
PtrNodoListaEquipo primero;

};
/*-------------Primitivas-------------*/
void crearListaEquipo(ListaEquipo &lista);

bool listaVaciaEquipo(ListaEquipo &lista);

PtrNodoListaEquipo listaPrimeroEquipo(ListaEquipo &lista);

PtrNodoListaEquipo finEquipo();

PtrNodoListaEquipo siguienteEquipo(Lista &listaEquipo, PtrNodoListaEquipo ptrNodo);

PtrNodoListaEquipo anteriorEquipo(ListaEquipo &lista,PtrNodoListaEquipo ptrNodo);

PtrNodoListaEquipo ultimoEquipo(ListaEquipo &lista);

PtrNodoListaEquipo crearNodoLista(Equipo equipo);

PtrNodoListaEquipo adicionarAlPrincipio(ListaEquipo &lista, Equipo equipo);

PtrNodoListaEquipo adicionarDespues(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo);

PtrNodoListaEquipo adicionarFinal(ListaEquipo &lista,Equipo equipo);

PtrNodoListaEquipo adicionarAntes(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo);

void colocarDato(ListaEquipo &lista,Equipo equipo, PtrNodoListaEquipo ptrNodo);


#endif // _LISTAEQUIPO_H
