#ifndef TABLADESIMBOLOS_H
#define TABLADESIMBOLOS_H

#include "nombresDeTipos.h"
#include "literal.h"

// Definimos un tamaño máximo para la tabla (puedes ajustar este número)
#define MAX_SIMBOLOS 100

// Estructura que define cada entrada de la tabla
typedef struct {
    char * nombre;  // nombre de la variable
    NombreDeTipoT tipo;     // tipo de la variable
} CeldaSimbolos;

extern CeldaSimbolos tablaDeSimbolos[MAX_SIMBOLOS];
extern int pos;

// Inicializa/reinicia la tabla de símbolos
void nuevaTablaDeSimbolos(void);
// Busca un símbolo por nombre; devuelve índice o -1 si no existe
int buscarSimbolo(const char *);
// Agrega una variable con valor por defecto según su tipo
int agregarVariable(char *, NombreDeTipoT );

// Obtiene el tipo de una variable por su nombre
NombreDeTipoT obtenerTipo(const char *nombre);
// Obtiene el tipo de una variable por su índice
NombreDeTipoT obtenerTipoPorIndice(int indice);
// Obtiene el nombre de una variable por su índice
const char* obtenerNombrePorIndice(int indice);

// Convierte un NombreDeTipoT a string
const char* nombreDeTipoToString(NombreDeTipoT );
// Imprime la tabla de símbolos completa
void imprimirTabla(void);

#endif