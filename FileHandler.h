/* 
 * File:   FileHandler.h
 * Author: henriquevalcanaia
 *
 * Created on June 9, 2014, 11:30 PM
 */

#ifndef FILEHANDLER_H
#define	FILEHANDLER_H

#ifdef	__cplusplus
extern "C" {
#endif

    int parseLine(char *content);
    char *readLine(FILE *file);
    FILE *openFile(char *path);


#ifdef	__cplusplus
}
#endif

#endif	/* FILEHANDLER_H */

