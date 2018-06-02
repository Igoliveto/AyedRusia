#include "ListaEquipo.h"

#ifndef NULL
#define NULL      0
#endif



void crearLista(Lista &lista){
lista.primero=fin();

}

bool listaVacia(Lista &lista){
return(lista.primero==fin());
}

PtrNodoLista listaPrimero(Lista &lista){
return lista.primero;
}

PtrNodoLista fin() {
  return NULL;
}

PtrNodoLista siguiente(Lista &lista, PtrNodoLista ptrNodo){
if((!listaVacia(lista)) && (ptrNodo->siguiente!=fin())){
    return ptrNodo->siguiente;
}
else
    return fin();

}
PtrNodoLista anterior(Lista &lista,PtrNodoLista ptrNodo){
PtrNodoLista ptrAnterior;
PtrNodoLista ptrCursor=listaPrimero(lista);

while(ptrCursor!=fin() && ptrCursor !=ptrNodo){

    ptrAnterior=ptrCursor;
    ptrCursor=siguiente(lista,ptrCursor);

}
return ptrAnterior;

}

PtrNodoLista ultimo(Lista &lista){
return anterior(lista,fin());
}

PtrNodoLista crearNodoLista(Equipo equipo){
PtrNodoLista ptrNodo = new NodoLista;
ptrNodo->equipo=equipo;
ptrNodo->siguiente=fin();

return ptrNodo;
}

PtrNodoLista adicionarAlPrincipio(Lista &lista, Equipo equipo){
PtrNodoLista ptrNodo = crearNodoLista(equipo);

ptrNodo->siguiente=lista.primero;
lista.primero=ptrNodo;

return ptrNodo;
}

PtrNodoLista adicionarDespues(Lista &lista, Equipo equipo, PtrNodoLista ptrNodo){

PtrNodoLista ptrAux = fin();
if(listaVacia(lista)){
    adicionarAlPrincipio(lista,equipo);
    }
   if(ptrNodo!=fin()){

    ptrAux=crearNodoLista(equipo);

    ptrAux->siguiente=ptrNodo->siguiente;
    ptrNodo->siguiente=ptrAux;
   }

    return ptrAux;

 }

 PtrNodoLista adicionarFinal(Lista &lista,Equipo equipo){

 return adicionarDespues(lista,equipo,ultimo(lista));
   }

 PtrNodoLista adicionarAntes(Lista &lista, Equipo equipo, PtrNodoLista ptrNodo){
 PtrNodoLista ptrNodoNuevo=fin();
 if(!listaVacia(lista)){

     if(ptrNodo!=listaPrimero(lista))
         ptrNodoNuevo=adicionarDespues(lista,equipo,anterior(lista,ptrNodo));
      else
         ptrNodoNuevo=adicionarAlPrincipio(lista,equipo);
    }
    return ptrNodoNuevo;

 }

 void colocarDato(Lista &lista,Equipo equipo, PtrNodoLista ptrNodo){
 if(!listaVacia(lista) && ptrNodo!=fin()){
    ptrNodo->equipo=equipo;
 }
 }

