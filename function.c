/* function.c */
#include <stdio.h>
#include <string.h>
#include "function.h"

void displayMenu() {
    printf("\n===== Quan ly Sach =====\n");
    printf("1. Hien thi danh sach sach\n");
    printf("2. Them sach\n");
    printf("3. Sua thong tin sach\n");
    printf("4. Xoa sach\n");
    printf("5. Tim kiem sach theo ten\n");
    printf("6. Sap xep sach\n");
    printf("7. Luu du lieu vao file\n");
    printf("8. Thoat\n");
    printf("Chon mot lua chon: ");
}

void displayBooks(Book books[], int count) {
    printf("\nDanh sach sach:\n");
    int i;
    for ( i = 0; i < count; i++) {
        printf("ID: %d | Ten: %s | Gia: %.2f\n", books[i].id, books[i].name, books[i].price);
    }
}

void addBook(Book books[], int *count) {
    if (*count >= MAX_BOOKS) {
        printf("Khong the them sach, du lieu da day!\n");
        return;
    }
    printf("Nhap ID: ");
    scanf("%d", &books[*count].id);
    getchar(); // Xoa bo dem
    printf("Nhap ten sach: ");
    fgets(books[*count].name, MAX_NAME_LENGTH, stdin);
    books[*count].name[strcspn(books[*count].name, "\n")] = 0;
    printf("Nhap gia: ");
    scanf("%lf", &books[*count].price);
    getchar(); // Xoa bo dem
    (*count)++;
    printf("Them sach thanh cong!\n");
}

void editBook(Book books[], int count) {
    int id, found = 0;
    printf("Nhap ID sach can sua: ");
    scanf("%d", &id);
    getchar();
    int i;
    for ( i = 0; i < count; i++) {
        if (books[i].id == id) {
            found = 1;
            printf("Nhap ten sach moi: ");
            fgets(books[i].name, MAX_NAME_LENGTH, stdin);
            books[i].name[strcspn(books[i].name, "\n")] = 0;
            printf("Nhap gia moi: ");
            scanf("%lf", &books[i].price);
            getchar();
            printf("Sua thong tin sach thanh cong!\n");
            break;
        }
    }
    if (!found) printf("ID sach khong ton tai!\n");
}

void deleteBook(Book books[], int *count) {
    int id, found = 0;
    printf("Nhap ID sach can xoa: ");
    scanf("%d", &id);
    getchar();
    int i;
    for ( i = 0; i < *count; i++) {
        if (books[i].id == id) {
            found = 1;
            int j;
            for ( j = i; j < *count - 1; j++) {
                books[j] = books[j + 1];
            }
            (*count)--;
            printf("Xoa sach thanh cong!\n");
            break;
        }
    }
    if (!found) printf("ID sach khong ton tai!\n");
}

void searchBook(Book books[], int count) {
    char keyword[MAX_NAME_LENGTH];
    int found = 0;
    printf("Nhap ten sach can tim: ");
    getchar();
    fgets(keyword, MAX_NAME_LENGTH, stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    printf("\nKet qua tim kiem:\n");
    int i;
    for (i = 0; i < count; i++) {
        if (strstr(books[i].name, keyword)) {
            printf("ID: %d | Ten: %s | Gia: %.2f\n", books[i].id, books[i].name, books[i].price);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay sach nao!\n");
}

void sortBooks(Book books[], int count) {
    int choice;
    printf("Chon cach sap xep:\n");
    printf("1. Gia tang dan\n");
    printf("2. Gia giam dan\n");
    printf("Lua chon: ");
    scanf("%d", &choice);
    getchar();
    int i;

    for (i = 0; i < count - 1; i++) {
    	int j;
        for ( j = i + 1; j < count; j++) {
            if ((choice == 1 && books[i].price > books[j].price) || (choice == 2 && books[i].price < books[j].price)) {
                Book temp = books[i];
                books[i] = books[j];
                books[j] = temp;
            }
        }
    }
    printf("Sap xep sach thanh cong!\n");
    displayBooks(books, count);
}

void saveToFile(Book books[], int count) {
    FILE *file = fopen("books.txt", "w");
    if (!file) {
        printf("Khong the mo file de ghi!\n");
        return;
    }
    int i;
    for ( i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f\n", books[i].id, books[i].name, books[i].price);
    }
    fclose(file);
    printf("Luu du lieu thanh cong!\n");
}

void loadFromFile(Book books[], int *count) {
    FILE *file = fopen("books.txt", "r");
    if (!file) {
        printf("Khong the mo file de doc!\n");
        return;
    }
    *count = 0;
    while (fscanf(file, "%d,%99[^,],%lf", &books[*count].id, books[*count].name, &books[*count].price) == 3) {
        (*count)++;
    }
    fclose(file);
    printf("Tai du lieu thanh cong!\n");
}

