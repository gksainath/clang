#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define FILE_NAME "library.dat"

typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
    int available;
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook();
void displayBooks();
void searchBook();
void issueBook();
void returnBook();
void deleteBook();
void saveBooks();
void loadBooks();

int findBookById(int id);

int main() {
    int choice;

    loadBooks();

    while (1) {
         printf("____________________________________\n");
        printf("       LIBRARY MANAGEMENT SYSTEM\n");
        printf("1. Add Book\n");
        printf("2. Display All Books\n");
        printf("3. Search Book\n");
        printf("4. Issue Book\n");
        printf("5. Return Book\n");
        printf("6. Delete Book\n");
        printf("7. Exit\n");
        printf("____________________________________\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;

            case 2:
                displayBooks();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                issueBook();
                break;

            case 5:
                returnBook();
                break;

            case 6:
                deleteBook();
                break;

            case 7:
                saveBooks();
                printf("\nLibrary data saved successfully.\n");
                printf("Thank you!\n");
                return 0;

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}


/* Find book using ID */
int findBookById(int id) {

    for (int i = 0; i < bookCount; i++) {

        if (books[i].id == id) {
            return i;
        }
    }

    return -1;
}


/* Add a new book */
void addBook() {

    if (bookCount >= MAX_BOOKS) {
        printf("\nLibrary is full!\n");
        return;
    }

    Book newBook;

    printf("\nEnter Book ID: ");
    scanf("%d", &newBook.id);

    if (findBookById(newBook.id) != -1) {
        printf("\nBook ID already exists!\n");
        return;
    }

    getchar();

    printf("Enter Book Title: ");
    fgets(newBook.title, sizeof(newBook.title), stdin);
    newBook.title[strcspn(newBook.title, "\n")] = '\0';

    printf("Enter Author Name: ");
    fgets(newBook.author, sizeof(newBook.author), stdin);
    newBook.author[strcspn(newBook.author, "\n")] = '\0';

    printf("Enter Publication Year: ");
    scanf("%d", &newBook.year);

    newBook.available = 1;

    books[bookCount] = newBook;
    bookCount++;

    saveBooks();

    printf("\nBook added successfully!\n");
}

void displayBooks() {

    if (bookCount == 0) {
        printf("\nNo books available.\n");
        return;
    }

    printf("\n================ ALL BOOKS ================\n");

    for (int i = 0; i < bookCount; i++) {

        printf("\nBook ID     : %d", books[i].id);
        printf("\nTitle       : %s", books[i].title);
        printf("\nAuthor      : %s", books[i].author);
        printf("\nYear        : %d", books[i].year);

        if (books[i].available)
            printf("\nStatus      : Available\n");
        else
            printf("\nStatus      : Issued\n");

        printf("-------------------------------------------\n");
    }
}



void searchBook() {

    int id;

    printf("\nEnter Book ID to search: ");
    scanf("%d", &id);

    int index = findBookById(id);

    if (index == -1) {
        printf("\nBook not found!\n");
        return;
    }

    printf("\nBook Found!\n");
    printf("--------------------------------\n");
    printf("ID     : %d\n", books[index].id);
    printf("Title  : %s\n", books[index].title);
    printf("Author : %s\n", books[index].author);
    printf("Year   : %d\n", books[index].year);

    if (books[index].available)
        printf("Status : Available\n");
    else
        printf("Status : Issued\n");
}

void issueBook() {

    int id;

    printf("\nEnter Book ID to issue: ");
    scanf("%d", &id);

    int index = findBookById(id);

    if (index == -1) {
        printf("\nBook not found!\n");
        return;
    }

    if (!books[index].available) {
        printf("\nBook is already issued!\n");
        return;
    }

    books[index].available = 0;

    saveBooks();

    printf("\nBook issued successfully!\n");
}


/* Return a book */
void returnBook() {

    int id;

    printf("\nEnter Book ID to return: ");
    scanf("%d", &id);

    int index = findBookById(id);

    if (index == -1) {
        printf("\nBook not found!\n");
        return;
    }

    if (books[index].available) {
        printf("\nThis book has not been issued.\n");
        return;
    }

    books[index].available = 1;

    saveBooks();

    printf("\nBook returned successfully!\n");
}

void deleteBook() {

    int id;

    printf("\nEnter Book ID to delete: ");
    scanf("%d", &id);

    int index = findBookById(id);

    if (index == -1) {
        printf("\nBook not found!\n");
        return;
    }

    for (int i = index; i < bookCount - 1; i++) {
        books[i] = books[i + 1];
    }

    bookCount--;

    saveBooks();

    printf("\nBook deleted successfully!\n");
}

void saveBooks() {

    FILE *file = fopen(FILE_NAME, "wb");

    if (file == NULL) {
        printf("\nError opening file!\n");
        return;
    }

    fwrite(&bookCount, sizeof(int), 1, file);
    fwrite(books, sizeof(Book), bookCount, file);

    fclose(file);
}



void loadBooks() {

    FILE *file = fopen(FILE_NAME, "rb");

    if (file == NULL) {
        return;
    }

    fread(&bookCount, sizeof(int), 1, file);
    fread(books, sizeof(Book), bookCount, file);

    fclose(file);
}