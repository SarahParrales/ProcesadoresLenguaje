#ifndef LISTAIDS_H
#define LISTAIDS_H

#define MAX_IDS 100

typedef struct {
    char* ids[MAX_IDS];
    int n;
} ListaIDs;

ListaIDs* nuevaListaIDs(void);
void agregarID(ListaIDs* lista, char* id);

#endif
