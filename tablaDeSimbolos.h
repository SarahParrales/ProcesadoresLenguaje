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
    LiteralT valor; // valor actual de la variable
} CeldaSimbolos;

extern CeldaSimbolos tablaDeSimbolos[MAX_SIMBOLOS];
extern int pos;

// Inicializa/reinicia la tabla de símbolos
void nuevaTablaDeSimbolos(void);
// Busca un símbolo por nombre; devuelve índice o -1 si no existe
int buscarSimbolo(const char *);
// Agrega una variable con valor por defecto según su tipo
void agregarVariableInicial(char *, NombreDeTipoT );
// Agrega una variable con valor específico
void agregarVariableConValor(char *, NombreDeTipoT , LiteralT );
// Obtiene el valor de una variable por su nombre
LiteralT obtenerValor(const char *);
// Actualiza el valor de una variable existente
void actualizarValor(const char *, LiteralT );
// Convierte un NombreDeTipoT a string
const char* nombreDeTipoToString(NombreDeTipoT );
// Imprime la tabla de símbolos completa
void imprimirTabla(void);

//para exp_a:
LiteralT sumarLiterales(LiteralT a, LiteralT b);
LiteralT restarLiterales(LiteralT a, LiteralT b);
LiteralT multiplicarLiterales(LiteralT a, LiteralT b);
LiteralT divisionRealLiterales(LiteralT a, LiteralT b);
LiteralT divisionEnteraLiterales(LiteralT a, LiteralT b);
LiteralT moduloLiterales(LiteralT a, LiteralT b);
LiteralT negarLiteral(LiteralT a);

//para asignacion
void asignarValor(const char* , LiteralT );

#endif