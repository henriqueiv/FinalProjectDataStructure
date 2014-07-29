#include "Musica.h"
#include <string.h>

typedef struct TMusica {
    char *mus;
    int plays;
} Musica;

typedef struct TListMusica {
    Musica *mus;
    ListaMusica *ant;
    ListaMusica *prox;
} ListaMusica;

typedef struct TArvoreMusica {
    Musica *mus;
    ArvoreMusica *esq;
    ArvoreMusica *dir;
} ArvoreMusica;

/*
void centralEsquerda(Usuario *usuario, int limit) {
    static count = 0;
    count++;
    if (usuario != NULL && count <= limit) {
        centralEsquerda(usuario->esq);
        printf("%d, ", usuario->mus);
        centralEsquerda(usuario->dir);
    }
}

void centralDireita(Usuario *usuario, int limit) {
    static count = 0;
    count++;
    if (usuario != NULL && count <= limit) {
        centralDireita(usuario->dir);
        printf("%d, ", usuario->mus);
        centralDireita(usuario->esq);
    }
}
 * */
