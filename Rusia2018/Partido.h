#ifndef _PARTIDO_H
#define _PARTIDO_H


#ifndef NULL
#define NULL      0
#endif


typedef struct{
    int id;
    int idEquipoL;
    int idEquipoV;
    int golesL;
    int golesV;
}Partido;

void crearPartido(Partido &partido, int id, int idEquipoL, int idEquipoV);
int getId(Partido &partido);
int getIdEquipoL(Partido &partido);
int getIdEquipoV(Partido &partido);
void setId(Partido &partido,int id);
void setIdEquipoL(Partido &partido, int idEquipoL);
void setIdEquipoV(Partido &partido, int idEquipoV);

#endif // _PARTIDO_H
