
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Constantes.h"
#define PRINT_RETORNOS_PARSE 0

FILE *inputFile;
FILE *outputFile;

int setInputFile(char file[STR_BUFFER]) {
    inputFile = fopen(file, "r");
    if (inputFile == NULL) {
        perror("Erro abrindo no arquivo");
        return ERRO;
    }
    return SUCESSO;
}

int setOutputFile(char file[STR_BUFFER]) {
    outputFile = fopen(file, "+a");
    if (outputFile == NULL) {
        perror("Erro abrindo no arquivo");
        return ERRO;
    }
    return SUCESSO;
}

void processFile() {
    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t read;

    while ((read = getline(&line, &len, inputFile)) != -1) {
        parseLine(line);
    }
}

int parseLine(char *input) {
    int i = 0;
    char *p;
    char *retornos[3];
    p = strtok(input, " ");
    if (p) {
        retornos[i] = p;
        i++;
    }
    while (p) {
        p = strtok(NULL, " ");
        if (p) {
            retornos[i] = p;
            i++;
        }
    }
    
    exec(retornos);

    if (PRINT_RETORNOS_PARSE) {
        for (int x = 0; x < i; x++) {
            printf("retornos[%d]: %s\n", x, retornos[x]);
        }
    }
    return 0;
}

int writeFile(char *text) {
    fwrite(text, sizeof (char), sizeof (text), outputFile);
    if (ferror(outputFile)) {
        perror("Erro escrevendo no arquivo");
        return ERRO;
    }
    return SUCESSO;
}