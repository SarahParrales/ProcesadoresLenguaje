/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 7 "parserNuestro.y"

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>   // strdup

	#include "listaIDs.h"           
	#include "nombresDeTipos.h"
	#include "literal.h"
	#include "tablaDeConstantes.h"
	#include "tablaDeSimbolos.h"
	#include "cuadrupla.h"
	#include "parserNuestro.tab.h"

	int yylex();
	void yyerror(char*);
	extern FILE* yyin;

	ListaIDs* listaIDs;           // Variable global para lista de IDs
	TablaDeConstantes tc;         // Variable global para tabla de constantes

	#define YYDEBUG 1

#line 94 "parserNuestro.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parserNuestro.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_MAS_TK = 3,                     /* MAS_TK  */
  YYSYMBOL_MENOS_TK = 4,                   /* MENOS_TK  */
  YYSYMBOL_ID_TK = 5,                      /* ID_TK  */
  YYSYMBOL_IDBOOLEANO_TK = 6,              /* IDBOOLEANO_TK  */
  YYSYMBOL_CONSTANTE_TK = 7,               /* CONSTANTE_TK  */
  YYSYMBOL_LITERAL_BOOLEANO_TK = 8,        /* LITERAL_BOOLEANO_TK  */
  YYSYMBOL_LITERAL_ENTERO_TK = 9,          /* LITERAL_ENTERO_TK  */
  YYSYMBOL_LITERAL_REAL_TK = 10,           /* LITERAL_REAL_TK  */
  YYSYMBOL_LITERAL_CADENA_TK = 11,         /* LITERAL_CADENA_TK  */
  YYSYMBOL_LITERAL_CARACTER_TK = 12,       /* LITERAL_CARACTER_TK  */
  YYSYMBOL_ACCION_TK = 13,                 /* ACCION_TK  */
  YYSYMBOL_ALGORITMO_TK = 14,              /* ALGORITMO_TK  */
  YYSYMBOL_BOOLEANO_TK = 15,               /* BOOLEANO_TK  */
  YYSYMBOL_CADENA_TK = 16,                 /* CADENA_TK  */
  YYSYMBOL_CARACTER_TK = 17,               /* CARACTER_TK  */
  YYSYMBOL_CONST_TK = 18,                  /* CONST_TK  */
  YYSYMBOL_CONTINUAR_TK = 19,              /* CONTINUAR_TK  */
  YYSYMBOL_DE_TK = 20,                     /* DE_TK  */
  YYSYMBOL_DEV_TK = 21,                    /* DEV_TK  */
  YYSYMBOL_DIV_TK = 22,                    /* DIV_TK  */
  YYSYMBOL_ENT_TK = 23,                    /* ENT_TK  */
  YYSYMBOL_ENTERO_TK = 24,                 /* ENTERO_TK  */
  YYSYMBOL_E_S_TK = 25,                    /* E_S_TK  */
  YYSYMBOL_FACCION_TK = 26,                /* FACCION_TK  */
  YYSYMBOL_FALGORITMO_TK = 27,             /* FALGORITMO_TK  */
  YYSYMBOL_FALSO_TK = 28,                  /* FALSO_TK  */
  YYSYMBOL_FCONST_TK = 29,                 /* FCONST_TK  */
  YYSYMBOL_FFUNCION_TK = 30,               /* FFUNCION_TK  */
  YYSYMBOL_FMIENTRAS_TK = 31,              /* FMIENTRAS_TK  */
  YYSYMBOL_FPARA_TK = 32,                  /* FPARA_TK  */
  YYSYMBOL_FSI_TK = 33,                    /* FSI_TK  */
  YYSYMBOL_FTIPO_TK = 34,                  /* FTIPO_TK  */
  YYSYMBOL_FTUPLA_TK = 35,                 /* FTUPLA_TK  */
  YYSYMBOL_FUNCION_TK = 36,                /* FUNCION_TK  */
  YYSYMBOL_FVAR_TK = 37,                   /* FVAR_TK  */
  YYSYMBOL_HACER_TK = 38,                  /* HACER_TK  */
  YYSYMBOL_HASTA_TK = 39,                  /* HASTA_TK  */
  YYSYMBOL_MIENTRAS_TK = 40,               /* MIENTRAS_TK  */
  YYSYMBOL_MOD_TK = 41,                    /* MOD_TK  */
  YYSYMBOL_NO_TK = 42,                     /* NO_TK  */
  YYSYMBOL_O_TK = 43,                      /* O_TK  */
  YYSYMBOL_PARA_TK = 44,                   /* PARA_TK  */
  YYSYMBOL_REAL_TK = 45,                   /* REAL_TK  */
  YYSYMBOL_REF_TK = 46,                    /* REF_TK  */
  YYSYMBOL_SAL_TK = 47,                    /* SAL_TK  */
  YYSYMBOL_SI_TK = 48,                     /* SI_TK  */
  YYSYMBOL_TABLA_TK = 49,                  /* TABLA_TK  */
  YYSYMBOL_TIPO_TK = 50,                   /* TIPO_TK  */
  YYSYMBOL_TUPLA_TK = 51,                  /* TUPLA_TK  */
  YYSYMBOL_VAR_TK = 52,                    /* VAR_TK  */
  YYSYMBOL_VERDADERO_TK = 53,              /* VERDADERO_TK  */
  YYSYMBOL_Y_TK = 54,                      /* Y_TK  */
  YYSYMBOL_PRECONDICION_TK = 55,           /* PRECONDICION_TK  */
  YYSYMBOL_POSTCONDICION_TK = 56,          /* POSTCONDICION_TK  */
  YYSYMBOL_ASIGNACION_TK = 57,             /* ASIGNACION_TK  */
  YYSYMBOL_PUNTOYCOMA_TK = 58,             /* PUNTOYCOMA_TK  */
  YYSYMBOL_DOSPUNTOS_TK = 59,              /* DOSPUNTOS_TK  */
  YYSYMBOL_ENTONCES_TK = 60,               /* ENTONCES_TK  */
  YYSYMBOL_SINO_SI_TK = 61,                /* SINO_SI_TK  */
  YYSYMBOL_IGUAL_TK = 62,                  /* IGUAL_TK  */
  YYSYMBOL_INICIO_ARRAY_TK = 63,           /* INICIO_ARRAY_TK  */
  YYSYMBOL_CIERRE_ARRAY_TK = 64,           /* CIERRE_ARRAY_TK  */
  YYSYMBOL_MULTIPLICACION_TK = 65,         /* MULTIPLICACION_TK  */
  YYSYMBOL_DIVREAL_TK = 66,                /* DIVREAL_TK  */
  YYSYMBOL_MAYORIGUAL_TK = 67,             /* MAYORIGUAL_TK  */
  YYSYMBOL_MENORIGUAL_TK = 68,             /* MENORIGUAL_TK  */
  YYSYMBOL_MAYOR_TK = 69,                  /* MAYOR_TK  */
  YYSYMBOL_MENOR_TK = 70,                  /* MENOR_TK  */
  YYSYMBOL_DISTINTO_TK = 71,               /* DISTINTO_TK  */
  YYSYMBOL_COMA_TK = 72,                   /* COMA_TK  */
  YYSYMBOL_LLAVE_APERTURA_TK = 73,         /* LLAVE_APERTURA_TK  */
  YYSYMBOL_LLAVE_CIERRE_TK = 74,           /* LLAVE_CIERRE_TK  */
  YYSYMBOL_PUNTO_TK = 75,                  /* PUNTO_TK  */
  YYSYMBOL_DOBLEPUNTO_TK = 76,             /* DOBLEPUNTO_TK  */
  YYSYMBOL_PARENTESIS_APERTURA_TK = 77,    /* PARENTESIS_APERTURA_TK  */
  YYSYMBOL_PARENTESIS_CIERRE_TK = 78,      /* PARENTESIS_CIERRE_TK  */
  YYSYMBOL_COMENTARIO_TK = 79,             /* COMENTARIO_TK  */
  YYSYMBOL_NEG_TK = 80,                    /* NEG_TK  */
  YYSYMBOL_POS_TK = 81,                    /* POS_TK  */
  YYSYMBOL_YYACCEPT = 82,                  /* $accept  */
  YYSYMBOL_desc_algoritmo = 83,            /* desc_algoritmo  */
  YYSYMBOL_cabecera_alg = 84,              /* cabecera_alg  */
  YYSYMBOL_bloque_alg = 85,                /* bloque_alg  */
  YYSYMBOL_decl_globales = 86,             /* decl_globales  */
  YYSYMBOL_decl_a_f = 87,                  /* decl_a_f  */
  YYSYMBOL_bloque = 88,                    /* bloque  */
  YYSYMBOL_declaraciones = 89,             /* declaraciones  */
  YYSYMBOL_decl_ent_sal = 90,              /* decl_ent_sal  */
  YYSYMBOL_decl_ent = 91,                  /* decl_ent  */
  YYSYMBOL_decl_salida = 92,               /* decl_salida  */
  YYSYMBOL_declaracion_tipo = 93,          /* declaracion_tipo  */
  YYSYMBOL_declaracion_const = 94,         /* declaracion_const  */
  YYSYMBOL_declaracion_var = 95,           /* declaracion_var  */
  YYSYMBOL_lista_d_tipo = 96,              /* lista_d_tipo  */
  YYSYMBOL_lista_d_const = 97,             /* lista_d_const  */
  YYSYMBOL_literal = 98,                   /* literal  */
  YYSYMBOL_lista_d_var = 99,               /* lista_d_var  */
  YYSYMBOL_lista_id = 100,                 /* lista_id  */
  YYSYMBOL_d_tipo = 101,                   /* d_tipo  */
  YYSYMBOL_expresion_t = 102,              /* expresion_t  */
  YYSYMBOL_lista_campos = 103,             /* lista_campos  */
  YYSYMBOL_tipo_base = 104,                /* tipo_base  */
  YYSYMBOL_expresion = 105,                /* expresion  */
  YYSYMBOL_exp_a = 106,                    /* exp_a  */
  YYSYMBOL_exp_b = 107,                    /* exp_b  */
  YYSYMBOL_oprel = 108,                    /* oprel  */
  YYSYMBOL_operando = 109,                 /* operando  */
  YYSYMBOL_operando_booleano = 110,        /* operando_booleano  */
  YYSYMBOL_instrucciones = 111,            /* instrucciones  */
  YYSYMBOL_instruccion = 112,              /* instruccion  */
  YYSYMBOL_asignacion = 113,               /* asignacion  */
  YYSYMBOL_alternativa = 114,              /* alternativa  */
  YYSYMBOL_lista_opciones = 115,           /* lista_opciones  */
  YYSYMBOL_iteracion = 116,                /* iteracion  */
  YYSYMBOL_it_cota_fija = 117,             /* it_cota_fija  */
  YYSYMBOL_it_cota_exp = 118,              /* it_cota_exp  */
  YYSYMBOL_accion_d = 119,                 /* accion_d  */
  YYSYMBOL_funcion_d = 120,                /* funcion_d  */
  YYSYMBOL_a_cabecera = 121,               /* a_cabecera  */
  YYSYMBOL_f_cabecera = 122,               /* f_cabecera  */
  YYSYMBOL_d_par_form = 123,               /* d_par_form  */
  YYSYMBOL_d_p_form = 124,                 /* d_p_form  */
  YYSYMBOL_accion_ll = 125,                /* accion_ll  */
  YYSYMBOL_funcion_ll = 126,               /* funcion_ll  */
  YYSYMBOL_l_ll = 127                      /* l_ll  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   364

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  82
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  258

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   336


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   180,   180,   184,   189,   193,   194,   198,   199,   200,
     204,   208,   209,   210,   211,   215,   216,   217,   221,   225,
     229,   233,   237,   241,   242,   243,   247,   251,   256,   261,
     265,   269,   273,   277,   285,   293,   297,   303,   308,   314,
     323,   325,   327,   329,   331,   335,   343,   344,   348,   349,
     353,   354,   355,   356,   357,   362,   366,   370,   375,   391,
     401,   411,   417,   423,   429,   433,   437,   454,   461,   467,
     473,   479,   483,   493,   502,   531,   538,   542,   546,   550,
     554,   558,   566,   583,   584,   585,   586,   662,   676,   677,
     681,   682,   683,   684,   685,   689,   694,   702,   706,   707,
     710,   711,   714,   718,   722,   726,   730,   734,   738,   739,
     743,   744,   745,   749,   753,   757,   758
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "MAS_TK", "MENOS_TK",
  "ID_TK", "IDBOOLEANO_TK", "CONSTANTE_TK", "LITERAL_BOOLEANO_TK",
  "LITERAL_ENTERO_TK", "LITERAL_REAL_TK", "LITERAL_CADENA_TK",
  "LITERAL_CARACTER_TK", "ACCION_TK", "ALGORITMO_TK", "BOOLEANO_TK",
  "CADENA_TK", "CARACTER_TK", "CONST_TK", "CONTINUAR_TK", "DE_TK",
  "DEV_TK", "DIV_TK", "ENT_TK", "ENTERO_TK", "E_S_TK", "FACCION_TK",
  "FALGORITMO_TK", "FALSO_TK", "FCONST_TK", "FFUNCION_TK", "FMIENTRAS_TK",
  "FPARA_TK", "FSI_TK", "FTIPO_TK", "FTUPLA_TK", "FUNCION_TK", "FVAR_TK",
  "HACER_TK", "HASTA_TK", "MIENTRAS_TK", "MOD_TK", "NO_TK", "O_TK",
  "PARA_TK", "REAL_TK", "REF_TK", "SAL_TK", "SI_TK", "TABLA_TK", "TIPO_TK",
  "TUPLA_TK", "VAR_TK", "VERDADERO_TK", "Y_TK", "PRECONDICION_TK",
  "POSTCONDICION_TK", "ASIGNACION_TK", "PUNTOYCOMA_TK", "DOSPUNTOS_TK",
  "ENTONCES_TK", "SINO_SI_TK", "IGUAL_TK", "INICIO_ARRAY_TK",
  "CIERRE_ARRAY_TK", "MULTIPLICACION_TK", "DIVREAL_TK", "MAYORIGUAL_TK",
  "MENORIGUAL_TK", "MAYOR_TK", "MENOR_TK", "DISTINTO_TK", "COMA_TK",
  "LLAVE_APERTURA_TK", "LLAVE_CIERRE_TK", "PUNTO_TK", "DOBLEPUNTO_TK",
  "PARENTESIS_APERTURA_TK", "PARENTESIS_CIERRE_TK", "COMENTARIO_TK",
  "NEG_TK", "POS_TK", "$accept", "desc_algoritmo", "cabecera_alg",
  "bloque_alg", "decl_globales", "decl_a_f", "bloque", "declaraciones",
  "decl_ent_sal", "decl_ent", "decl_salida", "declaracion_tipo",
  "declaracion_const", "declaracion_var", "lista_d_tipo", "lista_d_const",
  "literal", "lista_d_var", "lista_id", "d_tipo", "expresion_t",
  "lista_campos", "tipo_base", "expresion", "exp_a", "exp_b", "oprel",
  "operando", "operando_booleano", "instrucciones", "instruccion",
  "asignacion", "alternativa", "lista_opciones", "iteracion",
  "it_cota_fija", "it_cota_exp", "accion_d", "funcion_d", "a_cabecera",
  "f_cabecera", "d_par_form", "d_p_form", "accion_ll", "funcion_ll",
  "l_ll", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-131)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-48)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    17,    36,     5,  -131,    18,    78,    -3,    35,    18,
      25,    32,    10,    95,    99,    88,    62,   316,    -3,    -3,
      -3,   121,   143,    -2,    35,    35,  -131,   246,   246,    87,
      89,    91,   127,   103,   104,   134,   118,   105,  -131,   106,
    -131,  -131,  -131,  -131,  -131,  -131,  -131,    22,   176,    22,
    -131,    -6,   125,  -131,   126,  -131,  -131,  -131,  -131,  -131,
    -131,  -131,  -131,  -131,   108,    -3,   109,    -3,    99,    99,
     133,   142,  -131,  -131,  -131,   219,   219,   -42,  -131,  -131,
    -131,  -131,  -131,   119,  -131,   246,   129,   188,  -131,   119,
      38,   136,   122,  -131,  -131,   244,    19,   -34,  -131,  -131,
     141,  -131,   155,   155,   144,    99,    99,   145,   246,  -131,
      22,   123,   163,   147,   148,  -131,    22,    22,   204,    22,
     316,    33,   191,    99,   198,  -131,  -131,  -131,  -131,  -131,
     219,  -131,  -131,    22,   244,  -131,  -131,    22,   161,   186,
     175,   -35,    78,    22,   219,   219,   219,   219,  -131,   219,
     219,  -131,  -131,  -131,  -131,  -131,   219,   119,   119,    78,
     167,   180,  -131,  -131,  -131,  -131,   181,   187,   182,   316,
      22,   316,  -131,   200,  -131,  -131,  -131,    99,    99,    99,
     189,   207,  -131,   190,    22,    20,   193,   196,   246,  -131,
    -131,  -131,  -131,  -131,    75,    75,  -131,  -131,  -131,  -131,
     146,   215,  -131,  -131,    95,    95,    99,    22,  -131,   242,
     236,   216,  -131,   217,   220,   221,   223,    33,   257,   252,
    -131,    22,   225,  -131,  -131,  -131,  -131,  -131,    22,    22,
     251,   246,   246,   246,  -131,  -131,   246,  -131,   222,   188,
     249,   229,  -131,  -131,  -131,  -131,   232,   273,  -131,   316,
     316,  -131,   246,   262,   216,  -131,  -131,  -131
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     6,    25,    14,     9,     6,
       0,     0,     0,    28,    35,     0,     0,     0,    14,    14,
      14,     0,     0,     0,     9,     9,     5,     0,     0,     0,
       0,     0,     0,    36,    38,     0,     0,     0,     4,    82,
      87,    29,    32,    33,    30,    31,    90,     0,     0,     0,
      86,     0,     0,    10,    89,    91,    92,    93,   100,   101,
      94,    11,    12,    13,     0,    14,     0,    14,    35,    35,
       0,    15,    17,     7,     8,     0,     0,    82,    51,    54,
      52,    50,    73,     0,    53,     0,     0,    49,    72,     0,
      86,     0,     0,    45,    46,    56,    55,    65,    71,    57,
       0,    20,     0,     0,     0,     0,     0,     0,     0,     2,
       0,    82,     0,     0,     0,    85,     0,     0,     0,     0,
       0,   109,     0,    35,     0,    18,    19,     3,    16,    82,
       0,    67,    66,     0,     0,    70,    44,     0,     0,     0,
       0,     0,    25,     0,     0,     0,     0,     0,    78,     0,
       0,    80,    81,    77,    76,    79,     0,     0,     0,    25,
       0,     0,    21,    37,    39,    22,     0,   115,     0,     0,
       0,     0,    95,     0,    83,    96,    88,     0,     0,     0,
       0,     0,   104,     0,     0,     0,     0,     0,     0,    40,
      64,    75,    23,    43,    58,    59,    63,    62,    60,    61,
      74,    69,    68,    24,    28,    28,    35,     0,   113,     0,
       0,    99,    84,     0,     0,     0,     0,   109,     0,     0,
     114,     0,     0,    26,    27,    34,   116,   102,     0,     0,
       0,     0,     0,     0,   106,   108,     0,   105,     0,    49,
       0,     0,    97,   110,   112,   111,     0,     0,    48,     0,
       0,   107,     0,     0,    99,    41,   103,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -131,  -131,  -131,  -131,   289,   111,    77,   140,  -131,  -131,
     230,    65,  -131,  -131,  -105,   -31,   -26,   -63,   -40,   -18,
    -130,    61,  -131,   -38,   -37,   -69,  -131,   -17,   -14,  -116,
    -131,  -131,  -131,    48,  -131,  -131,  -131,  -131,  -131,  -131,
    -131,    86,  -131,  -131,  -131,  -115
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     7,    15,     8,    23,    16,    17,    70,    71,
      72,    18,    19,    20,    12,    32,    50,    35,    36,    91,
      92,   139,    93,    94,    95,    96,   156,    97,    98,    53,
      54,    55,    56,   230,    57,    58,    59,    24,    25,    65,
      67,   180,   181,    60,    99,   168
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      51,    90,    90,    52,   176,   125,   126,   187,   157,   112,
     100,   114,   115,   193,   135,    13,   -42,     1,   186,   158,
     141,    68,     3,   144,   145,    75,    76,   111,    40,   117,
      41,    42,    43,    44,    45,   133,     4,   192,   131,   132,
     115,   118,   146,   191,    29,    69,   134,     6,    21,    14,
      82,   116,   140,   209,   203,   211,   177,   117,   178,    90,
     183,   147,   157,     5,    83,   163,   164,   136,     6,   118,
       9,    22,   167,   158,     9,    88,   160,   161,   172,   173,
     179,   175,    90,    10,    11,   149,   150,    27,   201,   202,
     166,   238,   226,   185,    28,   167,   -47,   146,   190,    89,
      30,    31,   -47,    51,    33,    34,    52,   194,   195,   196,
     197,    90,   198,   199,   -47,    37,   147,    90,    38,   200,
     134,   134,    75,    76,   129,    40,    64,    41,    42,    43,
      44,    45,   210,   253,   254,    73,    74,   213,   214,   215,
     149,   150,   122,   225,   124,   101,   219,    82,    66,   144,
     145,   102,    51,   103,    51,    52,   104,    52,    61,    62,
      63,    83,    90,    41,    42,    43,    44,    45,   146,   167,
     222,   107,    88,   223,   224,   105,   106,   108,   144,   145,
     109,   113,   119,   110,   120,   121,   123,   147,   127,    69,
     240,   241,   137,   138,   142,    90,    89,   146,   143,   159,
     133,   169,   162,   165,   170,    90,    90,    90,   171,   174,
      90,   149,   150,   243,   244,   245,   147,   182,   246,   184,
     188,   189,    75,    76,   129,   204,    90,    41,    42,    43,
      44,    45,    51,    51,   255,    52,    52,   148,   205,   206,
     149,   150,   151,   152,   153,   154,   155,   144,   145,    75,
      76,    77,    40,   190,    41,    42,    43,    44,    45,   207,
     208,    78,    79,    80,   212,   217,   146,   216,   218,   158,
      81,   220,   221,   227,    82,   228,   231,   229,   236,   232,
     233,   234,   237,   239,   242,   147,   247,   249,    83,   250,
     251,    84,    85,   252,   256,    86,   130,    87,    26,    88,
     248,   128,   257,   235,     0,     0,   148,     0,     0,   149,
     150,   151,   152,   153,   154,   155,     0,     0,     0,     0,
       0,    39,    40,    89,    41,    42,    43,    44,    45,     0,
       0,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    47,     0,     0,     0,
      48,     0,     0,     0,    49
};

static const yytype_int16 yycheck[] =
{
      17,    27,    28,    17,   120,    68,    69,   137,    43,    47,
      28,    49,    46,   143,    83,    18,    58,    14,   133,    54,
      89,    23,     5,     3,     4,     3,     4,     5,     6,    63,
       8,     9,    10,    11,    12,    77,     0,   142,    75,    76,
      46,    75,    22,    78,    34,    47,    83,    50,    13,    52,
      28,    57,    89,   169,   159,   171,    23,    63,    25,    85,
     123,    41,    43,    58,    42,   105,   106,    85,    50,    75,
       5,    36,   110,    54,     9,    53,   102,   103,   116,   117,
      47,   119,   108,     5,     6,    65,    66,    62,   157,   158,
     108,   221,   207,   130,    62,   133,    58,    22,    78,    77,
       5,     6,    64,   120,     5,     6,   120,   144,   145,   146,
     147,   137,   149,   150,    76,    27,    41,   143,    56,   156,
     157,   158,     3,     4,     5,     6,     5,     8,     9,    10,
      11,    12,   170,   249,   250,    24,    25,   177,   178,   179,
      65,    66,    65,   206,    67,    58,   184,    28,     5,     3,
       4,    62,   169,    62,   171,   169,    29,   171,    18,    19,
      20,    42,   188,     8,     9,    10,    11,    12,    22,   207,
     188,    37,    53,   204,   205,    72,    72,    59,     3,     4,
      75,     5,    57,    77,    58,    77,    77,    41,    55,    47,
     228,   229,    63,     5,    58,   221,    77,    22,    76,    58,
      77,    38,    58,    58,    57,   231,   232,   233,    60,     5,
     236,    65,    66,   231,   232,   233,    41,    26,   236,    21,
      59,    35,     3,     4,     5,    58,   252,     8,     9,    10,
      11,    12,   249,   250,   252,   249,   250,    62,    58,    58,
      65,    66,    67,    68,    69,    70,    71,     3,     4,     3,
       4,     5,     6,    78,     8,     9,    10,    11,    12,    72,
      78,    15,    16,    17,    64,    58,    22,    78,    78,    54,
      24,    78,    76,    31,    28,    39,    59,    61,    21,    59,
      59,    58,    30,    58,    33,    41,    64,    38,    42,    60,
      58,    45,    46,    20,    32,    49,    77,    51,     9,    53,
     239,    71,   254,   217,    -1,    -1,    62,    -1,    -1,    65,
      66,    67,    68,    69,    70,    71,    -1,    -1,    -1,    -1,
      -1,     5,     6,    77,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    40,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    48
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    14,    83,     5,     0,    58,    50,    84,    86,    93,
       5,     6,    96,    18,    52,    85,    88,    89,    93,    94,
      95,    13,    36,    87,   119,   120,    86,    62,    62,    34,
       5,     6,    97,     5,     6,    99,   100,    27,    56,     5,
       6,     8,     9,    10,    11,    12,    19,    40,    44,    48,
      98,   109,   110,   111,   112,   113,   114,   116,   117,   118,
     125,    89,    89,    89,     5,   121,     5,   122,    23,    47,
      90,    91,    92,    87,    87,     3,     4,     5,    15,    16,
      17,    24,    28,    42,    45,    46,    49,    51,    53,    77,
      98,   101,   102,   104,   105,   106,   107,   109,   110,   126,
     101,    58,    62,    62,    29,    72,    72,    37,    59,    75,
      77,     5,   105,     5,   105,    46,    57,    63,    75,    57,
      58,    77,    88,    77,    88,    99,    99,    55,    92,     5,
      77,   106,   106,    77,   106,   107,   101,    63,     5,   103,
     106,   107,    58,    76,     3,     4,    22,    41,    62,    65,
      66,    67,    68,    69,    70,    71,   108,    43,    54,    58,
      98,    98,    58,   100,   100,    58,   101,   105,   127,    38,
      57,    60,   105,   105,     5,   105,   111,    23,    25,    47,
     123,   124,    26,    99,    21,   106,   127,   102,    59,    35,
      78,    78,    96,   102,   106,   106,   106,   106,   106,   106,
     106,   107,   107,    96,    58,    58,    58,    72,    78,   111,
     105,   111,    64,   100,   100,   100,    78,    58,    78,   105,
      78,    76,   101,    97,    97,    99,   127,    31,    39,    61,
     115,    59,    59,    59,    58,   123,    21,    30,   102,    58,
     105,   105,    33,   101,   101,   101,   101,    64,   103,    38,
      60,    58,    20,   111,   111,   101,    32,   115
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    82,    83,    84,    85,    86,    86,    87,    87,    87,
      88,    89,    89,    89,    89,    90,    90,    90,    91,    92,
      93,    94,    95,    96,    96,    96,    97,    97,    97,    98,
      98,    98,    98,    98,    99,    99,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   101,   102,   102,   103,   103,
     104,   104,   104,   104,   104,   105,   105,   105,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   108,   108,   108,   108,
     108,   108,   109,   109,   109,   109,   109,   110,   111,   111,
     112,   112,   112,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   117,   118,   119,   120,   121,   122,   123,   123,
     124,   124,   124,   125,   126,   127,   127
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     7,     4,     2,     2,     0,     2,     2,     0,
       2,     2,     2,     2,     0,     1,     2,     1,     2,     2,
       4,     4,     4,     5,     5,     0,     5,     5,     0,     1,
       1,     1,     1,     1,     5,     0,     1,     3,     1,     3,
       3,     8,     1,     3,     2,     1,     1,     1,     5,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     1,     2,     2,     3,     3,
       2,     1,     1,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     3,     4,     2,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     3,     6,     5,     0,
       1,     1,     5,     9,     4,     6,     5,     7,     3,     0,
       4,     4,     4,     4,     4,     1,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 26: /* lista_d_const: ID_TK IGUAL_TK literal PUNTOYCOMA_TK lista_d_const  */
#line 248 "parserNuestro.y"
        {
        insertaConstante(&tc, (yyvsp[-4].cadena), (yyvsp[-2].literal));
    	}
#line 1418 "parserNuestro.tab.c"
    break;

  case 27: /* lista_d_const: IDBOOLEANO_TK IGUAL_TK literal PUNTOYCOMA_TK lista_d_const  */
#line 252 "parserNuestro.y"
        {
        insertaConstante(&tc, (yyvsp[-4].cadena), (yyvsp[-2].literal));
    	}
#line 1426 "parserNuestro.tab.c"
    break;

  case 28: /* lista_d_const: %empty  */
#line 256 "parserNuestro.y"
        {}
#line 1432 "parserNuestro.tab.c"
    break;

  case 29: /* literal: LITERAL_BOOLEANO_TK  */
#line 262 "parserNuestro.y"
        {
		(yyval.literal) = (yyvsp[0].literal);
	}
#line 1440 "parserNuestro.tab.c"
    break;

  case 30: /* literal: LITERAL_CADENA_TK  */
#line 266 "parserNuestro.y"
        {
		(yyval.literal) = (yyvsp[0].literal);
	}
#line 1448 "parserNuestro.tab.c"
    break;

  case 31: /* literal: LITERAL_CARACTER_TK  */
#line 270 "parserNuestro.y"
        {
		(yyval.literal) = (yyvsp[0].literal);
	}
#line 1456 "parserNuestro.tab.c"
    break;

  case 32: /* literal: LITERAL_ENTERO_TK  */
#line 274 "parserNuestro.y"
        {
		(yyval.literal) = (yyvsp[0].literal);
	}
#line 1464 "parserNuestro.tab.c"
    break;

  case 33: /* literal: LITERAL_REAL_TK  */
#line 278 "parserNuestro.y"
        {
		(yyval.literal) = (yyvsp[0].literal);
	}
#line 1472 "parserNuestro.tab.c"
    break;

  case 34: /* lista_d_var: lista_id DOSPUNTOS_TK d_tipo PUNTOYCOMA_TK lista_d_var  */
#line 285 "parserNuestro.y"
                                                           {
        // Agregamos todos los IDs a la tabla de símbolos con el tipo $3
        for(int i = 0; i < (yyvsp[-4].lista_ids)->n; i++) {
            agregarVariable((yyvsp[-4].lista_ids)->ids[i], (yyvsp[-2].tipo));
            free((yyvsp[-4].lista_ids)->ids[i]); // liberamos la memoria de cada ID (ya no la necesitamos -> esta en var)
        }
        free((yyvsp[-4].lista_ids)); // liberamos la lista
	}
#line 1485 "parserNuestro.tab.c"
    break;

  case 35: /* lista_d_var: %empty  */
#line 293 "parserNuestro.y"
                      {}
#line 1491 "parserNuestro.tab.c"
    break;

  case 36: /* lista_id: ID_TK  */
#line 297 "parserNuestro.y"
          {
        // Creamos una nueva lista prov con un solo ID
        (yyval.lista_ids) = nuevaListaIDs();
        (yyval.lista_ids)->n = 1;
        (yyval.lista_ids)->ids[0] = strdup((yyvsp[0].cadena));
    }
#line 1502 "parserNuestro.tab.c"
    break;

  case 37: /* lista_id: ID_TK COMA_TK lista_id  */
#line 303 "parserNuestro.y"
                           {
        // Añadimos el ID al inicio de la lista ya existente
        agregarID((yyvsp[0].lista_ids), (yyvsp[-2].cadena));
        (yyval.lista_ids) = (yyvsp[0].lista_ids);
    }
#line 1512 "parserNuestro.tab.c"
    break;

  case 38: /* lista_id: IDBOOLEANO_TK  */
#line 308 "parserNuestro.y"
                  {
        // Creamos una nueva lista prov con un solo ID booleano
        (yyval.lista_ids) = nuevaListaIDs();
        (yyval.lista_ids)->n = 1;
        (yyval.lista_ids)->ids[0] = strdup((yyvsp[0].cadena));
    }
#line 1523 "parserNuestro.tab.c"
    break;

  case 39: /* lista_id: IDBOOLEANO_TK COMA_TK lista_id  */
#line 314 "parserNuestro.y"
                                   {
        // Añadimos el ID booleano al inicio de la lista ya existente
        agregarID((yyvsp[0].lista_ids), (yyvsp[-2].cadena));
        (yyval.lista_ids) = (yyvsp[0].lista_ids);
    }
#line 1533 "parserNuestro.tab.c"
    break;

  case 40: /* d_tipo: TUPLA_TK lista_campos FTUPLA_TK  */
#line 324 "parserNuestro.y"
        {}
#line 1539 "parserNuestro.tab.c"
    break;

  case 41: /* d_tipo: TABLA_TK INICIO_ARRAY_TK expresion_t DOBLEPUNTO_TK expresion_t CIERRE_ARRAY_TK DE_TK d_tipo  */
#line 326 "parserNuestro.y"
        {}
#line 1545 "parserNuestro.tab.c"
    break;

  case 42: /* d_tipo: ID_TK  */
#line 328 "parserNuestro.y"
        {}
#line 1551 "parserNuestro.tab.c"
    break;

  case 43: /* d_tipo: expresion_t DOBLEPUNTO_TK expresion_t  */
#line 330 "parserNuestro.y"
        {}
#line 1557 "parserNuestro.tab.c"
    break;

  case 44: /* d_tipo: REF_TK d_tipo  */
#line 332 "parserNuestro.y"
        {
		(yyval.tipo) = (yyvsp[0].tipo);
	}
#line 1565 "parserNuestro.tab.c"
    break;

  case 45: /* d_tipo: tipo_base  */
#line 336 "parserNuestro.y"
        {
		(yyval.tipo) = (yyvsp[0].tipo);
	}
#line 1573 "parserNuestro.tab.c"
    break;

  case 50: /* tipo_base: ENTERO_TK  */
#line 353 "parserNuestro.y"
                { (yyval.tipo) = ENTERO; }
#line 1579 "parserNuestro.tab.c"
    break;

  case 51: /* tipo_base: BOOLEANO_TK  */
#line 354 "parserNuestro.y"
                { (yyval.tipo) = BOOLEANO; }
#line 1585 "parserNuestro.tab.c"
    break;

  case 52: /* tipo_base: CARACTER_TK  */
#line 355 "parserNuestro.y"
                { (yyval.tipo) = CARACTER; }
#line 1591 "parserNuestro.tab.c"
    break;

  case 53: /* tipo_base: REAL_TK  */
#line 356 "parserNuestro.y"
                { (yyval.tipo) = REAL; }
#line 1597 "parserNuestro.tab.c"
    break;

  case 54: /* tipo_base: CADENA_TK  */
#line 357 "parserNuestro.y"
                { (yyval.tipo) = CADENA; }
#line 1603 "parserNuestro.tab.c"
    break;

  case 55: /* expresion: exp_b  */
#line 363 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[0].id_simbolo);
	}
#line 1611 "parserNuestro.tab.c"
    break;

  case 56: /* expresion: exp_a  */
#line 367 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[0].id_simbolo);
	}
#line 1619 "parserNuestro.tab.c"
    break;

  case 57: /* expresion: funcion_ll  */
#line 371 "parserNuestro.y"
        {}
#line 1625 "parserNuestro.tab.c"
    break;

  case 58: /* exp_a: exp_a MAS_TK exp_a  */
#line 376 "parserNuestro.y"
        {
		// Guardamos el tipo para saber el tipo de operacion suma (SUMAENT o SUMAREAL)
		NombreDeTipoT tipo1 = obtenerTipoPorIndice((yyvsp[-2].id_simbolo));
		NombreDeTipoT tipo2 = obtenerTipoPorIndice((yyvsp[0].id_simbolo));
		
		// Crear temporal del tipo apropiado
		NombreDeTipoT tipoResultado = (tipo1 == REAL || tipo2 == REAL) ? REAL : ENTERO;
		int temp = newTemp(tipoResultado);
		
		// Generar cuádrupla
		OperadorT op = (tipoResultado == REAL) ? SUMAREAL : SUMAENT;
		gen(op, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		
		(yyval.id_simbolo) = temp;
	}
#line 1645 "parserNuestro.tab.c"
    break;

  case 59: /* exp_a: exp_a MENOS_TK exp_a  */
#line 392 "parserNuestro.y"
        {
		NombreDeTipoT tipo1 = obtenerTipoPorIndice((yyvsp[-2].id_simbolo));
		NombreDeTipoT tipo2 = obtenerTipoPorIndice((yyvsp[0].id_simbolo));
		NombreDeTipoT tipoResultado = (tipo1 == REAL || tipo2 == REAL) ? REAL : ENTERO;
		int temp = newTemp(tipoResultado);
		OperadorT op = (tipoResultado == REAL) ? RESTAREAL : RESTAENT;
		gen(op, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		(yyval.id_simbolo) = temp;
	}
#line 1659 "parserNuestro.tab.c"
    break;

  case 60: /* exp_a: exp_a MULTIPLICACION_TK exp_a  */
#line 402 "parserNuestro.y"
        {
		NombreDeTipoT tipo1 = obtenerTipoPorIndice((yyvsp[-2].id_simbolo));
		NombreDeTipoT tipo2 = obtenerTipoPorIndice((yyvsp[0].id_simbolo));
		NombreDeTipoT tipoResultado = (tipo1 == REAL || tipo2 == REAL) ? REAL : ENTERO;
		int temp = newTemp(tipoResultado);
		OperadorT op = (tipoResultado == REAL) ? MULTREAL : MULTENT;
		gen(op, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		(yyval.id_simbolo) = temp;
	}
#line 1673 "parserNuestro.tab.c"
    break;

  case 61: /* exp_a: exp_a DIVREAL_TK exp_a  */
#line 412 "parserNuestro.y"
        {
		int temp = newTemp(REAL);
        	gen(DIVREAL, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
        (yyval.id_simbolo) = temp;
	}
#line 1683 "parserNuestro.tab.c"
    break;

  case 62: /* exp_a: exp_a MOD_TK exp_a  */
#line 418 "parserNuestro.y"
        {
		int temp = newTemp(ENTERO);
        	gen(MODULO, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
        (yyval.id_simbolo) = temp;
	}
#line 1693 "parserNuestro.tab.c"
    break;

  case 63: /* exp_a: exp_a DIV_TK exp_a  */
#line 424 "parserNuestro.y"
        {
		int temp = newTemp(ENTERO);
        	gen(DIVENT, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
        (yyval.id_simbolo) = temp;
	}
#line 1703 "parserNuestro.tab.c"
    break;

  case 64: /* exp_a: PARENTESIS_APERTURA_TK exp_a PARENTESIS_CIERRE_TK  */
#line 430 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[-1].id_simbolo);
	}
#line 1711 "parserNuestro.tab.c"
    break;

  case 65: /* exp_a: operando  */
#line 434 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[0].id_simbolo);
	}
#line 1719 "parserNuestro.tab.c"
    break;

  case 66: /* exp_a: MENOS_TK exp_a  */
#line 438 "parserNuestro.y"
        {
		NombreDeTipoT tipo = obtenerTipoPorIndice((yyvsp[0].id_simbolo));
		int temp = newTemp(tipo);
		
		// Crear constante 0
		char nombreCero[5];
		sprintf(nombreCero, "_cero");
		int idCero = buscarSimbolo(nombreCero);
		if (idCero == -1) {
		    idCero = agregarVariable(nombreCero, tipo);
		}
		
		OperadorT op = (tipo == REAL) ? RESTAREAL : RESTAENT;
		gen(op, idCero, (yyvsp[0].id_simbolo), temp);
        	(yyval.id_simbolo) = temp;
	}
#line 1740 "parserNuestro.tab.c"
    break;

  case 67: /* exp_a: MAS_TK exp_a  */
#line 455 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[0].id_simbolo);
	}
#line 1748 "parserNuestro.tab.c"
    break;

  case 68: /* exp_b: exp_b Y_TK exp_b  */
#line 462 "parserNuestro.y"
        {
		int temp = newTemp(BOOLEANO);
		gen(Y_OP, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		(yyval.id_simbolo) = temp;
	}
#line 1758 "parserNuestro.tab.c"
    break;

  case 69: /* exp_b: exp_b O_TK exp_b  */
#line 468 "parserNuestro.y"
        {
		int temp = newTemp(BOOLEANO);
		gen(O_OP, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		(yyval.id_simbolo) = temp;
	}
#line 1768 "parserNuestro.tab.c"
    break;

  case 70: /* exp_b: NO_TK exp_b  */
#line 474 "parserNuestro.y"
        {
		int temp = newTemp(BOOLEANO);
		gen(NO_OP, (yyvsp[0].id_simbolo), -1, temp); //solo importa el $2
		(yyval.id_simbolo) = temp;
	}
#line 1778 "parserNuestro.tab.c"
    break;

  case 71: /* exp_b: operando_booleano  */
#line 480 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[0].id_simbolo);
	}
#line 1786 "parserNuestro.tab.c"
    break;

  case 72: /* exp_b: VERDADERO_TK  */
#line 484 "parserNuestro.y"
        {
		// Crear literal booleano verdadero
		int id = buscarSimbolo("_litverdadero");
		if (id == -1) {
			//si no existe agregarlo y usarlo
			id = agregarVariable("_true", BOOLEANO);
		}
		(yyval.id_simbolo) = id;
	}
#line 1800 "parserNuestro.tab.c"
    break;

  case 73: /* exp_b: FALSO_TK  */
#line 494 "parserNuestro.y"
        {
		// Crear literal booleano falso
		int id = buscarSimbolo("_litfalso");
		if (id == -1) {
			id = agregarVariable("_false", BOOLEANO);
		}
		(yyval.id_simbolo) = id;
	}
#line 1813 "parserNuestro.tab.c"
    break;

  case 74: /* exp_b: exp_a oprel exp_a  */
#line 503 "parserNuestro.y"
        {
		int temp = newTemp(BOOLEANO);
		
		// Determinar tipos
		NombreDeTipoT tipo1 = obtenerTipoPorIndice((yyvsp[-2].id_simbolo));
		NombreDeTipoT tipo2 = obtenerTipoPorIndice((yyvsp[0].id_simbolo));
		int esReal = (tipo1 == REAL || tipo2 == REAL);
		
		// Ajustar operador según el tipo
		OperadorT op = (yyvsp[-1].id_simbolo); // Operador base de oprel
		
		//si es real (tenemos por defecto entero) se asigna real dependiendo si es menor,mayor etc
		if (esReal) {
			// Convertir a versión REAL
			switch((yyvsp[-1].id_simbolo)) {
				case MENORENT: op = MENORREAL; break;
				case MAYORENT: op = MAYORREAL; break;
				case IGUALENT: op = IGUALREAL; break;
				case DISTINTENT: op = DISTINREAL; break;
				case MAYORIGUALENT: op = MAYORIGUALREAL; break;
				case MENORIGUALENT: op = MENORIGUALREAL; break;
				default: op = (yyvsp[-1].id_simbolo);
			}
		}
		
		gen(op, (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo), temp);
		(yyval.id_simbolo) = temp;
	}
#line 1846 "parserNuestro.tab.c"
    break;

  case 75: /* exp_b: PARENTESIS_APERTURA_TK exp_b PARENTESIS_CIERRE_TK  */
#line 532 "parserNuestro.y"
        {
		(yyval.id_simbolo) = (yyvsp[-1].id_simbolo);
	}
#line 1854 "parserNuestro.tab.c"
    break;

  case 76: /* oprel: MENOR_TK  */
#line 539 "parserNuestro.y"
        {
		(yyval.id_simbolo) = MENORENT; //necesitamos saber si es ent o real -> por defecto entero
	}
#line 1862 "parserNuestro.tab.c"
    break;

  case 77: /* oprel: MAYOR_TK  */
#line 543 "parserNuestro.y"
        {
		(yyval.id_simbolo) = MAYORENT;
	}
#line 1870 "parserNuestro.tab.c"
    break;

  case 78: /* oprel: IGUAL_TK  */
#line 547 "parserNuestro.y"
        {
		(yyval.id_simbolo) = IGUALENT;
	}
#line 1878 "parserNuestro.tab.c"
    break;

  case 79: /* oprel: DISTINTO_TK  */
#line 551 "parserNuestro.y"
        {
		(yyval.id_simbolo) = DISTINTENT;
	}
#line 1886 "parserNuestro.tab.c"
    break;

  case 80: /* oprel: MAYORIGUAL_TK  */
#line 555 "parserNuestro.y"
        {
		(yyval.id_simbolo) = MAYORIGUALENT;
	}
#line 1894 "parserNuestro.tab.c"
    break;

  case 81: /* oprel: MENORIGUAL_TK  */
#line 559 "parserNuestro.y"
        {
		(yyval.id_simbolo) = MENORIGUALENT;
	}
#line 1902 "parserNuestro.tab.c"
    break;

  case 82: /* operando: ID_TK  */
#line 567 "parserNuestro.y"
        {
		// Buscar el ID en la tabla de símbolos
		int id = buscarSimbolo((yyvsp[0].cadena));
		if (id == -1) {
			// Si es una constante, buscarla en tabla de constantes
			LiteralT* lit = buscarConstante(tc, (yyvsp[0].cadena));
			if (lit != NULL) {
				// Crear entrada temporal en tabla de símbolos para la constante
				id = agregarVariable((yyvsp[0].cadena), lit->tipoDelValor);
			} else {
				printf("Error: identificador '%s' no declarado\n", (yyvsp[0].cadena));
				exit(1);
			}
		}
		(yyval.id_simbolo) = id;
	}
#line 1923 "parserNuestro.tab.c"
    break;

  case 86: /* operando: literal  */
#line 587 "parserNuestro.y"
        {
		char tempName[100];
		int idTemp;
		
		switch((yyvsp[0].literal).tipoDelValor) {
			case ENTERO:
				sprintf(tempName, "_lit%d", (yyvsp[0].literal).valor.valorEntero);
				break;
				
			case BOOLEANO:
				if ((yyvsp[0].literal).valor.valorBooleano == VERDADERO)
					sprintf(tempName, "_litverdadero");
				else
					sprintf(tempName, "_litfalso");
				break;
				
			case REAL: {
				// Convertir el real a string sin notación científica
				// y reemplazar caracteres problemáticos
				char realStr[50];
				sprintf(realStr, "%.6f", (yyvsp[0].literal).valor.valorReal);
				
				// Reemplazar '.' por '_' y '-' por 'n' para nombre válido
				sprintf(tempName, "_litr");
				for (int i = 0; realStr[i] != '\0' && i < 40; i++) {
					char c = realStr[i];
					if (c == '.') strcat(tempName, "_");
					else if (c == '-') strcat(tempName, "n");
					else if (c >= '0' && c <= '9') {
						char digit[2] = {c, '\0'};
						strcat(tempName, digit);
					}
				}
				break;
			}
				
			case CARACTER: {
				// Manejar caracteres especiales
				char c = (yyvsp[0].literal).valor.valorCaracter;
				if (c == ' ')
					sprintf(tempName, "_lit_espacio");
				else if (c == '\n')
					sprintf(tempName, "_lit_salto");
				else if (c == '\t')
					sprintf(tempName, "_lit_tab");
				else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
					sprintf(tempName, "_lit_%c", c);
				else
					sprintf(tempName, "_lit_car_%d", (int)c);
				break;
			}
				
			case CADENA: {
				// Para cadenas, crear un nombre único basado en hash o contador
				static int contadorCadenas = 0;
				sprintf(tempName, "_lit_cadena_%d", contadorCadenas++);
				break;
			}
				
			default:
				sprintf(tempName, "_lit_desconocido");
				break;
		}
		
		// Verificar si ya existe en tabla de símbolos
		idTemp = buscarSimbolo(tempName);
		if (idTemp == -1) {
			idTemp = agregarVariable(tempName, (yyvsp[0].literal).tipoDelValor);
		}
		
		(yyval.id_simbolo) = idTemp;
	}
#line 2000 "parserNuestro.tab.c"
    break;

  case 87: /* operando_booleano: IDBOOLEANO_TK  */
#line 663 "parserNuestro.y"
        {
		// Buscar la variable booleana en la tabla de símbolos
		int id = buscarSimbolo((yyvsp[0].cadena));
		if (id == -1) {
			printf("Error: variable booleana '%s' no declarada\n", (yyvsp[0].cadena));
			exit(1);
		}
		(yyval.id_simbolo) = id;
	}
#line 2014 "parserNuestro.tab.c"
    break;

  case 95: /* asignacion: operando ASIGNACION_TK expresion  */
#line 690 "parserNuestro.y"
        {
		printf("DEBUG: ASIGNACION generada: id_dest=%d id_src=%d\n", (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo));
		gen(ASIGNACION, (yyvsp[0].id_simbolo), -1, (yyvsp[-2].id_simbolo));
	}
#line 2023 "parserNuestro.tab.c"
    break;

  case 96: /* asignacion: operando_booleano ASIGNACION_TK expresion  */
#line 695 "parserNuestro.y"
        {
		printf("DEBUG: ASIGNACION BOOLEANA: id_dest=%d id_src=%d\n", (yyvsp[-2].id_simbolo), (yyvsp[0].id_simbolo));
		gen(ASIGNACION, (yyvsp[0].id_simbolo), -1, (yyvsp[-2].id_simbolo));
	}
#line 2032 "parserNuestro.tab.c"
    break;


#line 2036 "parserNuestro.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 761 "parserNuestro.y"


int main(int argc, char **argv){
	#if defined YYDEBUG
	yydebug=1;
	#endif
	++argv, --argc;

	listaIDs = nuevaListaIDs();
    tc = nuevaTablaDeConstantes();

    nuevaTablaDeSimbolos();   // Inicializamos la tabla de símbolos
	inicializarCuadruplas();      // Inicializar cuádrupla

	if (argc > 0)
		yyin = fopen(argv[0], "r");
	else
		yyin = stdin;

	yyparse();

	printf("\n=== RESULTADOS DE LA COMPILACIÓN ===\n");
	imprimeTablaDeConstantes(tc);
	imprimirTabla();
	imprimirCuadruplas();

}


void yyerror(char * s){
	printf("\tBISON: ERROR, %s\n", s);
}
