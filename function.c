//noi khai trien ham
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

struct Book book[MAX_BOOK];
int bookCount = 0;

// ham menu chinh
void mainMenu(){
	int choice;
	while(1){
    printf("***Library Management System Using C***\n");
    printf("\n\t\tMENU\n");
    printf("\t======================\n");
    printf("\t[1] Add Book\n");
    printf("\t[2] Display Book List\n");
    printf("\t[3] Exit\n");
    printf("\tEnter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
			case 3:
				exit(0);      
            default:
                printf("Invalid choice! Please try again.\n");
        }
	}
}
    

//ham them sach
void addBook() {
	printf("\nEnter new book details:\n");
    printf("Book ID: "); 
	scanf("%s", book[bookCount].bookId);
    printf("Title: "); 
	scanf("%s", book[bookCount].title);
    printf("Author: "); 
	scanf("%s", book[bookCount].author);
    printf("Quantity: "); 
	scanf("%d", &book[bookCount].quantity);
    printf("Price: "); 
	scanf("%d", &book[bookCount].price);
    printf("Publication Date (dd/mm/yyyy): ");
    scanf("%d %d %d", &book[bookCount].publication.day, &book[bookCount].publication.month, &book[bookCount].publication.year);
    bookCount++;
    printf("Book added successfully!\n\n");
}

//ham danh sach sach
void displayBooks() {
	if (bookCount == 0) {
        printf("No books available in the library.\n\n");
        return;
    }
	printf("\n\t\t**** All Book ****\n");
	printf("\n|==========|==============================|====================|==========|==========|==========|\n");
    printf("|%-10s|%-30s|%-20s|%-10s|%-10s|%-10s|", "Book ID", "Title", "Author", "Quantity", "Price", "Pub Date");
    printf("\n|==========|==============================|====================|==========|==========|==========|\n");
    int i;
    for(i = 0; i < bookCount; i++) {
    	printf("|%-10s|%-30s|%-20s|%-10d|%-10d|%02d/%02d/%04d|\n",
               book[i].bookId, book[i].title, book[i].author,
               book[i].quantity, book[i].price,
               book[i].publication.day, book[i].publication.month, book[i].publication.year);
        printf("|----------|------------------------------|--------------------|----------|----------|----------|\n\n");
	}
}
//ham sua danh sach
typedef struct {
    int id;
    char title[50];
    char author[50];
    int year;
} Book;

// ham hien thi thong tin sach 
void displayBook(Book book) {
    printf("ID: %d\n", book.id); 
    printf("Title: %s\n", book.title);
    printf("Author: %s\n", book.author);
    printf("Year: %d\n", book.year);
}

//Ham tim chi so sach trong danh sach theo ID
int findBookIndex(Book books[], int totalBooks, int id) {
    for (int i = 0; i < totalBooks; i++) {
        if (books[i].id == id) {
            return i;
        }
    }
    return -1; // khong tim thay sach
}

int main() {
    Book books[MAX_BOOKS];
    int totalBooks = 0;
    int id;

    // Thêm mot so sach mau vao danh sach
    books[totalBooks++] = (Book){1, "Book One", "Author One", 2001};
    books[totalBooks++] = (Book){2, "Book Two", "Author Two", 2002};
    books[totalBooks++] = (Book){3, "Book Three", "Author Three", 2003};

    // Yeu cau nguoi dung nhap ID cua cuon sach muon sua
    printf("Enter the ID of the book you want to edit: ");
    scanf("%d", &id);

    // Kiem tra xem ID sach co ton tai hay không
    int bookIndex = findBookIndex(books, totalBooks, id);

    // Hien thi thong tin hien tai cua sach
    if (bookIndex == -1) {
        printf("Book with ID %d not found.\n", id);
    } else {
        // {
        // Hien thi thong tin hien tai cua sach
        printf("Current information of the book:\n");
        displayBook(books[bookIndex]);

        // Yeu cau nguoi dung nhap thong tin moi
        printf("\nEnter new information for the book:\n");
        printf("New Title: ");
        scanf("%s", books[bookIndex].title);
        printf("New Author: ");
        scanf("%s", books[bookIndex].author);
        printf("New Year: ");
        scanf("%d", &books[bookIndex].year);

        // 
        // hien thi thong bao thanh cong
        printf("\nBook information updated successfully.\n");
        displayBook(books[bookIndex]);
    }
}

// khai báo các hàm 
void option1();
void option2();
void option3();
void mainMenu();

int main() {
    mainMenu();
    return 0;
}

// hàm de hien thi menu chinh
void mainMenu() {
    int choice;
    do {
        printf("\n-- Main Menu --\n");
        printf("1. Option 1\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                option1();
                break;
            case 2:
                option2();
                break;
            case 3:
                option3();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
}

// cac ham cho tung lua chon
void option1() {
    printf("You selected Option 1\n");
    // thêm ma cua ban cho tung lua chon 1 tai day
    mainMenu();
}

void option2() {
    printf("You selected Option 2\n");
    // thêm ma cua ban cho tung lua chon 2 tai day
    mainMenu();
}

void option3() {
    printf("You selected Option 3\n");
    // thêm ma cua ban cho tung lua chon 3 tai day
    mainMenu();
}


