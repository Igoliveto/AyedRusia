#include "ListaJugadores.h"

#ifndef NULL
#define NULL      0
#endif
/*----------------------------------------------------------------------------*/
//                        IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearListaJugador(ListaJugador &lista) {
  lista.primero = finJugador();
}
/*----------------------------------------------------------------------------*/
bool listaVaciaJugador(ListaJugador &lista) {

  return (primeroJugador(lista) == finJugador());
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador finJugador() {
  return NULL;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador primeroJugador(ListaJugador &lista) {
  return lista.primero;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador siguienteJugador(ListaJugador &lista, PtrNodoListaJugador ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVaciaJugador(lista)) && (ptrNodo != finJugador()))
    return ptrNodo->sgte;
  else
    return finJugador();
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador anteriorJugador(ListaJugador &lista, PtrNodoListaJugador ptrNodo) {

  PtrNodoListaJugador ptrPrevio = finJugador();
  PtrNodoListaJugador ptrCursor = primeroJugador(lista);

  while (( ptrCursor != finJugador()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguienteJugador(lista,ptrCursor);
  }
  return ptrPrevio;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador ultimoJugador(ListaJugador &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anteriorJugador(lista,finJugador());
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador crearNodoListaJugador(Jugador jugador) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoListaJugador ptrAux = new NodoListaJugador;

  ptrAux->jugador = jugador;
  ptrAux->sgte = finJugador();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoListaJugador adicionarPrincipio(ListaJugador &lista, Jugador jugador) {

  /* crea el nodo */
  PtrNodoListaJugador ptrNuevoNodo = crearNodoListaJugador(jugador);

  /* lo incorpora al principio de la lista */
  ptrNuevoNodo->sgte = lista.primero;
  lista.primero = ptrNuevoNodo;

  return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador adicionarDespues(ListaJugador &lista, Jugador jugador, PtrNodoListaJugador ptrNodo) {

  PtrNodoListaJugador ptrNuevoNodo = finJugador();

  /* si la lista está vacia se adiciona la principio */
  if (listaVaciaJugador(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,jugador);

  else {
    if (ptrNodo != finJugador()) {

      /* crea el nodo y lo intercala en la lista */
      ptrNuevoNodo = crearNodoListaJugador(jugador);

      ptrNuevoNodo->sgte = ptrNodo->sgte;
      ptrNodo->sgte = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador adicionarFinal(ListaJugador &lista, Jugador jugador) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,jugador,ultimoJugador(lista));
}
/*----------------------------------------------------------------------------*/
PtrNodoListaJugador adicionarAntes(ListaJugador &lista, Jugador jugador, PtrNodoListaJugador ptrNodo) {

  PtrNodoListaJugador ptrNuevoNodo = finJugador();

  if (! listaVaciaJugador(lista)) {
    if (ptrNodo != primeroJugador(lista))
      ptrNuevoNodo = adicionarDespues(lista,jugador,anteriorJugador(lista,ptrNodo));
    else
      ptrNuevoNodo = adicionarPrincipio(lista,jugador);
   }
   return ptrNuevoNodo;
}
/*----------------------------------------------------------------------------*/
void colocarDato(ListaJugador &lista, Jugador &jugador, PtrNodoListaJugador ptrNodo) {

  if ( (! listaVaciaJugador(lista)) && (ptrNodo != finJugador()))
    ptrNodo->jugador = jugador;
}
/*----------------------------------------------------------------------------*/
void obtenerDato(ListaJugador &lista, Jugador &jugador, PtrNodoListaJugador ptrNodo) {

  if ((! listaVaciaJugador(lista)) && (ptrNodo != finJugador()))
    jugador = ptrNodo->jugador;
}
/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaJugador &lista, PtrNodoListaJugador ptrNodo) {

  PtrNodoListaJugador ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVaciaJugador(lista)) && (ptrNodo != finJugador())) {

    if (ptrNodo == primeroJugador(lista))
      lista.primero = siguienteJugador(lista,primeroJugador(lista));

    else {
      ptrPrevio = anteriorJugador( lista , ptrNodo );
      ptrPrevio->sgte = ptrNodo->sgte;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}
/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaJugador &lista) {

  if (! listaVaciaJugador(lista))
    eliminarNodo(lista,primeroJugador(lista));
}
/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaJugador &lista) {

  if (! listaVaciaJugador(lista))
    eliminarNodo(lista,ultimoJugador(lista));
}
/*----------------------------------------------------------------------------*/
void eliminarLista(ListaJugador &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaJugador(lista))
    eliminarNodo(lista,primeroJugador(lista));
}
/*----------------------------------------------------------------------------*/
ResultadoComparacionJugador compararDatoJugador(Jugador jugador1, Jugador jugador2) {
    if (jugador1.id > jugador2.id) {
        return MAYOR_JUGADOR;
    }
    else if (jugador1.id < jugador2.id) {
        return MENOR_JUGADOR;
    }
    else {
        return IGUAL_JUGADOR;
    }
}
/*--------------------------------------------------------------------------*/
PtrNodoListaJugador localizarDato(ListaJugador &lista, Jugador jugador) {

   bool encontrado = false;
   Jugador jugadorCursor;
   PtrNodoListaJugador ptrCursor = primeroJugador(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finJugador()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,jugadorCursor,ptrCursor);
    if (compararDatoJugador(jugadorCursor,jugador) == IGUAL_JUGADOR)
      encontrado = true;
    else
      ptrCursor = siguienteJugador(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finJugador();

  return ptrCursor;
}
/*----------------------------------------------------------------------------*/
void eliminarDato(ListaJugador &lista, Jugador jugador) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaJugador ptrNodo = localizarDato(lista,jugador);
  if (ptrNodo != finJugador())
    eliminarNodo(lista,ptrNodo);
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/
