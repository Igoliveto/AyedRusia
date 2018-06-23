#include "ListaEquipo.h"

#ifndef NULL
#define NULL      0
#endif
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearListaEquipo(ListaEquipo &lista){
lista.primero=finEquipo();

}
/*----------------------------------------------------------------------------*/
bool listaVaciaEquipo(ListaEquipo &lista){
return(lista.primero==finEquipo());
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo finEquipo() {
  return NULL;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo primeroEquipo(ListaEquipo &lista) {
  return lista.primero;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo siguienteEquipo(ListaEquipo &lista, PtrNodoListaEquipo ptrNodo){

if((!listaVaciaEquipo(lista)) && (ptrNodo->siguiente!=finEquipo())){
    return ptrNodo->siguiente;
}
else
    return finEquipo();

}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo anteriorEquipo(ListaEquipo &lista,PtrNodoListaEquipo ptrNodo){
PtrNodoListaEquipo ptrAnterior=finEquipo();
PtrNodoListaEquipo ptrCursor=primeroEquipo(lista);

while(ptrCursor!=finEquipo() && ptrCursor !=ptrNodo){

    ptrAnterior=ptrCursor;
    ptrCursor=siguienteEquipo(lista,ptrCursor);

}
return ptrAnterior;

}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo ultimoEquipo(ListaEquipo &lista){
return anteriorEquipo(lista,finEquipo());
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo crearNodoListaEquipo(Equipo equipo){
PtrNodoListaEquipo ptrNodo = new NodoListaEquipo;
ptrNodo->equipo=equipo;
ptrNodo->siguiente=finEquipo();

return ptrNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo adicionarAlPrincipio(ListaEquipo &lista, Equipo equipo){
PtrNodoListaEquipo ptrNodo = crearNodoListaEquipo(equipo);

ptrNodo->siguiente=lista.primero;
lista.primero=ptrNodo;

return ptrNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo adicionarDespues(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo){

PtrNodoListaEquipo ptrAux = finEquipo();
if(listaVaciaEquipo(lista)){
    adicionarAlPrincipio(lista,equipo);
    }
   if(ptrNodo!=finEquipo()){

    ptrAux=crearNodoListaEquipo(equipo);

    ptrAux->siguiente=ptrNodo->siguiente;
    ptrNodo->siguiente=ptrAux;
   }

    return ptrAux;

 }
/*----------------------------------------------------------------------------*/
 PtrNodoListaEquipo adicionarFinal(ListaEquipo &lista,Equipo equipo){

 return adicionarDespues(lista,equipo,ultimoEquipo(lista));
   }
/*----------------------------------------------------------------------------*/
 PtrNodoListaEquipo adicionarAntes(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo){
 PtrNodoListaEquipo ptrNodoNuevo=finEquipo();
 if(!listaVaciaEquipo(lista)){

     if(ptrNodo!=primeroEquipo(lista))
         ptrNodoNuevo=adicionarDespues(lista,equipo,anteriorEquipo(lista,ptrNodo));
      else
         ptrNodoNuevo=adicionarAlPrincipio(lista,equipo);
    }
    return ptrNodoNuevo;

 }
/*----------------------------------------------------------------------------*/
 void colocarDato(ListaEquipo &lista,Equipo equipo, PtrNodoListaEquipo ptrNodo){
 if(!listaVaciaEquipo(lista) && ptrNodo!=finEquipo()){
    ptrNodo->equipo=equipo;
 }
 }
/*----------------------------------------------------------------------------*/
 void obtenerDato(ListaEquipo &lista, Equipo &equipo, PtrNodoListaEquipo ptrNodo) {

  if ((! listaVaciaEquipo(lista)) && (ptrNodo != finEquipo()))
    equipo = ptrNodo->equipo;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaEquipo &lista, PtrNodoListaEquipo ptrNodo) {

  PtrNodoListaEquipo ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVaciaEquipo(lista)) && (ptrNodo != finEquipo())) {

    if (ptrNodo == primeroEquipo(lista))
      lista.primero = siguienteEquipo(lista,primeroEquipo(lista));

    else {
      ptrPrevio = anteriorEquipo( lista , ptrNodo );
      ptrPrevio->siguiente = ptrNodo->siguiente;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaEquipo &lista) {

  if (! listaVaciaEquipo(lista))
    eliminarNodo(lista,primeroEquipo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaEquipo &lista) {

  if (! listaVaciaEquipo(lista))
    eliminarNodo(lista,ultimoEquipo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaEquipo &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaEquipo(lista))
    eliminarNodo(lista,primeroEquipo(lista));
}
/*--------------------------------------------------------------------------*/
PtrNodoListaEquipo localizarDato(ListaEquipo &lista, Equipo equipo) {

   bool encontrado = false;
   Equipo equipoCursor;
   PtrNodoListaEquipo ptrCursor = primeroEquipo(lista);

  /* recorre los nodos hasta llegar al último o hasta
     encontrar el nodo buscado */
  while ((ptrCursor != finEquipo()) && (! encontrado)) {

    /* obtiene el dato del nodo y lo compara */
    obtenerDato(lista,equipoCursor,ptrCursor);
    if (compararDatoEquipo(equipoCursor,equipo) == IGUAL_EQUIPO)
      encontrado = true;
    else
      ptrCursor = siguienteEquipo(lista,ptrCursor);
  }

  /* si no lo encontró devuelve fin */
  if (! encontrado)
    ptrCursor = finEquipo();

  return ptrCursor;
}

/*----------------------------------------------------------------------------*/
ResultadoComparacionEquipo compararDatoEquipo(Equipo equipo1, Equipo equipo2) {
    if (equipo1.id > equipo2.id) {
        return MAYOR_EQUIPO;
    }
    else if (equipo1.id < equipo2.id) {
        return MENOR_EQUIPO;
    }
    else {
        return IGUAL_EQUIPO;
    }
}
/*---------------------------------------------------------------------------*/
bool estaPrimero(Equipo equipo1, Equipo equipo2) {
    if (equipo1.puntos > equipo2.puntos) {
        return true;
    }
    else if (equipo1.puntos < equipo2.puntos) {
        return false;
    }
    else {
        if(equipo1.golesAFavor> equipo2.golesAFavor){
            return true;
        }
        else return false;

    }
}
/*----------------------------------------------------------------------------*/
void eliminarDato(ListaEquipo &lista, Equipo equipo) {

  /* localiza el dato y luego lo elimina */
  PtrNodoListaEquipo ptrNodo = localizarDato(lista,equipo);
  if (ptrNodo != finEquipo())
    eliminarNodo(lista,ptrNodo);
}
/*----------------------------------------------------------------------------*/
PtrNodoListaEquipo insertarDato(ListaEquipo &lista, Equipo equipo) {

  PtrNodoListaEquipo ptrPrevio = primeroEquipo(lista);
  PtrNodoListaEquipo ptrCursor = primeroEquipo(lista);
  PtrNodoListaEquipo ptrNuevoNodo;
  Equipo equipoCursor;
  bool ubicado = false;

  /* recorre la lista buscando el lugar de la inserción */
  while ((ptrCursor != finEquipo()) && (! ubicado)) {

    obtenerDato(lista,equipoCursor,ptrCursor);
    if (estaPrimero(equipoCursor,equipo) == true)
      ubicado = true;

    else {
      ptrPrevio = ptrCursor;
      ptrCursor = siguienteEquipo(lista,ptrCursor);
    }
  }

  if (ptrCursor == primeroEquipo(lista))
    ptrNuevoNodo = adicionarDespues(lista,equipo,ptrPrevio);
  else
    ptrNuevoNodo = adicionarAlPrincipio(lista,equipo);

  return ptrNuevoNodo;
}
/*------------------------------------------------------------------------------*/
void reordenar(ListaEquipo &lista) {

  ListaEquipo temp = lista;
  PtrNodoListaEquipo ptrCursor = primeroEquipo(temp);
  crearListaEquipo(lista);
  while ( ptrCursor != finEquipo() ) {
        Equipo equipo;
        obtenerDato( temp, equipo, ptrCursor);
        insertarDato( lista, equipo );
        eliminarNodo( temp, ptrCursor );
        ptrCursor = primeroEquipo(temp);
  }
  eliminarLista( temp );
}
/******************************************************************************/
