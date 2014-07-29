/* 
 * File:   FileHandler.h
 * Author: henriquevalcanaia
 *
 * Created on June 9, 2014, 11:30 PM
 */

#include "Constantes.h"

#ifndef FILEHANDLER_H
#define	FILEHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

    int parseLine(char *content);
    char *readLine(FILE *file);
    FILE *openFile(char *path);
    void setInputFile(char file[STR_BUFFER]);
    void setOutputFile(char file[STR_BUFFER]);
    int writeFile(char *text);
    char *readLine(char *in);
    int x(void);


#ifdef	__cplusplus
}
#endif

#endif	/* FILEHANDLER_H */

