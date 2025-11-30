compilador: parserNuestro.tab.o lex.yy.o literal.o literal.h tablaDeConstantes.o tablaDeConstantes.h tablaDeSimbolos.o cuadrupla.o listaIDs.o
	gcc parserNuestro.tab.o lex.yy.o tablaDeConstantes.o literal.o tablaDeSimbolos.o cuadrupla.o listaIDs.o -lfl
	mv a.out compilador

parserNuestro.tab.c parserNuestro.tab.h: parserNuestro.y literal.h nombresDeTipos.h tablaDeConstantes.h
	bison -d -v -t parserNuestro.y

lex.yy.o: scannerNuestro.l parserNuestro.tab.h literal.h nombresDeTipos.h tablaDeConstantes.h
	flex scannerNuestro.l
	gcc -c lex.yy.c

literal.o: literal.c
	gcc -c literal.c

tablaDeSimbolos.o: tablaDeSimbolos.c
	gcc -c tablaDeSimbolos.c

tablaDeConstantes.o: tablaDeConstantes.c
	gcc -c tablaDeConstantes.c

cuadrupla.o: cuadrupla.c
	gcc -c cuadrupla.c

listaIDs.o: listaIDs.c
	gcc -c listaIDs.c

scanner: scannerNuestro.l
	flex scannerNuestro.l
	gcc lex.yy.c -lfl
	mv a.out scanner

clean:
	rm -f *.tab.* lex.yy.c *.o parser.output compilador
