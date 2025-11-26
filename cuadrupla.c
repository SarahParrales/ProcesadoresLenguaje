#include "cuadrupla.h"
#include "tablaDeSimbolos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Variables globales
Cuadrupla listaCuadruplas;
int numCuadruplas = 0;
static int contadorTemp = 0;

// Nombres de operadores para imprimir
const char* nombreOperador[] = {
    "SUMAENT", "SUMAREAL", "RESTAENT", "RESTAREAL",
    "MULTENT", "MULTREAL", "DIVENT", "DIVREAL",
    "ASIGNACION", "SALTO"
};

/**
 * Inicializa la estructura de cuádruplas
 */
void inicializarCuadruplas() {
    numCuadruplas = 0;
    contadorTemp = 0;
    listaCuadruplas.nextquad = 0;
    
    // Inicializar la tabla a -1 (indica vacío)
    for (int i = 0; i < MAX_CUADRUPLAS; i++) {
        for (int j = 0; j < 4; j++) {
            listaCuadruplas.tabla[i][j] = -1;
        }
    }
}

/**
 * Genera una nueva cuádrupla y la añade a la tabla
 * @param op: operador de la operación
 * @param arg1: ID del primer argumento en la tabla de símbolos (-1 si no se usa)
 * @param arg2: ID del segundo argumento en la tabla de símbolos (-1 si no se usa)
 * @param resultado: ID del resultado en la tabla de símbolos (-1 si no se usa)
 */
void gen(OperadorT op, int arg1, int arg2, int resultado) {
    if (numCuadruplas >= MAX_CUADRUPLAS) {
        fprintf(stderr, "Error: Se excedió el límite de cuádruplas (%d)\n", MAX_CUADRUPLAS);
        exit(1);
    }
    
    // Guardar en formato tabla[fila][columna]
    listaCuadruplas.tabla[numCuadruplas][0] = (int)op;
    listaCuadruplas.tabla[numCuadruplas][1] = arg1;
    listaCuadruplas.tabla[numCuadruplas][2] = arg2;
    listaCuadruplas.tabla[numCuadruplas][3] = resultado;
    
    numCuadruplas++;
    listaCuadruplas.nextquad = numCuadruplas;
}

/**
 * Genera un nuevo temporal, lo registra en la tabla de símbolos
 * y retorna su ID en la tabla
 * @param tipo: tipo del temporal (ENTERO, REAL, etc.)
 * @return: ID del temporal en la tabla de símbolos
 */
int newTemp(NombreDeTipoT tipo) {
    char temp[20];
    
    if (contadorTemp >= MAX_TEMP) {
        fprintf(stderr, "Error: Se excedió el límite de temporales (%d)\n", MAX_TEMP);
        exit(1);
    }
    
    // Generar nombre del temporal
    sprintf(temp, "T%d", contadorTemp);
    contadorTemp++;
    
    // Agregar el temporal a la tabla de símbolos
    agregarVariable(temp, tipo);
    
    // Buscar y retornar su ID
    int id = buscarSimbolo(temp);
    if (id == -1) {
        fprintf(stderr, "Error: No se pudo agregar temporal %s a la tabla de símbolos\n", temp);
        exit(1);
    }
    
    return id;
}

/**
 * Obtiene el número actual de cuádruplas (útil para saltos y etiquetas)
 */
int getNextQuad() {
    return listaCuadruplas.nextquad;
}

/**
 * Modifica una cuádrupla existente (útil para backpatching de saltos)
 * @param pos: posición de la cuádrupla a modificar
 * @param campo: campo a modificar (0=op, 1=arg1, 2=arg2, 3=resultado)
 * @param valor: nuevo valor
 */
void modificarCuadrupla(int pos, int campo, int valor) {
    if (pos < 0 || pos >= numCuadruplas) {
        fprintf(stderr, "Error: Posición %d fuera de rango\n", pos);
        return;
    }
    if (campo < 0 || campo > 3) {
        fprintf(stderr, "Error: Campo %d inválido (debe ser 0-3)\n", campo);
        return;
    }
    
    listaCuadruplas.tabla[pos][campo] = valor;
}

/**
 * Imprime todas las cuádruplas generadas con nombres de variables
 */
void imprimirCuadruplas() {
    printf("\nTabla de Cuadrupla \n");
    printf("%-5s | %-12s | %-15s | %-15s | %-15s\n", 
           "Num", "Operador", "Arg1", "Arg2", "Resultado");
    printf("--------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < numCuadruplas; i++) {
        OperadorT op = (OperadorT)listaCuadruplas.tabla[i][0];
        int arg1 = listaCuadruplas.tabla[i][1];
        int arg2 = listaCuadruplas.tabla[i][2];
        int resultado = listaCuadruplas.tabla[i][3];
        
        // Obtener nombres de las variables desde la tabla de símbolos
        const char* nombreArg1 = (arg1 >= 0) ? obtenerNombrePorIndice(arg1) : "-";
        const char* nombreArg2 = (arg2 >= 0) ? obtenerNombrePorIndice(arg2) : "-";
        const char* nombreRes = (resultado >= 0) ? obtenerNombrePorIndice(resultado) : "-";
        
        printf("%-5d | %-12s | %-15s | %-15s | %-15s\n", 
               i, 
               nombreOperador[op], 
               nombreArg1, 
               nombreArg2, 
               nombreRes);
    }

}

/**
 * Imprime las cuádruplas en formato compacto (solo IDs)
 */
void imprimirCuadruplasCompacto() {
    printf("\n=== CUÁDRUPLAS (FORMATO COMPACTO) ===\n");
    printf("%-5s | %-3s | %-5s | %-5s | %-5s\n", 
           "Num", "Op", "Arg1", "Arg2", "Res");
    printf("----------------------------------------\n");
    
    for (int i = 0; i < numCuadruplas; i++) {
        printf("%-5d | %-3d | %-5d | %-5d | %-5d\n", 
               i,
               listaCuadruplas.tabla[i][0],
               listaCuadruplas.tabla[i][1],
               listaCuadruplas.tabla[i][2],
               listaCuadruplas.tabla[i][3]);
    }
    printf("========================================\n\n");
}

/**
 * Reinicia el contador de cuádruplas (útil para múltiples compilaciones)
 */
void resetCuadruplas() {
    numCuadruplas = 0;
    contadorTemp = 0;
    listaCuadruplas.nextquad = 0;
    
    // Limpiar la tabla
    for (int i = 0; i < MAX_CUADRUPLAS; i++) {
        for (int j = 0; j < 4; j++) {
            listaCuadruplas.tabla[i][j] = -1;
        }
    }
}

/**
 * Obtiene el operador de una cuádrupla
 */
OperadorT obtenerOperador(int pos) {
    if (pos < 0 || pos >= numCuadruplas) {
        fprintf(stderr, "Error: Posición %d fuera de rango\n", pos);
        exit(1);
    }
    return (OperadorT)listaCuadruplas.tabla[pos][0];
}

/**
 * Función auxiliar para determinar el tipo de operador según los operandos
 * Útil para generar el operador correcto (SUMAENT vs SUMAREAL, etc.)
 */
OperadorT determinarOperador(const char* operacion, int id1, int id2) {
    NombreDeTipoT tipo1 = obtenerTipoPorIndice(id1);
    NombreDeTipoT tipo2 = obtenerTipoPorIndice(id2);
    
    // Si alguno es REAL, el resultado es REAL
    int esReal = (tipo1 == REAL || tipo2 == REAL);
    
    if (strcmp(operacion, "+") == 0) {
        return esReal ? SUMAREAL : SUMAENT;
    } else if (strcmp(operacion, "-") == 0) {
        return esReal ? RESTAREAL : RESTAENT;
    } else if (strcmp(operacion, "*") == 0) {
        return esReal ? MULTREAL : MULTENT;
    } else if (strcmp(operacion, "/") == 0) {
        return esReal ? DIVREAL : DIVENT;
    }
    
    fprintf(stderr, "Error: Operación '%s' no reconocida\n", operacion);
    exit(1);
}