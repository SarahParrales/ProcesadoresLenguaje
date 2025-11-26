#include <string.h>
#include <stdlib.h>
#include "listaIDs.h"

ListaIDs* nuevaListaIDs(void) {
    ListaIDs* l = malloc(sizeof(ListaIDs));
    if (!l) return NULL; // manejo de error
    l->n = 0;
    for(int i = 0; i < MAX_IDS; i++)
        l->ids[i] = NULL; // inicializar punteros
    return l;
}

void agregarID(ListaIDs* lista, char* id) {
    if(lista->n < MAX_IDS)
        lista->ids[lista->n++] = strdup(id);
}
