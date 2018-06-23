#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#include "ListaPartidos.h"
#ifndef NULL
#define NULL      0
#endif

using namespace std;

/*----------------------------------------------------------------------------*/
//                        IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearListaPartido(ListaPartido &lista) {
  lista.primero = finListaPartido();
}
/*----------------------------------------------------------------------------*/
bool listaVaciaPartido(ListaPartido &lista) {

  return (primeroPartido(lista) == finListaPartido());
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido finListaPartido() {
  return NULL;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido primeroPartido(ListaPartido &lista) {
  return lista.primero;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido siguientePartido(ListaPartido &lista, PtrNodoPartido ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVaciaPartido(lista)) && (ptrNodo != finListaPartido()))
    return ptrNodo->siguiente;
  else
    return finListaPartido();
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido anteriorPartido(ListaPartido &lista, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrPrevio = finListaPartido();
  PtrNodoPartido ptrCursor = primeroPartido(lista);

  while (( ptrCursor != finListaPartido()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguientePartido(lista,ptrCursor);
  }
  return ptrPrevio;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido ultimoPartido(ListaPartido &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anteriorPartido(lista,finListaPartido());
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido crearNodoListaPartido(Partido partido) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoPartido ptrAux = new NodoListaPartido;

  ptrAux->partido = partido;
  ptrAux->siguiente = finListaPartido();

  return ptrAux;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarPrincipio(ListaPartido &lista, Partido partido) {

  /* crea el nodo */
  PtrNodoPartido ptrNuevoNodo = crearNodoListaPartido(partido);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->siguiente = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarDespues(ListaPartido &lista, Partido partido, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrNuevoNodo = finListaPartido();

  /* si la lista está vacia se adiciona la principio */
  if (listaVaciaPartido(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,partido);

  else {
    if (ptrNodo != finListaPartido()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaPartido(partido);

      ptrNuevoNodo->siguiente = ptrNodo->siguiente;
      ptrNodo->siguiente = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarFinal(ListaPartido &lista, Partido partido) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,partido,ultimoPartido(lista));
}
/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarAntes(ListaPartido &lista, Partido partido, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrNuevoNodo = finListaPartido();

  if (! listaVaciaPartido(lista)) {
    if (ptrNodo != primeroPartido(lista))
      ptrNuevoNodo = adicionarDespues(lista,partido,anteriorPartido(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,partido);
   }
   return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
void colocarDato(ListaPartido &lista, Partido &partido, PtrNodoPartido ptrNodo) {

  if ( (! listaVaciaPartido(lista)) && (ptrNodo != finListaPartido()))
    ptrNodo->partido = partido;
}
/*----------------------------------------------------------------------------*/
void obtenerDato(ListaPartido &lista, Partido &partido, PtrNodoPartido ptrNodo) {

  if ((! listaVaciaPartido(lista)) && (ptrNodo != finListaPartido()))
    partido = ptrNodo->partido;
}
/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaPartido &lista, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVaciaPartido(lista)) && (ptrNodo != finListaPartido())) {

    if (ptrNodo == primeroPartido(lista))
      lista.primero = siguientePartido(lista,primeroPartido(lista));

    else {
      ptrPrevio = anteriorPartido( lista , ptrNodo );
      ptrPrevio->siguiente = ptrNodo->siguiente;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}
/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaPartido &lista) {

  if (! listaVaciaPartido(lista))
    eliminarNodo(lista,primeroPartido(lista));
}
/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaPartido &lista) {

  if (! listaVaciaPartido(lista))
    eliminarNodo(lista,ultimoPartido(lista));
}
/*----------------------------------------------------------------------------*/
void eliminarLista(ListaPartido &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaPartido(lista))
    eliminarNodo(lista,primeroPartido(lista));
}
/*----------------------------------------------------------------------------*/
ResultadoComparacionPartido compararDatoPartido(Partido partido1, Partido partido2) {

    if (partido1.id > partido2.id) {
        return MAYOR_PARTIDO;
    }
    else if (partido1.id < partido2.id) {
        return MENOR_PARTIDO;
    }
    else {
        return IGUAL_PARTIDO;
    }
}
/*--------------------------------------------------------------------------*/
PtrNodoPartido localizarDato(ListaPartido &lista, Partido partido) {

   bool encontrado = false;
   Partido partidoCursor;
   PtrNodoPartido ptrCursor = primeroPartido(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finListaPartido()) && (false== encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,partidoCursor,ptrCursor);
    if (compararDatoPartido(partidoCursor,partido) == IGUAL_PARTIDO)
      encontrado = true;
    else
      ptrCursor = siguientePartido(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finListaPartido();

  return ptrCursor;
}
/*----------------------------------------------------------------------------*/
void eliminarDato(ListaPartido &lista, Partido partido) {

  /* localiza el dato y luego lo elimina */
  PtrNodoPartido ptrNodo = localizarDato(lista,partido);
  if (ptrNodo != finListaPartido())
    eliminarNodo(lista,ptrNodo);
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/
