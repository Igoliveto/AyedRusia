#ifndef _LISTAPARTIDO_H_
#define _LISTAPARTIDO_H_
#include "Partido.h"
#ifndef NULL
#define NULL      0
#endif

/* tipo enumerado para realizar comparaciones */
enum ResultadoComparacion {
  ESMAYOR,
  ESIGUAL,
  ESMENOR
};
struct NodoListaPartido{
Partido partido;
NodoListaPartido* siguiente;

};

typedef NodoListaPartido* PtrNodoPartido;

struct ListaPartido{
PtrNodoPartido primero;
};


void crearListaPartido(ListaPartido &lista);
bool listaVaciaPartido(ListaPartido &lista);
PtrNodoPartido finListaPartido();
PtrNodoPartido primero(ListaPartido &lista);
PtrNodoPartido siguiente(ListaPartido &lista, PtrNodoPartido ptrNodo);
PtrNodoPartido anterior(ListaPartido &lista, PtrNodoPartido ptrNodo);
PtrNodoPartido ultimo(ListaPartido &lista);
PtrNodoPartido crearNodoLista(Partido partido);
PtrNodoPartido adicionarPrincipio(ListaPartido &lista, Partido partido);
PtrNodoPartido adicionarDespues(ListaPartido &lista, Partido partido, PtrNodoPartido ptrNodo);
PtrNodoPartido adicionarFinal(ListaPartido &lista, Partido partido);
PtrNodoPartido adicionarAntes(ListaPartido &lista, Partido partido, PtrNodoPartido ptrNodo);
void colocarDato(ListaPartido &lista, Partido &partido, PtrNodoPartido ptrNodo);
void obtenerDato(ListaPartido &lista, Partido &partido, PtrNodoPartido ptrNodo);
void eliminarNodo(ListaPartido &lista, PtrNodoPartido ptrNodo);
void eliminarNodoPrimero(ListaPartido &lista);
void eliminarNodoUltimo(ListaPartido &lista);
void eliminarLista(ListaPartido &lista);
PtrNodoPartido localizarDato(ListaPartido &lista, Partido partido);
void eliminarDato(ListaPartido &lista, Partido partido);
PtrNodoPartido insertarDato(ListaPartido &lista, Partido partido);
void reordenar(ListaPartido &lista);
int longitud(ListaPartido &lista);
#endif
