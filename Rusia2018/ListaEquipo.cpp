#include "ListaEquipo.h"

#ifndef NULL
#define NULL      0
#endif



void crearListaEquipo(ListaEquipo &lista){
lista.primero=finEquipo();

}

bool listaVaciaEquipo(ListaEquipo &lista){
return(lista.primero==finEquipo());
}

PtrNodoListaEquipo listaPrimeroEquipo(ListaEquipo &lista){
return lista.primero;
}

PtrNodoListaEquipo finEquipo() {
  return NULL;
}

PtrNodoListaEquipo siguienteEquipo(ListaEquipo &lista, PtrNodoListaEquipo ptrNodo){
if((!listaVaciaEquipo(lista)) && (ptrNodo->siguiente!=finEquipo())){
    return ptrNodo->siguiente;
}
else
    return finEquipo();

}
PtrNodoListaEquipo anteriorEquipo(ListaEquipo &lista,PtrNodoListaEquipo ptrNodo){
PtrNodoListaEquipo ptrAnterior;
PtrNodoListaEquipo ptrCursor=listaPrimeroEquipo(lista);

while(ptrCursor!=finEquipo() && ptrCursor !=ptrNodo){

    ptrAnterior=ptrCursor;
    ptrCursor=siguienteEquipo(lista,ptrCursor);

}
return ptrAnterior;

}

PtrNodoListaEquipo ultimoEquipo(ListaEquipo &lista){
return anteriorEquipo(lista,finEquipo());
}

PtrNodoListaEquipo crearNodoLista(Equipo equipo){
PtrNodoListaEquipo ptrNodo = new NodoListaEquipo;
ptrNodo->equipo=equipo;
ptrNodo->siguiente=finEquipo();

return ptrNodo;
}

PtrNodoListaEquipo adicionarAlPrincipio(ListaEquipo &lista, Equipo equipo){
PtrNodoListaEquipo ptrNodo = crearNodoLista(equipo);

ptrNodo->siguiente=lista.primero;
lista.primero=ptrNodo;

return ptrNodo;
}

PtrNodoListaEquipo adicionarDespues(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo){

PtrNodoListaEquipo ptrAux = finEquipo();
if(listaVaciaEquipo(lista)){
    adicionarAlPrincipio(lista,equipo);
    }
   if(ptrNodo!=finEquipo()){

    ptrAux=crearNodoLista(equipo);

    ptrAux->siguiente=ptrNodo->siguiente;
    ptrNodo->siguiente=ptrAux;
   }

    return ptrAux;

 }

 PtrNodoListaEquipo adicionarFinal(ListaEquipo &lista,Equipo equipo){

 return adicionarDespues(lista,equipo,ultimoEquipo(lista));
   }

 PtrNodoListaEquipo adicionarAntes(ListaEquipo &lista, Equipo equipo, PtrNodoListaEquipo ptrNodo){
 PtrNodoListaEquipo ptrNodoNuevo=finEquipo();
 if(!listaVaciaEquipo(lista)){

     if(ptrNodo!=listaPrimeroEquipo(lista))
         ptrNodoNuevo=adicionarDespues(lista,equipo,anteriorEquipo(lista,ptrNodo));
      else
         ptrNodoNuevo=adicionarAlPrincipio(lista,equipo);
    }
    return ptrNodoNuevo;

 }

 void colocarDato(ListaEquipo &lista,Equipo equipo, PtrNodoListaEquipo ptrNodo){
 if(!listaVaciaEquipo(lista) && ptrNodo!=finEquipo()){
    ptrNodo->equipo=equipo;
 }
 }

