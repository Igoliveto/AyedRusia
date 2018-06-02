#include <iostream>
#include "Equipo.h"
#include <stdlib.h>
#include <string>
using namespace std;
void alta();
int main()
{
    int opcion=0;
    cout<<"1_Alta"<<endl;
    cout<<"2_Baja"<<endl;
    cout<<"3_Modificacion"<<endl;
    cin>>opcion;
     switch(opcion){
     case 1: alta();




     }
    return 0;
}

void alta(){
Equipo equipo;
string nombre;
int id=0;
cout<<"ingrese id :"<<endl;
cin>>id;
cout<<"ingrese nombre del equipo :"<<endl;
cin>>nombre;
crearEquipo(equipo,id,nombre);
cout<<getNombre(equipo)<<endl;
system("pause");
};
