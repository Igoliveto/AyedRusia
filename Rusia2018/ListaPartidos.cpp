#include "ListaPartidos.h"

/******************************************************************************/
/* Implementación de Primitivas */
/*------------------------------*/
/*
  pre : ninguna.
  post: compara ambos dato1 y dato2, devuelve
          mayor si dato1 es mayor que dato2,
          igual si dato1 es igual a dato2,
          menor si dato1 es menor que dato2.

  dato1 : dato a comparar.
  dato2 : dato a comparar.
  return resultado de comparar dato1 respecto de dato2.
*/
ResultadoComparacion compararDato(Partido partido1, Partido partido2) {
    if (partido1.id > partido2.id) {
        return ESMAYOR;
    }
    else if (partido1.id < partido2.id) {
        return ESMENOR;
    }
    else {
        return ESIGUAL;
    }
}
void crearListaPartido(ListaPartido &lista) {
  lista.primero = finListaPartido();
}

/*----------------------------------------------------------------------------*/
bool listaVaciaPartido(ListaPartido &lista) {

  return (primero(lista) == finListaPartido());
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido finListaPartido() {
  return NULL;
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido primero(ListaPartido &lista) {
  return lista.primero;
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido siguiente(ListaPartido &lista, PtrNodoPartido ptrNodo) {

  /* verifica si la lista está vacia o si ptrNodo es el último */
  if ((! listaVaciaPartido(lista)) && (ptrNodo != finListaPartido()))
    return ptrNodo->siguiente;
  else
    return finListaPartido();
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido anterior(ListaPartido &lista, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrPrevio = finListaPartido();
  PtrNodoPartido ptrCursor = primero(lista);

  while (( ptrCursor != finListaPartido()) && (ptrCursor != ptrNodo)) {
    ptrPrevio = ptrCursor;
    ptrCursor = siguiente(lista,ptrCursor);
  }
  return ptrPrevio;
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido ultimo(ListaPartido &lista) {

  /* el último nodo de la lista es el anterior al fin() */
  return anterior(lista,finListaPartido());
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido crearNodoLista(Partido partido) {

  /* reserva memoria para el nodo y luego completa sus datos */
  PtrNodoPartido ptrAux = new NodoListaPartido;

  ptrAux->partido = partido;
  ptrAux->siguiente = finListaPartido();

  return ptrAux;
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarPrincipio(ListaPartido &lista, Partido partido) {

  /* crea el nodo */
  PtrNodoPartido ptrNuevoNodo = crearNodoLista(partido);

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
      ptrNuevoNodo = crearNodoLista(partido);

      ptrNuevoNodo->siguiente = ptrNodo->siguiente;
      ptrNodo->siguiente = ptrNuevoNodo;
    }
  }
  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarFinal(ListaPartido &lista, Partido partido) {

  /* adiciona el dato después del último nodo de la lista */
  return adicionarDespues(lista,partido,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido adicionarAntes(ListaPartido &lista, Partido partido, PtrNodoPartido ptrNodo) {

  PtrNodoPartido ptrNuevoNodo = finListaPartido();

  if (! listaVaciaPartido(lista)) {
    if (ptrNodo != primero(lista))
      ptrNuevoNodo = adicionarDespues(lista,partido,anterior(lista,ptrNodo));
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

    if (ptrNodo == primero(lista))
      lista.primero = siguiente(lista,primero(lista));

    else {
      ptrPrevio = anterior( lista , ptrNodo );
      ptrPrevio->siguiente = ptrNodo->siguiente;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaPartido &lista) {

  if (! listaVaciaPartido(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaPartido &lista) {

  if (! listaVaciaPartido(lista))
    eliminarNodo(lista,ultimo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaPartido &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaPartido(lista))
    eliminarNodo(lista,primero(lista));
}

/*----------------------------------------------------------------------------*/
PtrNodoPartido localizarDato(ListaPartido &lista, Partido partido) {

   bool encontrado = false;
   Partido partidoCursor;
   PtrNodoPartido ptrCursor = primero(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finListaPartido()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,partidoCursor,ptrCursor);
    if (compararDato(partidoCursor,partido) == ESIGUAL)
      encontrado = true;
    else
      ptrCursor = siguiente(lista,ptrCursor);
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
PtrNodoPartido insertarDato(ListaPartido &lista, Partido partido) {

  PtrNodoPartido ptrPrevio = primero(lista);
  PtrNodoPartido ptrCursor = primero(lista);
  PtrNodoPartido ptrNuevoNodo;
  Partido partidoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finListaPartido()) && (! ubicado)) {

    obtenerDato(lista,partidoCursor,ptrCursor);
    if (compararDato(partidoCursor,partido) == ESMAYOR)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguiente(lista,ptrCursor);
    }
  }

  if (ptrCursor == primero(lista))
    ptrNuevoNodo = adicionarPrincipio(lista,partido);
  else
    ptrNuevoNodo = adicionarDespues(lista,partido,ptrPrevio);

  return ptrNuevoNodo;
}

/*----------------------------------------------------------------------------*/

void reordenar(ListaPartido &lista) {

  ListaPartido temp = lista;
  PtrNodoPartido ptrCursor = primero(temp);
  crearListaPartido(lista);
  while ( ptrCursor != finListaPartido() ) {
        Partido partido;
        obtenerDato( temp, partido, ptrCursor);
        insertarDato( lista, partido );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primero(temp);
  }
  eliminarLista( temp );
}


/*----------------------------------------------------------------------------*/

int longitud(ListaPartido &lista){
  PtrNodoPartido ptrCursor = primero(lista);
  int longitud = 0;
  while ( ptrCursor != finListaPartido() ) {
        longitud++;
        ptrCursor = siguiente( lista, ptrCursor);
  }
  return longitud;
}

/*----------------------------------------------------------------------------*/

