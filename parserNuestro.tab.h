/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSERNUESTRO_TAB_H_INCLUDED
# define YY_YY_PARSERNUESTRO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 120 "parserNuestro.y"

    #include "listaIDs.h"
    #include "nombresDeTipos.h"
    #include "literal.h"
    #include "tablaDeConstantes.h"
    #include "tablaDeSimbolos.h"

#line 57 "parserNuestro.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MAS_TK = 258,                  /* MAS_TK  */
    MENOS_TK = 259,                /* MENOS_TK  */
    ID_TK = 260,                   /* ID_TK  */
    IDBOOLEANO_TK = 261,           /* IDBOOLEANO_TK  */
    CONSTANTE_TK = 262,            /* CONSTANTE_TK  */
    LITERAL_BOOLEANO_TK = 263,     /* LITERAL_BOOLEANO_TK  */
    LITERAL_ENTERO_TK = 264,       /* LITERAL_ENTERO_TK  */
    LITERAL_REAL_TK = 265,         /* LITERAL_REAL_TK  */
    LITERAL_CADENA_TK = 266,       /* LITERAL_CADENA_TK  */
    LITERAL_CARACTER_TK = 267,     /* LITERAL_CARACTER_TK  */
    ACCION_TK = 268,               /* ACCION_TK  */
    ALGORITMO_TK = 269,            /* ALGORITMO_TK  */
    BOOLEANO_TK = 270,             /* BOOLEANO_TK  */
    CADENA_TK = 271,               /* CADENA_TK  */
    CARACTER_TK = 272,             /* CARACTER_TK  */
    CONST_TK = 273,                /* CONST_TK  */
    CONTINUAR_TK = 274,            /* CONTINUAR_TK  */
    DE_TK = 275,                   /* DE_TK  */
    DEV_TK = 276,                  /* DEV_TK  */
    DIV_TK = 277,                  /* DIV_TK  */
    ENT_TK = 278,                  /* ENT_TK  */
    ENTERO_TK = 279,               /* ENTERO_TK  */
    E_S_TK = 280,                  /* E_S_TK  */
    FACCION_TK = 281,              /* FACCION_TK  */
    FALGORITMO_TK = 282,           /* FALGORITMO_TK  */
    FALSO_TK = 283,                /* FALSO_TK  */
    FCONST_TK = 284,               /* FCONST_TK  */
    FFUNCION_TK = 285,             /* FFUNCION_TK  */
    FMIENTRAS_TK = 286,            /* FMIENTRAS_TK  */
    FPARA_TK = 287,                /* FPARA_TK  */
    FSI_TK = 288,                  /* FSI_TK  */
    FTIPO_TK = 289,                /* FTIPO_TK  */
    FTUPLA_TK = 290,               /* FTUPLA_TK  */
    FUNCION_TK = 291,              /* FUNCION_TK  */
    FVAR_TK = 292,                 /* FVAR_TK  */
    HACER_TK = 293,                /* HACER_TK  */
    HASTA_TK = 294,                /* HASTA_TK  */
    MIENTRAS_TK = 295,             /* MIENTRAS_TK  */
    MOD_TK = 296,                  /* MOD_TK  */
    NO_TK = 297,                   /* NO_TK  */
    O_TK = 298,                    /* O_TK  */
    PARA_TK = 299,                 /* PARA_TK  */
    REAL_TK = 300,                 /* REAL_TK  */
    REF_TK = 301,                  /* REF_TK  */
    SAL_TK = 302,                  /* SAL_TK  */
    SI_TK = 303,                   /* SI_TK  */
    TABLA_TK = 304,                /* TABLA_TK  */
    TIPO_TK = 305,                 /* TIPO_TK  */
    TUPLA_TK = 306,                /* TUPLA_TK  */
    VAR_TK = 307,                  /* VAR_TK  */
    VERDADERO_TK = 308,            /* VERDADERO_TK  */
    Y_TK = 309,                    /* Y_TK  */
    PRECONDICION_TK = 310,         /* PRECONDICION_TK  */
    POSTCONDICION_TK = 311,        /* POSTCONDICION_TK  */
    ASIGNACION_TK = 312,           /* ASIGNACION_TK  */
    PUNTOYCOMA_TK = 313,           /* PUNTOYCOMA_TK  */
    DOSPUNTOS_TK = 314,            /* DOSPUNTOS_TK  */
    ENTONCES_TK = 315,             /* ENTONCES_TK  */
    SINO_SI_TK = 316,              /* SINO_SI_TK  */
    IGUAL_TK = 317,                /* IGUAL_TK  */
    INICIO_ARRAY_TK = 318,         /* INICIO_ARRAY_TK  */
    CIERRE_ARRAY_TK = 319,         /* CIERRE_ARRAY_TK  */
    MULTIPLICACION_TK = 320,       /* MULTIPLICACION_TK  */
    DIVREAL_TK = 321,              /* DIVREAL_TK  */
    MAYORIGUAL_TK = 322,           /* MAYORIGUAL_TK  */
    MENORIGUAL_TK = 323,           /* MENORIGUAL_TK  */
    MAYOR_TK = 324,                /* MAYOR_TK  */
    MENOR_TK = 325,                /* MENOR_TK  */
    DISTINTO_TK = 326,             /* DISTINTO_TK  */
    COMA_TK = 327,                 /* COMA_TK  */
    LLAVE_APERTURA_TK = 328,       /* LLAVE_APERTURA_TK  */
    LLAVE_CIERRE_TK = 329,         /* LLAVE_CIERRE_TK  */
    PUNTO_TK = 330,                /* PUNTO_TK  */
    DOBLEPUNTO_TK = 331,           /* DOBLEPUNTO_TK  */
    PARENTESIS_APERTURA_TK = 332,  /* PARENTESIS_APERTURA_TK  */
    PARENTESIS_CIERRE_TK = 333,    /* PARENTESIS_CIERRE_TK  */
    COMENTARIO_TK = 334,           /* COMENTARIO_TK  */
    NEG_TK = 335,                  /* NEG_TK  */
    POS_TK = 336                   /* POS_TK  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 131 "parserNuestro.y"

    char* cadena;            // Para ID_TK, IDBOOLEANO_TK, CONSTANTE_TK
    LiteralT literal;        // Para literales
	int entero;              
    double real;
    char caracter;
    int booleano;
    NombreDeTipoT tipo;      // Para tipo_base y d_tipo
    ListaIDs* lista_ids;     // Para lista_id y lista_d_var
	int id_simbolo; 		 // Para expresion operando y operando

#line 167 "parserNuestro.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSERNUESTRO_TAB_H_INCLUDED  */
