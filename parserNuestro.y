 // Autor: Sarah Parrales Gomez
 // Fecha: 4/10/25


 //  1: ZONA DE DECLARACIONES
 // PARTE 1.2: Cosas que necesitamos que esten en el .c
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>   // strdup

	#include "listaIDs.h"           
	#include "nombresDeTipos.h"
	#include "literal.h"
	#include "tablaDeConstantes.h"
	#include "tablaDeSimbolos.h"
	#include "parserNuestro.tab.h"

	int yylex();
	void yyerror(char*);
	extern FILE* yyin;

	ListaIDs* listaIDs;           // Variable global para lista de IDs
	TablaDeConstantes tc;         // Variable global para tabla de constantes

	#define YYDEBUG 1
%}

 //PARTE 2.2: Declaracion de los tokens del lenguaje y declaracion de los tipos del
 // union en los que flex nos enviara el valor asociado a los tokens multivaluados
%token MAS_TK
%token MENOS_TK

%token <cadena> ID_TK
%token <cadena> IDBOOLEANO_TK
%token <cadena> CONSTANTE_TK

%token <booleano> LITERAL_BOOLEANO_TK
%token <entero> LITERAL_ENTERO_TK
%token <real> LITERAL_REAL_TK
%token <cadena> LITERAL_CADENA_TK
%token <caracter> LITERAL_CARACTER_TK


%token ACCION_TK
%token ALGORITMO_TK
%token BOOLEANO_TK
%token CADENA_TK
%token CARACTER_TK
%token CONST_TK
%token CONTINUAR_TK
%token DE_TK
%token DEV_TK
%token DIV_TK
%token ENT_TK
%token ENTERO_TK
%token E_S_TK
%token FACCION_TK
%token FALGORITMO_TK
%token FALSO_TK
%token FCONST_TK
%token FFUNCION_TK
%token FMIENTRAS_TK
%token FPARA_TK
%token FSI_TK
%token FTIPO_TK
%token FTUPLA_TK
%token FUNCION_TK
%token FVAR_TK
%token HACER_TK
%token HASTA_TK
%token MIENTRAS_TK
%token MOD_TK
%token NO_TK
%token O_TK
%token PARA_TK
%token REAL_TK
%token REF_TK
%token SAL_TK
%token SI_TK
%token TABLA_TK
%token TIPO_TK
%token TUPLA_TK
%token VAR_TK
%token VERDADERO_TK
%token Y_TK

%token PRECONDICION_TK
%token POSTCONDICION_TK

%token ASIGNACION_TK
%token PUNTOYCOMA_TK
%token DOSPUNTOS_TK
%token ENTONCES_TK
%token SINO_SI_TK
%token IGUAL_TK
%token INICIO_ARRAY_TK
%token CIERRE_ARRAY_TK

%token MULTIPLICACION_TK
%token DIVREAL_TK
%token MAYORIGUAL_TK
%token MENORIGUAL_TK
%token MAYOR_TK
%token MENOR_TK
%token DISTINTO_TK
%token COMA_TK
%token LLAVE_APERTURA_TK
%token LLAVE_CIERRE_TK
%token PUNTO_TK
%token DOBLEPUNTO_TK
%token PARENTESIS_APERTURA_TK
%token PARENTESIS_CIERRE_TK
%token COMENTARIO_TK

%token NEG_TK
%token POS_TK

%code requires {
    #include "listaIDs.h"
    #include "nombresDeTipos.h"
    #include "literal.h"
    #include "tablaDeConstantes.h"
    #include "tablaDeSimbolos.h"
}


//PARTE 2.3: Creamos el union necesario para valores de flex y traducciones de bison

%union {
    char* cadena;            // Para ID_TK, IDBOOLEANO_TK, CONSTANTE_TK
    LiteralT literal;        // Para literales
    NombreDeTipoT tipo;      // Para tipo_base y d_tipo
    int entero;              
	double real;
    char caracter;
    int booleano;
    ListaIDs* lista_ids;     // ✅ Para lista_id y lista_d_var
}

%type <tipo> tipo_base 
%type <tipo> d_tipo
%type <literal> literal
%type <lista_ids> lista_id 
%type <lista_ids> lista_d_var

//añadido para expresiones:
%type <literal> exp_a
%type <literal> expresion


 //PARTE 2.4: Asignacion de traducciones a las variables

%nonassoc CONST_TK //Baja prioridad a constTK
%right FCONST_TK //Prioritario a derecha
%left PUNTOYCOMA_TK 

%left O_TK
%left Y_TK
%nonassoc IGUAL_TK DISTINTO_TK MAYOR_TK MENOR_TK MAYORIGUAL_TK MENORIGUAL_TK
%left MAS_TK MENOS_TK
%left MULTIPLICACION_TK DIV_TK MOD_TK DIVREAL_TK
%right NO_TK
%right NEG_TK POS_TK 
%nonassoc PARENTESIS_APERTURA_TK INICIO_ARRAY_TK
%nonassoc CIERRE_ARRAY_TK DOBLEPUNTO_TK

%%

desc_algoritmo:
	ALGORITMO_TK ID_TK PUNTOYCOMA_TK cabecera_alg bloque_alg FALGORITMO_TK PUNTO_TK
	;

cabecera_alg:
	decl_globales decl_a_f decl_ent_sal PRECONDICION_TK 
	;


bloque_alg:
	bloque POSTCONDICION_TK
	;

decl_globales:
	declaracion_tipo decl_globales 
	| /* empty */
	;

decl_a_f:
	accion_d decl_a_f
	| funcion_d decl_a_f
	| /* empty */
	;

bloque:
	declaraciones instrucciones
	;

declaraciones:
	declaracion_tipo declaraciones
	| declaracion_const declaraciones
	| declaracion_var declaraciones
	| /* empty */
	;

decl_ent_sal:
	decl_ent 
	| decl_ent decl_salida
	| decl_salida
	;

decl_ent:
	ENT_TK lista_d_var
	;

decl_salida:
	SAL_TK lista_d_var
	;

declaracion_tipo:
	TIPO_TK lista_d_tipo FTIPO_TK PUNTOYCOMA_TK
	;

declaracion_const:
	CONST_TK lista_d_const FCONST_TK PUNTOYCOMA_TK 
	;

declaracion_var:
	VAR_TK lista_d_var FVAR_TK PUNTOYCOMA_TK
	;

lista_d_tipo:
	ID_TK IGUAL_TK d_tipo PUNTOYCOMA_TK lista_d_tipo
	| IDBOOLEANO_TK IGUAL_TK d_tipo PUNTOYCOMA_TK lista_d_tipo
	| /* empty */
	;

lista_d_const:
    ID_TK IGUAL_TK literal PUNTOYCOMA_TK lista_d_const 
	{
        insertaConstante(&tc, $1, $3);
    }
  	| IDBOOLEANO_TK IGUAL_TK literal PUNTOYCOMA_TK lista_d_const 
  	{
        insertaConstante(&tc, $1, $3);
    }
  	| /* empty */
  	{}
;


literal:
    LITERAL_BOOLEANO_TK
	{
		$$ = nuevoLiteralBooleano($1); 
	}
    | LITERAL_CADENA_TK
	{
		$$ = nuevoLiteralCadena($1);
	}
    | LITERAL_CARACTER_TK
	{
		$$ = nuevoLiteralCaracter($1);
	}
    | LITERAL_ENTERO_TK
	{
		$$ = nuevoLiteralEntero($1);
	}
    | LITERAL_REAL_TK
	{
		$$ = nuevoLiteralReal($1);
	}
;


lista_d_var:
    lista_id DOSPUNTOS_TK d_tipo PUNTOYCOMA_TK lista_d_var {
        // Agregamos todos los IDs a la tabla de símbolos con el tipo $3
        for(int i = 0; i < $1->n; i++) {
            agregarVariableInicial($1->ids[i], $3);
            free($1->ids[i]); // liberamos la memoria de cada ID (ya no la necesitamos -> esta en var)
        }
        free($1); // liberamos la lista en sí    
	}
  	| /* empty */ {} 
;

lista_id:
    ID_TK {
        // Creamos una nueva lista prov con un solo ID
        ListaIDs* l = nuevaListaIDs();
        l->n = 1;
        l->ids[0] = strdup($1);
        $$ = l;
    }
  | ID_TK COMA_TK lista_id {
        // Añadimos el ID al inicio de la lista ya existente
        agregarID($3, $1);
        $$ = $3;
    }
  | IDBOOLEANO_TK {
        // Creamos una nueva lista prov con un solo ID booleano
        ListaIDs* l = nuevaListaIDs();
        l->n = 1;
        l->ids[0] = strdup($1);
        $$ = l;
    }
  | IDBOOLEANO_TK COMA_TK lista_id {
        // Añadimos el ID booleano al inicio de la lista ya existente
        agregarID($3, $1);
        $$ = $3;
    }
;


d_tipo:
	TUPLA_TK lista_campos FTUPLA_TK 
	{}
	| TABLA_TK INICIO_ARRAY_TK expresion_t DOBLEPUNTO_TK expresion_t CIERRE_ARRAY_TK DE_TK d_tipo
	{}
	| ID_TK 
	{}
	| expresion_t DOBLEPUNTO_TK expresion_t
	{}
	| REF_TK d_tipo 
	{
		$$ = $2;
	}
	| tipo_base
	{
		$$ = $1;
	}
	;
		
	
expresion_t:
	expresion 
	| literal
	;

lista_campos:
	ID_TK DOSPUNTOS_TK d_tipo PUNTOYCOMA_TK lista_campos
	| /* empty */
	;

tipo_base:
    ENTERO_TK   { $$ = ENTERO; }
  | BOOLEANO_TK { $$ = BOOLEANO; }
  | CARACTER_TK { $$ = CARACTER; }
  | REAL_TK     { $$ = REAL; }
  | CADENA_TK   { $$ = CADENA; }
  ;


expresion:
	exp_a
	| exp_b
	{}
	| funcion_ll
	{}
	;

exp_a:
	exp_a MAS_TK exp_a
	{
		$$ = sumarLiterales($1, $3);
	}
	| exp_a MENOS_TK exp_a
	{
		$$ = restarLiterales($1, $3);
	}
	| exp_a MULTIPLICACION_TK exp_a
	{
		$$ = multiplicarLiterales($1, $3);
	}
	| exp_a DIVREAL_TK exp_a
	{
		$$ = divisionRealLiterales($1, $3); 
	}
	| exp_a MOD_TK exp_a
	{
		$$ = moduloLiterales($1, $3);
	}
	| exp_a DIV_TK exp_a
	{
		$$ = divisionEnteraLiterales($1, $3);
	}
	| PARENTESIS_APERTURA_TK exp_a PARENTESIS_CIERRE_TK
	{
		$$ = $2;
	}
	| operando {}
	| MENOS_TK exp_a %prec NEG_TK
	{
		$$ = negarLiteral($2);
	}
	| MAS_TK exp_a %prec POS_TK
	{
		$$ = $2;
	}
	;

exp_b:
	exp_b Y_TK exp_b
	| exp_b O_TK exp_b
	| NO_TK exp_b
	| exp_b DIVREAL_TK exp_b
	| operando_booleano
	| VERDADERO_TK
	| FALSO_TK
	| exp_a oprel exp_a
	| PARENTESIS_APERTURA_TK exp_b PARENTESIS_CIERRE_TK
	;

oprel:
	MENOR_TK
	| MAYOR_TK
	| IGUAL_TK
	| DISTINTO_TK
	| MAYORIGUAL_TK
	| MENORIGUAL_TK
	;


operando:
	ID_TK
	{	}
	| operando PUNTO_TK ID_TK
	| operando INICIO_ARRAY_TK expresion CIERRE_ARRAY_TK
	| operando REF_TK
	| literal
	{	}
	;

operando_booleano:
	IDBOOLEANO_TK
	;


instrucciones:
	instruccion PUNTOYCOMA_TK instrucciones
	| instruccion
	;

instruccion:
	CONTINUAR_TK 
	| asignacion
	| alternativa
	| iteracion
	| accion_ll
	;

asignacion:
	operando ASIGNACION_TK expresion
	{
}
	| operando_booleano ASIGNACION_TK expresion
	{
	}
	;

alternativa:
	SI_TK expresion ENTONCES_TK instrucciones lista_opciones FSI_TK
	;

lista_opciones:
	SINO_SI_TK expresion ENTONCES_TK instrucciones lista_opciones 
	| /* empty */

iteracion:
	it_cota_fija 
	| it_cota_exp

it_cota_fija:
	MIENTRAS_TK expresion HACER_TK instrucciones FMIENTRAS_TK
	;

it_cota_exp:
	PARA_TK ID_TK ASIGNACION_TK expresion HASTA_TK expresion HACER_TK instrucciones FPARA_TK
	;

accion_d:
	ACCION_TK a_cabecera bloque FACCION_TK
	;

funcion_d:
	FUNCION_TK f_cabecera bloque DEV_TK expresion FFUNCION_TK
	;

a_cabecera:
	ID_TK PARENTESIS_APERTURA_TK d_par_form PARENTESIS_CIERRE_TK PUNTOYCOMA_TK
	;

f_cabecera:
	ID_TK PARENTESIS_APERTURA_TK lista_d_var PARENTESIS_CIERRE_TK DEV_TK d_tipo PUNTOYCOMA_TK
	;

d_par_form:
	d_p_form PUNTOYCOMA_TK d_par_form
	| /* empty */
	;

d_p_form:
	ENT_TK lista_id DOSPUNTOS_TK d_tipo
	| SAL_TK lista_id DOSPUNTOS_TK d_tipo
	| E_S_TK lista_id DOSPUNTOS_TK d_tipo
	;

accion_ll:
	ID_TK PARENTESIS_APERTURA_TK l_ll PARENTESIS_CIERRE_TK
	;

funcion_ll:
	ID_TK PARENTESIS_APERTURA_TK l_ll PARENTESIS_CIERRE_TK
	;

l_ll:
	expresion
	| expresion COMA_TK l_ll
	;	

%%

int main(int argc, char **argv){
	#if defined YYDEBUG
	yydebug=1;
	#endif
	++argv, --argc;

	listaIDs = nuevaListaIDs();
    tc = nuevaTablaDeConstantes();

    nuevaTablaDeSimbolos();   // Inicializamos la tabla de símbolos

	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;

	yyparse();

	imprimeTablaDeConstantes(tc);
	imprimirTabla();

}


void yyerror(char * s){
	printf("\tBISON: ERROR, %s\n", s);
}
