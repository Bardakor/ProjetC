/* primary_header.h */
#ifndef PRIMARY_HEADER_H
#define PRIMARY_HEADER_H

#include <stdio.h>

char **split(char *, int *);

int isNom(char *);

int isVer(char *);

int isAdj(char *);

int isAdv(char *);

char *getType(char *);

char *getLine(char *, int );

char *getNom(char *);

char *getVer(char *);

char *getAdj(char *);

char *getAdv(char *);

int display();

int displayNom();

int displayVer();

int displayAdj();

int displayAdv();


#endif /* PRIMARY_HEADER_H */