#include "Usuario.h"
#include <string.h>

typedef struct TUsuario {
    char *nome;
    Usuario *esq;
    Usuario *dir;
} Usuario;

int insereUsuario(Usuario *usuario);
void exibeUsuarios(int ordem, int k);

//-- funcoes auxiliares
int existeUsuario(Usuario *usuario);

int insereUsuario(Usuario *raiz, char *nome) {
    if (!existeUsuario(nome)) {
        if (raiz == NULL) {
            raiz = (Usuario*) malloc(sizeof (Usuario));
            raiz->nome = nome;
            raiz->esq = NULL;
            raiz->dir = NULL;
            return raiz;
        } else
            if (strcmp(nome, raiz->nome) > 0) {
            raiz->dir = insereUsuario(raiz->dir, nome);
        } else {
            raiz->esq = insereUsuario(raiz->esq, nome);
        }
    }

    return 1;
}

int existeUsuario(Usuario *raiz, char *pesquisado) {
    
}

void exibeUsuarios(){
    
}

void centralEsquerda(Usuario *usuario, int limit) {
    static count = 0;
    count++;
    if (usuario != NULL && count <= limit) {
        centralEsquerda(usuario->esq);
        printf("%d, ", usuario->nome);
        centralEsquerda(usuario->dir);
    }
}

void centralDireita(Usuario *usuario, int limit) {
    static count = 0;
    count++;
    if (usuario != NULL && count <= limit) {
        centralDireita(usuario->dir);
        printf("%d, ", usuario->nome);
        centralDireita(usuario->esq);
    }
}
