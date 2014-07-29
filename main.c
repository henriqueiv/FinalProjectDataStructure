/* 
 * File:   main.c
 * Author: henriquevalcanaia
 *
 * Created on June 4, 2014, 9:03 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "FileHandler.h"

void startProcess(){
    processFile();
}

void init(){
    setInputFile("in.txt");
    setOutputFile("out.txt");
}

int main(int argc, char** argv) {
    init();
    printf("%s", readLine());
    startProcess();
    return (EXIT_SUCCESS);
}

