/* datatype.h */
#ifndef DATATYPE_H
#define DATATYPE_H

#define MAX_NAME_LENGTH 100
#define MAX_BOOKS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    double price;
} Book;

#endif

