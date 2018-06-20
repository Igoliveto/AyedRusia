#include "ListaGrupo.h"

#ifndef NULL
#define NULL      0
#endif
/*----------------------------------------------------------------------------*/
//                           IMPLEMENTACION DE PRIMITIVAS
/*----------------------------------------------------------------------------*/
void crearListaGrupo(ListaGrupo &lista){
    lista.primero=finGrupo();
}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo finGrupo(){
    return NULL;
}
/*----------------------------------------------------------------------------*/
bool listaVaciaGrupo(ListaGrupo lista){
    return(lista.primero==finGrupo());
}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo primeroListaGrupo(ListaGrupo &lista){
return lista.primero;
}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo siguienteListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo){
    if(!listaVaciaGrupo(lista) && ptrNodoGrupo->siguiente!=finGrupo()){

        return ptrNodoGrupo->siguiente;
        }
        else
            return finGrupo();

}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo anteriorListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo){

PtrNodoGrupo ptrCursor = primeroListaGrupo(lista);
PtrNodoGrupo ptrAnterior=finGrupo();
    while(ptrCursor!=finGrupo() && ptrCursor!=ptrNodoGrupo){
        ptrAnterior=ptrCursor;
        ptrCursor=siguienteListaGrupo(lista,ptrCursor);
    }

    return ptrAnterior;

}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo ultimoListaGrupo(ListaGrupo &lista){
return anteriorListaGrupo(lista,finGrupo());

}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo crearNodoGrupo(Grupo grupo){
    PtrNodoGrupo ptrNodo = new NodoGrupo;
    ptrNodo->grupo=grupo;
    ptrNodo->siguiente=finGrupo();

    return ptrNodo;

}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo adicionarAlPrincipio(ListaGrupo &lista,Grupo grupo){
PtrNodoGrupo ptrNodo=crearNodoGrupo(grupo);
ptrNodo->siguiente=lista.primero;
lista.primero=ptrNodo;

return ptrNodo;
}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo adicionarDespues(ListaGrupo &lista, Grupo grupo,PtrNodoGrupo ptrNodo){
PtrNodoGrupo ptrAux=finGrupo();
if(listaVaciaGrupo(lista)){
    adicionarAlPrincipio(lista,grupo);
}
if(ptrNodo!=finGrupo()){
    PtrNodoGrupo ptrAux=crearNodoGrupo(grupo);
    ptrAux->siguiente=ptrNodo->siguiente;
    ptrNodo->siguiente=ptrAux;
}
return ptrAux;
}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo adicionarFinal(ListaGrupo &lista,Grupo grupo){
return adicionarDespues(lista,grupo,ultimoListaGrupo(lista));

}
/*----------------------------------------------------------------------------*/
PtrNodoGrupo adicionarAntes(ListaGrupo &lista,Grupo grupo,PtrNodoGrupo ptrNodoGrupo){
PtrNodoGrupo ptrNodoNuevo=finGrupo();
 if(!listaVaciaGrupo(lista)){

     if(ptrNodoNuevo!=primeroListaGrupo(lista))
         ptrNodoNuevo=adicionarDespues(lista,grupo,anteriorListaGrupo(lista,ptrNodoNuevo));
      else
         ptrNodoNuevo=adicionarAlPrincipio(lista,grupo);
    }
    return ptrNodoNuevo;

}
/*----------------------------------------------------------------------------*/
 void colocarDato(ListaGrupo &lista,Grupo grupo, PtrNodoGrupo ptrNodoGrupo){
 if(!listaVaciaGrupo(lista) && ptrNodoGrupo!=finGrupo()){
    ptrNodoGrupo->grupo=grupo;
 }
 }
/*----------------------------------------------------------------------------*/
 void obtenerDato(ListaGrupo &lista, Grupo &grupo, PtrNodoGrupo ptrNodo) {

  if ((! listaVaciaGrupo(lista)) && (ptrNodo != finGrupo()))
    grupo = ptrNodo->grupo;
}

/*----------------------------------------------------------------------------*/
void eliminarNodo(ListaGrupo &lista, PtrNodoGrupo ptrNodo) {

  PtrNodoGrupo ptrPrevio;

  /* verifica que la lista no esté vacia y que nodo no sea fin*/
  if ((! listaVaciaGrupo(lista)) && (ptrNodo != finGrupo())) {

    if (ptrNodo == primeroListaGrupo(lista))
      lista.primero = siguienteListaGrupo(lista,primeroListaGrupo(lista));

    else {
      ptrPrevio = anteriorListaGrupo( lista , ptrNodo );
      ptrPrevio->siguiente = ptrNodo->siguiente;
    }
    // Si el dato es un TDA, acá habría que llamar al destructor.

    delete ptrNodo;
  }
}

/*----------------------------------------------------------------------------*/
void eliminarNodoPrimero(ListaGrupo &lista) {

  if (! listaVaciaGrupo(lista))
    eliminarNodo(lista,primeroListaGrupo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarNodoUltimo(ListaGrupo &lista) {

  if (! listaVaciaGrupo(lista))
    eliminarNodo(lista,ultimoListaGrupo(lista));
}

/*----------------------------------------------------------------------------*/
void eliminarLista(ListaGrupo &lista) {

  /* retira uno a uno los nodos de la lista */
  while (! listaVaciaGrupo(lista))
    eliminarNodo(lista,primeroListaGrupo(lista));
}

ResultadoComparacionGrupo compararDatoGrupo(Grupo grupo1, Grupo grupo2) {
    if (grupo1.id > grupo2.id) {
        return MAYOR_GRUPO;
    }
    else if (grupo1.id < grupo2.id) {
        return MENOR_GRUPO;
    }
    else {
        return IGUAL_GRUPO;
    }
}
/*----------------------------------------------------------------------------*/
/******************************************************************************/
