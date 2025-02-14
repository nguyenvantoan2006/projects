#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

void displayMenu();
void displayBooks(Book books[], int count);
void addBook(Book books[], int *count);
void editBook(Book books[], int count);
void deleteBook(Book books[], int *count);
void searchBook(Book books[], int count);
void sortBooks(Book books[], int count);
void saveToFile(Book books[], int count);
void loadFromFile(Book books[], int *count);

#endif
