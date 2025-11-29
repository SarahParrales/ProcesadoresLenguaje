CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lfl

OBJS = parserNuestro.tab.o lex.yy.o tablaDeConstantes.o \
       literal.o tablaDeSimbolos.o cuadrupla.o listaIDs.o

programa: $(OBJS)
	$(CC) $(OBJS) -o programa $(LDFLAGS)

parserNuestro.tab.o: parserNuestro.tab.c parserNuestro.tab.h tablaDeConstantes.h tablaDeSimbolos.h cuadrupla.h listaIDs.h literal.h
lex.yy.o: lex.yy.c parserNuestro.tab.h tablaDeConstantes.h tablaDeSimbolos.h cuadrupla.h listaIDs.h literal.h
tablaDeConstantes.o: tablaDeConstantes.c tablaDeConstantes.h literal.h
literal.o: literal.c literal.h
tablaDeSimbolos.o: tablaDeSimbolos.c tablaDeSimbolos.h literal.h
cuadrupla.o: cuadrupla.c cuadrupla.h tablaDeSimbolos.h literal.h
listaIDs.o: listaIDs.c listaIDs.h tablaDeSimbolos.h literal.h

clean:
	rm -f *.o programa
