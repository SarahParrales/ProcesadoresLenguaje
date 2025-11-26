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
    pos = 0;
    for (int i = 0; i < MAX_SIMBOLOS; i++) {
        tablaDeSimbolos[i].nombre = NULL; //liberar memoria????
        tablaDeSimbolos[i].tipo = ENTERO; // valor por defecto
    }
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

void agregarVariableInicial(char * nombreVariable, NombreDeTipoT tipoVariable) {
    // Comprobar si ya existe
    if (buscarSimbolo(nombreVariable) != -1) {
        printf("Error: identificador '%s' ya declarado\n", nombreVariable);
        return; // no insertamos de nuevo
    }

    if (pos >= MAX_SIMBOLOS) {
        printf("Error: Tabla de simbolos llena\n");
        return;
    }

    // Inicializamos valor por defecto según el tipo
    LiteralT valorPorDefecto;
    switch(tipoVariable) {
        case ENTERO:
            valorPorDefecto = nuevoLiteralEntero(0);
            break;
        case REAL:
            valorPorDefecto = nuevoLiteralReal(0.0);
            break;
        case BOOLEANO:
            valorPorDefecto = nuevoLiteralBooleano(VERDADERO); // o FALSO si prefieres
            break;
        case CARACTER:
            valorPorDefecto = nuevoLiteralCaracter('\0');
            break;
        case CADENA:
            valorPorDefecto = nuevoLiteralCadena(""); // cadena vacía
            break;
        default:
            printf("Error: tipo desconocido al inicializar variable '%s'\n", nombreVariable);
            exit(1);
    }

    tablaDeSimbolos[pos].nombre = strdup(nombreVariable);
    tablaDeSimbolos[pos].tipo = tipoVariable;
    tablaDeSimbolos[pos].valor = valorPorDefecto;

    pos++;
}

void agregarVariableConValor(char *nombreVariable, NombreDeTipoT tipoVariable, LiteralT valor) {
    // Comprobar si ya existe
    if (buscarSimbolo(nombreVariable) != -1) {
        printf("Error: identificador '%s' ya declarado\n", nombreVariable);
        return; // no insertamos de nuevo
    }

    if (pos >= MAX_SIMBOLOS) {
        printf("Error: Tabla de símbolos llena\n");
        return;
    }

    // Comprobar que el tipo del valor coincide con el tipo declarado
    if (valor.tipoDelValor != tipoVariable) {
        printf("Error: tipo del valor no coincide con el tipo de la variable '%s'\n", nombreVariable);
        return;
    }

    tablaDeSimbolos[pos].nombre = strdup(nombreVariable);
    tablaDeSimbolos[pos].tipo = tipoVariable;
    tablaDeSimbolos[pos].valor = valor; // asignamos el valor recibido

    pos++;
}


//obtener valor con el nombre de la variable
LiteralT obtenerValor(const char *nombreVariable) {
    int idx = buscarSimbolo(nombreVariable);
    if(idx != -1) {
        return tablaDeSimbolos[idx].valor;
    } else {
        printf("Error: variable '%s' no declarada\n", nombreVariable);
        exit(1);
    }
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
        printf("Nombre: %s, Tipo: %s, Valor: ", 
               tablaDeSimbolos[i].nombre, 
               nombreDeTipoToString(tablaDeSimbolos[i].tipo));
        escribeLiteral(tablaDeSimbolos[i].valor);
    }
}


//OPERACIONES PARA EXPRESIONES: (+,-,*,/)

LiteralT divisionRealLiterales(LiteralT a, LiteralT b) {
    double va = (a.tipoDelValor == ENTERO) ? a.valor.valorEntero : a.valor.valorReal;
    double vb = (b.tipoDelValor == ENTERO) ? b.valor.valorEntero : b.valor.valorReal;

    return nuevoLiteralReal(va / vb);
}

LiteralT divisionEnteraLiterales(LiteralT a, LiteralT b) {
    if (a.tipoDelValor != ENTERO || b.tipoDelValor != ENTERO) {
        printf("Error: DIV solo acepta enteros\n");
        exit(1);
    }

    if (b.valor.valorEntero == 0) {
        printf("Error: división entre cero\n");
        exit(1);
    }

    return nuevoLiteralEntero(a.valor.valorEntero / b.valor.valorEntero);
}

LiteralT negarLiteral(LiteralT a) {
    if (a.tipoDelValor == ENTERO)
        return nuevoLiteralEntero(-a.valor.valorEntero);
    else if (a.tipoDelValor == REAL)
        return nuevoLiteralReal(-a.valor.valorReal);

    printf("Error: negación aritmética solo admite enteros o reales\n");
    exit(1);
}

LiteralT sumarLiterales(LiteralT a, LiteralT b) {
    if (a.tipoDelValor == ENTERO && b.tipoDelValor == ENTERO)
        return nuevoLiteralEntero(a.valor.valorEntero + b.valor.valorEntero);

    // Promoción automática a real
    double va = (a.tipoDelValor == ENTERO) ? a.valor.valorEntero : a.valor.valorReal;
    double vb = (b.tipoDelValor == ENTERO) ? b.valor.valorEntero : b.valor.valorReal;

    return nuevoLiteralReal(va + vb);
}

LiteralT restarLiterales(LiteralT a, LiteralT b) {
    double va = (a.tipoDelValor == ENTERO) ? a.valor.valorEntero : a.valor.valorReal;
    double vb = (b.tipoDelValor == ENTERO) ? b.valor.valorEntero : b.valor.valorReal;

    if (a.tipoDelValor == ENTERO && b.tipoDelValor == ENTERO)
        return nuevoLiteralEntero(a.valor.valorEntero - b.valor.valorEntero);

    return nuevoLiteralReal(va - vb);
}

LiteralT multiplicarLiterales(LiteralT a, LiteralT b) {
    double va = (a.tipoDelValor == ENTERO) ? a.valor.valorEntero : a.valor.valorReal;
    double vb = (b.tipoDelValor == ENTERO) ? b.valor.valorEntero : b.valor.valorReal;

    if (a.tipoDelValor == ENTERO && b.tipoDelValor == ENTERO)
        return nuevoLiteralEntero(a.valor.valorEntero * b.valor.valorEntero);

    return nuevoLiteralReal(va * vb);
}

LiteralT moduloLiterales(LiteralT a, LiteralT b) {
    if (a.tipoDelValor != ENTERO || b.tipoDelValor != ENTERO) {
        printf("Error: MOD solo acepta enteros\n");
        exit(1);
    }

    return nuevoLiteralEntero(a.valor.valorEntero % b.valor.valorEntero);
}

//operaciones para asignacion:

void asignarValor(const char* nombreVariable, LiteralT valor) {
    int idx = buscarSimbolo(nombreVariable);
    if (idx == -1) {
        printf("Error: variable '%s' no declarada\n", nombreVariable);
        exit(1);
    }
    tablaDeSimbolos[idx].valor = valor;
}

