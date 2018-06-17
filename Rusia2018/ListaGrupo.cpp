#include "ListaGrupo.h"

#ifndef NULL
#define NULL      0
#endif



void crearListaGrupo(ListaGrupo &lista){
    lista.primero=finGrupo();
}

PtrNodoGrupo finGrupo(){
    return NULL;
}
bool listaVacia(ListaGrupo lista){
    return(lista.primero==finGrupo());
}

PtrNodoGrupo primeroListaGrupo(ListaGrupo &lista){
return lista.primero;
}
PtrNodoGrupo siguienteListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo){
    if(!listaVacia(lista) && ptrNodoGrupo->siguiente!=finGrupo()){

        return ptrNodoGrupo->siguiente;
        }
        else
            return finGrupo();

}
PtrNodoGrupo anteriorListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo){

PtrNodoGrupo ptrCursor = primeroListaGrupo(lista);
PtrNodoGrupo ptrAnterior;
    while(ptrCursor!=finGrupo() && ptrCursor!=ptrNodoGrupo){
        ptrAnterior=ptrCursor;
        ptrCursor=siguienteListaGrupo(lista,ptrCursor);
    }

    return ptrAnterior;

}
PtrNodoGrupo ultimoListaGrupo(ListaGrupo &lista){
return anteriorListaGrupo(lista,finGrupo());

}

PtrNodoGrupo crearNodoGrupo(Grupo grupo){
    PtrNodoGrupo ptrNodo = new NodoGrupo;
    ptrNodo->grupo=grupo;
    ptrNodo->siguiente=finGrupo();

    return ptrNodo;

}
PtrNodoGrupo adicionarAlPrincipio(ListaGrupo &lista,Grupo grupo){
PtrNodoGrupo ptrNodo=crearNodoGrupo(grupo);
ptrNodo->siguiente=lista.primero;
lista.primero=ptrNodo;

return ptrNodo;
}
PtrNodoGrupo adicionarDespues(ListaGrupo &lista, Grupo grupo,PtrNodoGrupo ptrNodo){
PtrNodoGrupo ptrAux=finGrupo();
if(listaVacia(lista)){
    adicionarAlPrincipio(lista,grupo);
}
if(ptrNodo!=finGrupo()){
    PtrNodoGrupo ptrAux=crearNodoGrupo(grupo);
    ptrAux->siguiente=ptrNodo->siguiente;
    ptrNodo->siguiente=ptrAux;
}
return ptrAux;
}
PtrNodoGrupo adicionarFinal(ListaGrupo &lista,Grupo grupo){
return adicionarDespues(lista,grupo,ultimoListaGrupo(lista));

}
PtrNodoGrupo adicionarAntes(ListaGrupo &lista,Grupo grupo,PtrNodoGrupo ptrNodoGrupo){
PtrNodoGrupo ptrNodoNuevo=finGrupo();
 if(!listaVacia(lista)){

     if(ptrNodoNuevo!=primeroListaGrupo(lista))
         ptrNodoNuevo=adicionarDespues(lista,grupo,anteriorListaGrupo(lista,ptrNodoNuevo));
      else
         ptrNodoNuevo=adicionarAlPrincipio(lista,grupo);
    }
    return ptrNodoNuevo;

}

 void colocarDato(ListaGrupo &lista,Grupo grupo, PtrNodoGrupo ptrNodoGrupo){
 if(!listaVacia(lista) && ptrNodoGrupo!=finGrupo()){
    ptrNodoGrupo->grupo=grupo;
 }
 }
