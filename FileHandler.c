
#include <stdio.h>
#include <string.h>
#include "Constantes.h"

char *inputFile;
char *outputFile;

void setInputFile(char file[STR_BUFFER]) {
    inputFile = (char*) malloc(sizeof (char) * strlen(file));
    inputFile = file;
}

void setInputFile(char file[STR_BUFFER]) {
    outputFile = (char*) malloc(sizeof (char) * strlen(file));
    outputFile = file;
}

// Só é feito write no arquivo de saída

int writeFile(char *texto) {
    FILE *file = fopen(outputFile, "a+");
    if (file == NULL) {
        perror("Erro abrindo no arquivo");
        return ERRO;
    }

    fwrite(texto, sizeof (char), sizeof (texto), file);
    if (ferror()) {
        perror("Erro escrevendo no arquivo");
        return ERRO;
    }

    return SUCESSO;
}

char *readLine(char *in) {
    char *cptr;

    if (cptr = fgets(in, STR_BUFFER - 1, stdin)) {
        // kill preceding whitespace but leave \n so we're guaranteed to have something
        while (*cptr == ' ' || *cptr == '\t') {
            cptr++;
        }
        return cptr;
    } else {
        return 0;
    }
}

int x() {
    char str[200];
    FILE *fp = fopen("test.txt", "r");
    if (!fp) return 1; // bail out if file not found
    while (fgets(str, sizeof (str), fp) != NULL) {
        int len = strlen(str) - 1;
        if (str[len] == '')
            str[len] = 0;
        printf("%s", str);
    }
    fclose(fp);
}


