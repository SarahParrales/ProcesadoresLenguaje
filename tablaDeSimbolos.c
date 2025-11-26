#include "tablaDeSimbolos.h"
#include "nombresDeTipos.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Variables globales
CeldaSimbolos tablaDeSimbolos[MAX_SIMBOLOS];
int pos = 0;

// Función para inicializar/reiniciar la tabla
void nuevaTablaDeSimbolos(void) {
    for (int i = 0; i < pos; i++) {
        if (tablaDeSimbolos[i].nombre != NULL) {
            free(tablaDeSimbolos[i].nombre);
            tablaDeSimbolos[i].nombre = NULL;
            tablaDeSimbolos[i].tipo = ENTERO; // valor por defecto
        }
    }
    pos = 0;
}

//para la comprobacion de simbolo en la tabla y evitar duplicado
int buscarSimbolo(const char *nombre) {
    for (int i = 0; i < pos; i++) {
        if (strcmp(tablaDeSimbolos[i].nombre, nombre) == 0) {
            return i; // encontrado
        }
    }
    return -1; // no encontrado
}

// Obtener tipo con el nombre de la variable
NombreDeTipoT obtenerTipo(const char *nombre) {
    int idx = buscarSimbolo(nombre);
    if (idx != -1) {
        return tablaDeSimbolos[idx].tipo;
    } else {
        printf("Error: variable '%s' no declarada\n", nombre);
        exit(1);
    }
}

// Obtener tipo por índice
NombreDeTipoT obtenerTipoPorIndice(int indice) {
    if (indice < 0 || indice >= pos) {
        printf("Error: índice %d fuera de rango en tabla de símbolos\n", indice);
        exit(1);
    }
    return tablaDeSimbolos[indice].tipo;
}

// Obtener nombre por índice
const char* obtenerNombrePorIndice(int indice) {
    if (indice < 0 || indice >= pos) {
        printf("Error: índice %d fuera de rango en tabla de símbolos\n", indice);
        exit(1);
    }
    return tablaDeSimbolos[indice].nombre;
}

int agregarVariable(char * nombreVariable, NombreDeTipoT tipoVariable) {
    // Comprobar si ya existe
    int idx = buscarSimbolo(nombreVariable);
    if (idx != -1) {
        printf("Error: identificador '%s' ya declarado\n", nombreVariable);
        return idx; // retornamos el índice existente
    }

    if (pos >= MAX_SIMBOLOS) {
        printf("Error: Tabla de simbolos llena\n");
        exit(1);
    }

    tablaDeSimbolos[pos].nombre = strdup(nombreVariable);
    tablaDeSimbolos[pos].tipo = tipoVariable;
    return pos++;
}


// Convierte un NombreDeTipoT a string
const char* nombreDeTipoToString(NombreDeTipoT tipo) {
    switch (tipo) {
        case BOOLEANO: return "Booleano";
        case CADENA: return "Cadena";
        case CARACTER: return "Caracter";
        case ENTERO: return "Entero";
        case REAL: return "Real";
        default: return "Desconocido";
    }
}

// Imprime la tabla completa
void imprimirTabla() {
    printf("\nTabla de Símbolos:\n");
    for(int i = 0; i < pos; i++) {
        printf("Nombre: %s, Tipo: %s ", 
               tablaDeSimbolos[i].nombre, 
               nombreDeTipoToString(tablaDeSimbolos[i].tipo));
        printf("\n");
    }
}


//OPERACIONES PARA EXPRESIONES: (+,-,*,/)


