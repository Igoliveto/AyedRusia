#ifndef _LISTAGRUPO_H_
#define _LISTAGRUPO_H_
#include "Grupo.h"

struct NodoGrupo{
Grupo grupo;
NodoGrupo* siguiente;
};
typedef NodoGrupo* PtrNodoGrupo;

struct ListaGrupo{
PtrNodoGrupo primero;
};
void crearListaGrupo(ListaGrupo &lista);
PtrNodoGrupo finGrupo();
bool listaVacia(ListaGrupo lista);
PtrNodoGrupo primeroListaGrupo(ListaGrupo &lista);
PtrNodoGrupo siguienteListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo);
PtrNodoGrupo anteriorListaGrupo(ListaGrupo &lista,PtrNodoGrupo ptrNodoGrupo);
PtrNodoGrupo ultimoListaGrupo(ListaGrupo &lista);
PtrNodoGrupo crearNodoGrupo(Grupo grupo);
PtrNodoGrupo adicionarAlPrincipio(ListaGrupo &lista,Grupo grupo);
PtrNodoGrupo adicionarDespues(ListaGrupo &lista, Grupo grupo,PtrNodoGrupo ptrNodo);
PtrNodoGrupo adicionarFinal(ListaGrupo &lista,Grupo grupo);
PtrNodoGrupo adicionarAntes(ListaGrupo &lista,Grupo grupo,PtrNodoGrupo ptrNodoGrupo);
void colocarDato(ListaGrupo &lista,Grupo grupo, PtrNodoGrupo ptrNodoGrupo);
#endif // _LISTAGRUPO_H
