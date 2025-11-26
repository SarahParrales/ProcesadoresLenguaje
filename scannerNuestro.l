 //GRUPO 1-13: SARAH PARRALES GOMEZ Y JON IKER ORMAETXEA NUNES
 //PARTE 1: ZONA DE DECLARACIONES
 //PARTE 1.1: Constantes manifiestas y codigo necesario para el .c que genera flex 

%{
	// Headers standard necesarios
	#include <stdio.h> //Para poder escribir en el terminal
	#include <stdlib.h> //Para usar exit()
	#include <strings.h> //Para trabajar con cadenas de caracteres
	
	// Headers creados para este ejemplo
	#include "nombresDeTipos.h" // Para saber los nombres de los tipos
	#include "literal.h" //Para poder usar el tipo Literal
	#include "parserNuestro.tab.h" // Lo crea automaticamente bison con la opcion -v
	
	void errorEnScanner(char*, char*); //prototipo necesario para compilar
	
%}

 // PARTE 1.2: Zona de definiciones regulares
MAS_D           \+
MENOS_D         \-

LETRA_D      [A-Za-z]
CIFRA_D       [0-9]
LETRAOCIFRA_D   {LETRA_D}|{CIFRA_D}
CARACTERBLANCO_D    [ \t\n]+
IDBOOLEANO_D     [bB]{LETRAOCIFRA_D}*
ID_D             {LETRA_D}{LETRAOCIFRA_D}*


 //literales
LITERAL_ENTERO_D      [+-]?[0-9]+
LITERAL_REAL_D        [+-]?[0-9]*(\.[0-9]+)?([eE][+-]?[0-9]+)?|([+-]?[0-9]+)[rR]
LITERAL_BOOLEANO_D      (?i:verdadero|falso)
LITERAL_CARACTER_D  	\".\"  
LITERAL_CADENA_D    '([^']|\\')*'


CONSTANTE_D			[A-Z][A-Z_]*

 //palabras reservadas
ACCION_D           (?i:accion)
ALGORITMO_D        (?i:algoritmo)
BOOLEANO_D         (?i:booleano)
CADENA_D           (?i:cadena)
CARACTER_D         (?i:caracter)
CONST_D            (?i:const)
CONTINUAR_D        (?i:continuar)
DE_D               (?i:de)
DEV_D              (?i:dev)
DIV_D              (?i:div)
ENT_D              (?i:ent)
ENTERO_D           (?i:entero)
E_S_D              (?i:e\/s)
FACCION_D          (?i:faccion)
FALGORITMO_D       (?i:falgoritmo)
FALSO_D            (?i:falso)
FCONST_D           (?i:fconst)
FFUNCION_D         (?i:ffuncion)
FMIENTRAS_D        (?i:fmientras)
FPARA_D            (?i:fpara)
FSI_D              (?i:fsi)
FTIPO_D            (?i:ftipo)
FTUPLA_D           (?i:ftupla)
FUNCION_D          (?i:funcion)
FVAR_D             (?i:fvar)
HACER_D            (?i:hacer)
HASTA_D            (?i:hasta)
MIENTRAS_D         (?i:mientras)
MOD_D              (?i:mod)
NO_D               (?i:no)
O_D               (?i:o)
PARA_D             (?i:para)
REAL_D             (?i:real)
REF_D              (?i:ref)
SAL_D              (?i:sal)
SI_D               (?i:si)
TABLA_D            (?i:tabla)
TIPO_D             (?i:tipo)
TUPLA_D            (?i:tupla)
VAR_D              (?i:var)
VERDADERO_D        (?i:verdadero)
Y_D             	(?i:y)


POSTCONDICION_D		\{Post:[^}]*\}
PRECONDICION_D      \{Prec:[^}]*\}


 //otros posibles tokens logicos
ASIGNACION_D            :=
PUNTOYCOMA_D   			 ;
DOSPUNTOS_D               :
ENTONCES_D              ->
SINO_SI_D               \[\]
IGUAL_D         		 =
INICIO_ARRAY_D   \[
CIERRE_ARRAY_D	\]


MULTIPLICACION_D           \*
DIVREAL_D       \/
MAYORIGUAL_D     >=
MENORIGUAL_D     <=
MAYOR_D          >
MENOR_D          <
DISTINTO_D       <>
COMA_D           ,
LLAVE_APERTURA_D    \{
LLAVE_CIERRE_D  	\}
PUNTO_D        	 \.
PARENTESIS_APERTURA_D   \(
PARENTESIS_CIERRE_D  \)


%%
 //PARTE 2: Reglas


{MAS_D} {  
    return MAS_TK;
}

{MENOS_D} {  
    return MENOS_TK;
}

{Y_D} {
    return Y_TK;
}

{O_D} {
    return O_TK;
}


{LITERAL_ENTERO_D}	{  
	printf("DEBUG entero: %s\n", yytext);
    yylval.literal.tipoDelValor = ENTERO;
    yylval.literal.valor.valorEntero = atoi(yytext);
    return LITERAL_ENTERO_TK;}

{LITERAL_REAL_D}	{  
	char * cadena;
	if (yytext[strlen(yytext)-1] == 'r' || yytext[strlen(yytext)-1] == 'R') {
        yytext[strlen(yytext)-1] = '\0'; // Eliminar el 'r' o 'R' al final
    }

    if ((cadena = strndup(yytext, strlen(yytext))) == NULL) 
        errorEnScanner("No hay memoria para strndup() al leer %s\n", yytext);
    else {
        yylval.literal.tipoDelValor = REAL;
	    yylval.literal.valor.valorReal = atof(cadena);
        free(cadena); // Liberar la memoria reservada
	    return LITERAL_REAL_TK;
    }

    
}

{LITERAL_CADENA_D}	{  //'hola'
    yylval.literal.tipoDelValor = CADENA;
	//Es necesario reservar memoria para la cadena. No puedo usar la de yytext.
	//En partes posteriores se tendra en cuenta que esta cadena tiene memoria
	//propia. Para usar strdup es necesario importar etring.h
	if ((yylval.literal.valor.valorCadena = strdup(yytext)) == NULL )
		errorEnScanner("No hay memoria para strdup() al leer %s\n", yytext);
	else
		return LITERAL_CADENA_TK;
}
{LITERAL_CARACTER_D}	{  //"b"
    yylval.literal.tipoDelValor = CARACTER;
	yylval.literal.valor.valorCaracter = yytext[1];
	return LITERAL_CARACTER_TK;
}

{LITERAL_BOOLEANO_D} {
    yylval.literal.tipoDelValor = BOOLEANO;  // tipo definido en literal.h
    if (strcasecmp(yytext, "verdadero") == 0) {
        yylval.literal.valor.valorBooleano = VERDADERO;  // constante definida en literal.h
    } else {
        yylval.literal.valor.valorBooleano = FALSO;      // constante definida en literal.h
    }
    return LITERAL_BOOLEANO_TK;
}

{ACCION_D} {
	return ACCION_TK;
}

{ALGORITMO_D} {
	return ALGORITMO_TK;
}

{BOOLEANO_D} {
	return BOOLEANO_TK;
}

{CADENA_D} {
	return CADENA_TK;
}

{CARACTER_D} {
	return CARACTER_TK;
}

{CONST_D} {
	return CONST_TK;
}

{CONTINUAR_D} {
	return CONTINUAR_TK;
}

{DE_D} {
	return DE_TK;
}

{DEV_D} {
	return DEV_TK;
}

{DIV_D} {
	return DIV_TK;
}

{ENT_D} {
	return ENT_TK;
}

{ENTERO_D} {
	return ENTERO_TK;
}

{E_S_D} {
	return E_S_TK;
}

{FACCION_D} {
	return FACCION_TK;
}

{FALGORITMO_D} {
	return FALGORITMO_TK;
}

{FCONST_D} {
	return FCONST_TK;
}

{FFUNCION_D} {
	return FFUNCION_TK;
}

{FMIENTRAS_D} {
	return FMIENTRAS_TK;
}

{FPARA_D} {
	return FPARA_TK;
}

{FSI_D} {
	return FSI_TK;
}

{FTIPO_D} {
	return FTIPO_TK;
}

{FTUPLA_D} {
	return FTUPLA_TK;
}

{FUNCION_D} {
	return FUNCION_TK;
}

{FVAR_D} {
	return FVAR_TK;
}

{HACER_D} {
	return HACER_TK;
}

{HASTA_D} {
	return HASTA_TK;
}

{MIENTRAS_D} {
	return MIENTRAS_TK;
}

{MOD_D} {
	return MOD_TK;
}

{NO_D} {
	return NO_TK;
}

{PARA_D} {
	return PARA_TK;
}

{REAL_D} {
	return REAL_TK;
}

{REF_D} {
	return REF_TK;
}

{SAL_D} {
	return SAL_TK;
}

{SI_D} {
	return SI_TK;
}

{TABLA_D} {
	return TABLA_TK;
}

{TIPO_D} {
	return TIPO_TK;
}

{TUPLA_D} {
	return TUPLA_TK;
}

{VAR_D} {
	return VAR_TK;
}

{PRECONDICION_D} {
	return PRECONDICION_TK;
}

{POSTCONDICION_D} {
	return POSTCONDICION_TK;
}

{ASIGNACION_D} {  
	return ASIGNACION_TK;
}

{PUNTOYCOMA_D} {  
	return PUNTOYCOMA_TK;
}

{COMA_D} {  
	return COMA_TK;
}

{DOSPUNTOS_D} {  
	return DOSPUNTOS_TK;
}

{ENTONCES_D} {  
	return ENTONCES_TK;
}

{SINO_SI_D} {  
	return SINO_SI_TK;
}

{IGUAL_D} {  
	return IGUAL_TK;
}

{INICIO_ARRAY_D} {  
	return INICIO_ARRAY_TK;
}

{CIERRE_ARRAY_D} {  
	return CIERRE_ARRAY_TK;
}

{MAYORIGUAL_D} {  
	return MAYORIGUAL_TK;
}

{MENORIGUAL_D} {  
	return MENORIGUAL_TK;
}

{MAYOR_D} {  
	return MAYOR_TK;
}

{MENOR_D} {  
	return MENOR_TK;
}

{DISTINTO_D} {  
	return DISTINTO_TK;
}

{MULTIPLICACION_D} {  
	return MULTIPLICACION_TK;
}

{DIVREAL_D} {  
	return DIVREAL_TK;
}

{LLAVE_APERTURA_D} {  
	return LLAVE_APERTURA_TK;
}

{LLAVE_CIERRE_D} {  
	return LLAVE_CIERRE_TK;
}

{PUNTO_D} {  
	return PUNTO_TK;
}

{PARENTESIS_APERTURA_D} {  
	return PARENTESIS_APERTURA_TK;
}

{PARENTESIS_CIERRE_D} {  
	return PARENTESIS_CIERRE_TK;
}


{CARACTERBLANCO_D} {
    // Ignorar espacios, tab y salto de línea

}

{IDBOOLEANO_D} {
    printf("IDBOOLEANO_TK, %s\n", yytext);
	yylval.cadena = strdup(yytext);
    return IDBOOLEANO_TK;
}

{ID_D} {
    printf("ID_TK, %s\n", yytext);
	yylval.cadena = strdup(yytext);
    return ID_TK;
}


\{[^}]*\} {
    return COMENTARIO_TK;
}


. {  
    printf("ERROR_TK, %s\n", yytext);
}


%%

 //PARTE 3: CODIGO ADICIONAL

void errorEnScanner(char* definicionDelError, char * variable){
	printf("\n\n\n\t%s %s \n", definicionDelError, variable);
	exit(EXIT_FAILURE);
}

int yywrap(){
	return(1);
}
