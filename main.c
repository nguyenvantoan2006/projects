#include <stdio.h>
#include "function.h"

int main() {
    Book books[MAX_BOOKS];
    int count = 0;
    int choice;

    loadFromFile(books, &count);

    do {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                displayBooks(books, count);
                break;
            case 2:
                addBook(books, &count);
                break;
            case 3:
                editBook(books, count);
                break;
            case 4:
                deleteBook(books, &count);
                break;
            case 5:
                searchBook(books, count);
                break;
            case 6:
                sortBooks(books, count);
                break;
            case 7:
                saveToFile(books, count);
                break;
            case 8:
                printf("Tho�t chuong tr�nh!\n");
                break;
            default:
                printf("L?a ch?n kh�ng h?p l?, vui l�ng th? l?i.\n");
        }
    } while (choice != 8);

    return 0;
}
