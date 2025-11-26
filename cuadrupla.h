#ifndef CUADRUPLA_H
#define CUADRUPLA_H
#include "nombresDeTipos.h"

#define MAX_CUADRUPLAS 1000
#define MAX_TEMP 100

typedef enum {
    SUMAENT, SUMAREAL,
    RESTAENT, RESTAREAL,
    MULTENT, MULTREAL,
    DIVENT, DIVREAL,
    ASIGNACION,
    SALTO,
    MODULO
} OperadorT;

typedef struct {
    int tabla[MAX_CUADRUPLAS][4];
    int nextquad;
} Cuadrupla;

extern Cuadrupla listaCuadruplas;
extern int numCuadruplas;

void inicializarCuadruplas();
void gen(OperadorT op, int arg1, int arg2, int resultado);
int newTemp(NombreDeTipoT tipo);
void imprimirCuadruplas();
void imprimirCuadruplasCompacto();
void resetCuadruplas();
int getNextQuad();
void modificarCuadrupla(int pos, int campo, int valor);
OperadorT obtenerOperador(int pos);
OperadorT determinarOperador(const char* operacion, int id1, int id2);

#endif