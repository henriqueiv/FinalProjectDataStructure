/* 
 * File:   Usuario.h
 * Author: henriquevalcanaia
 *
 * Created on June 4, 2014, 9:25 PM
 */

#ifndef USUARIO_H
#define	USUARIO_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct TUsuario {
    char *nome;
    Usuario *esq;
    Usuario *dir;
} Usuario;

int insereUsuario(Usuario *usuario);
void exibeUsuarios(int ordem, int k);
int existeUsuario(Usuario *usuario);

typedef struct Tusuario pNodoA;

pNodoA* InsereArvore(pNodoA *a, int ch);
void preFixado(pNodoA *a);
void posFixado(pNodoA *a);
void central(pNodoA *a);
pNodoA* consultaABP(pNodoA *a, int chave);
pNodoA* consultaABP2(pNodoA *a, int chave);

int getNosFolha(pNodoA *raiz);
int getNosFolhaChave(pNodoA *arv, int chave);
int max(int a, int b);
int altura(pNodoA *a);


#ifdef	__cplusplus
}
#endif

#endif	/* USUARIO_H */

