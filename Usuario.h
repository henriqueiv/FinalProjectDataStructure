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

typedef struct TUsuario Usuario;
typedef struct TListaUsuario ListaUsuario;
typedef struct TArvoreUsuario ArvoreUsuario;

int insereUsuario(Usuario *usuario);
void exibeUsuarios(int ordem, int k);
void montaProgramacao();
int existeUsuario(Usuario *usuario);

#ifdef	__cplusplus
}
#endif

#endif	/* USUARIO_H */

