#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tablaDeConstantes.h"


TablaDeConstantes nuevaTablaDeConstantes() {
    return (Celda *) NULL;
}

bool insertaConstante(TablaDeConstantes * ptc, char * pnombre, LiteralT v){
    Celda * c;
    c = *ptc;
    while (c != NULL && strcmp(pnombre, c->nombre))
        c = c->sig;
    if (c != NULL)
        printf("Ya existe una constante llamada %s\n", pnombre);
    else {
        if ((c = (Celda *) malloc(sizeof(Celda))) == NULL) {
            printf("No hay memoria para una celda de la tabla de constantes");
            exit(1);
        } 
        c->nombre = strdup(pnombre);
        c->valor = v;
        c->sig = *ptc;
        *ptc = c;
    }
}

LiteralT* buscarConstante(TablaDeConstantes tc, char* nombre) {
    // Iterar sobre la lista enlazada
    for (Celda *actual = tc; actual != NULL; actual = actual->sig) {
        if (strcmp(actual->nombre, nombre) == 0) {
            return &(actual->valor);
        }
    }
    return NULL; 
}

void imprimeTablaDeConstantes(TablaDeConstantes tc){
    Celda * aux = tc;
    if (tc == NULL) {
        printf("La tabla de constantes está vacía\n");
    } else {
        printf("\nTabla de Constantes:\n");
        printf("Nombre\t\tTipo\t\tValor\n");
        while (aux != NULL){
            printf("%s\t\t", aux->nombre);
            escribeLiteral(aux->valor);
            aux = aux->sig;
        }
    }
}

