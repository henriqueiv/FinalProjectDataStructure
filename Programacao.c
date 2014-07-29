#include <stdlib.h>
#include "Musica.h"
#include "Usuario.h"
#include "FileHandler.h"

typedef struct TProgramacao {
    char *nome;
    ListaUsuario *usuarios;
    ListaMusica *mus;
} Programacao;

typedef struct TListaProgramacao {
    Programacao *prog;
    ListaProgramacao *prox;
} ListaProgramacao;

typedef struct TArvoreProgramacao {
    Programacao *prog;
    ArvoreProgramacao *esq;
    ArvoreProgramacao *dir;
} ArvoreProgramacao;

ListaProgramacao *lista = (ListaProgramacao*) malloc(sizeof (ListaProgramacao));

void montaProg(Usuario *user, Programacao *prog, Musica *mus) {
    Usuario *u = (Programacao*) malloc(sizeof (Programacao));
    u = getProgramacao(user, prog);
    if (existeUsuario(user)) {
        Programacao *p = (Programacao*) malloc(sizeof (Programacao));
        p = getProgramacao(user, prog);
        if (p == NULL) {
            criaProgramacao(prog);
        }

        addMusica(p, mus);
        insereProgramacao(prog);
    } else {
        writeFile("Usuario nao cadastrado");
    }
}

void shareProg(Usuario *owner, Usuario *shared, Programacao *prog) {
    Programacao *p = (Programacao*) malloc(sizeof (Programacao));
    p = getProgramacao(prog);
    if(validaDados(Usuario *owner, Usuario *shared, Programacao *p)){
        ListaUsuario *l = (ListaProgramacao*) malloc(sizeof(ListaProgramacao));
        l = p->usuarios;
        addUsuario
    }
}

int validaDados(Usuario *owner, Usuario *shared, Programacao *prog){
    if (prog == NULL) {
        writeFile("Programacao nao cadastrada");
    } else {
        if (!existeUsuario(owner)) {
            writeFile("Usuario '" + owner->nome + "' nao cadastrado");
        } else {
            if (!existeUsuario(shared)) {
                writeFile("Usuario '" + shared->nome + "' nao cadastrado");
            }else{
                return SUCESSO;
            }
        }
    }
    return ERRO;
}

Programacao *getProgramacao(Usuario *user, Programacao *p) {
    if (p == NULL)
        return NULL;

    ListaProgramacao *aux;
    aux = lista->prox;
    while (aux->prog != NULL) {
        if (strcmp(aux->prog->nome, p->nome) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void criaProgramacao(Programacao *p) {
    lista->prox = p;
}

void addMusica(Programacao *p, Musica *m) {
    ListaMusica *aux = p->mus;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox->mus = m;
}

void insereProgramacao(Programacao *prog) {
    ListaProgramacao *aux = (ListaProgramacao*) malloc(sizeof (ListaProgramacao));
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = prog;
}