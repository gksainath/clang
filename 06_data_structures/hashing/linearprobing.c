#include <stdio.h>

#define SIZE 10

int hashTable[SIZE];

void initialize() {
    int i;

    for (i = 0; i < SIZE; i++)
        hashTable[i] = -1;
}

void insert() {
    int value, index, i;

    printf("Enter value: ");
    scanf("%d", &value);

    index = value % SIZE;

    for (i = 0; i < SIZE; i++) {
        int position = (index + i) % SIZE;

        if (hashTable[position] == -1) {
            hashTable[position] = value;
            printf("Value inserted at index %d\n", position);
            return;
        }
    }

    printf("Hash table is full\n");
}

void search() {
    int value, index, i;

    printf("Enter value to search: ");
    scanf("%d", &value);

    index = value % SIZE;

    for (i = 0; i < SIZE; i++) {
        int position = (index + i) % SIZE;

        if (hashTable[position] == value) {
            printf("Value found at index %d\n", position);
            return;
        }

        if (hashTable[position] == -1)
            break;
    }

    printf("Value not found\n");
}

void display() {
    int i;

    printf("Hash Table:\n");

    for (i = 0; i < SIZE; i++) {
        printf("%d: %d\n", i, hashTable[i]);
    }
}

int main() {
    int choice;

    initialize();

    do {
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insert();
                break;

            case 2:
                search();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 4);

    return 0;
}