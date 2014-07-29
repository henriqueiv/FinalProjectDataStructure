#include "Constantes.h"
#include "Funcoes.h"

void exec(char *data[4]) {
    char c = data[IDX_OPERACAO];
    switch (c) {
        case INSERE_USUARIO:
        {
            insereUsuario(data[IDX_ARG1]);
        }
        case EXIBE_USUARIOS:
        {
            exibeUsuarios(data[IDX_ARG1], data[IDX_ARG2]);
        }
        case MONTA_PROG:
        {
            montaProg(data[IDX_ARG1], data[IDX_ARG2], data[IDX_ARG3]);
        }
        case SHARE_PROG:
        {
            shareProg(data[IDX_ARG1], data[IDX_ARG2], data[IDX_ARG3]);
        }
        case EXIBE_PROG:
        {
            //exibeProg(data[IDX_ARG1]);
        }
        case OUVE_PROG:
        {
            shareProg(data[IDX_ARG1], data[IDX_ARG2]);
        }
        case RANKING_PROG:
        {
            //rankingProg(data[IDX_ARG1]);
        }
        default:
        {
            writeFile("Funcao '" + data[IDX_OPERACAO] + "' inexistente.");
        }

    }
}
