#include "Usuario.h"
#include "Programacao.h"
#include "Constantes.h"
#include <string.h>

struct TUsuario {
    char *nome;
    ListaProgramacao *prog;
} Usuario;

struct TListaUsuario {
    Usuario *user;
    ListaUsuario *ant;
    ListaUsuario *prox;
} ListaUsuario;

struct TArvoreUsuario {
    Usuario *user;
    ArvoreUsuario *esq;
    ArvoreUsuario *dir;
} ArvoreUsuario;

int insereUsuario(Usuario *usuario);
void exibeUsuarios(int ordem, int k);
void montaProgramacao();
int existeUsuario(Usuario *usuario);

//-- funcoes auxiliares
int insereUsuario(ArvoreUsuario *raiz, Usuario *user) {
    if (!existeUsuario(user)) {
        if (raiz == NULL) {
            raiz->user = user;
            return raiz;
        } else {
            if (strcmp(user->nome, raiz->user->nome) > 0) {
                raiz->dir = insereUsuario(raiz->dir, user);
            } else {
                raiz->esq = insereUsuario(raiz->esq, user);
            }
        }
        return SUCESSO;
    } else {
        return USUARIO_JA_EXISTENTE;
    }

}

int existeUsuario(ArvoreUsuario *raiz, Usuario *user) {
    Usuario encontrado = (Usuario*) malloc(sizeof(Usuario));
    encontrado = consultaABP(raiz, user);
    if(encontrado == NULL){
        return USUARIO_NAO_ENCONTRADO;
    }else{
        return USUARIO_ENCONTRADO;
    }
}

void exibeUsuarios(ArvoreUsuario *raiz, int ordem, int numUsuarios) {
    switch(ordem){
        case 1: //ASC
            centralEsquerda(raiz, numUsuarios);
        case 2: //DESC
            centralDireita(raiz, numUsuarios);
    }
}

Usuario* consultaABP(ArvoreUsuario *a, Usuario *user) {
    if (a != NULL) {
        if (strcmp(user->nome, a->user->nome) == 0)
            return a->user;
        else
            if (strcmp(user->nome, a->user->nome) > 0)
            return consultaABP(a->esq, user);

        if (strcmp(user->nome, a->user->nome) < 0)
            return consultaABP(a->dir, user);

        else return a-> user;
    } else return NULL;
}

void centralEsquerda(ArvoreUsuario *raiz, int limit) {
    static count = 0;
    count++;
    if (raiz != NULL && count <= limit) {
        centralEsquerda(raiz->esq);
        printf("%s, ", raiz->user->nome);
        centralEsquerda(raiz->dir);
    }
}

void centralDireita(ArvoreUsuario *raiz, int limit) {
    static count = 0;
    count++;
    if (raiz != NULL && count <= limit) {
        centralDireita(raiz->dir);
        printf("%d, ", raiz->user->nome);
        centralDireita(raiz->esq);
    }
}
