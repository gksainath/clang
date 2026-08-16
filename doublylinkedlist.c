#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


// CREATE
void create() {
    struct node *newnode, *temp;
    int x;
    char ch;

    do {
        newnode = (struct node *)malloc(sizeof(struct node));

        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &x);

        newnode->data = x;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
        }
        else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->prev = temp;
        }

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}


// DISPLAY FORWARD
void display_forward() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nForward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


// DISPLAY BACKWARD
void display_backward() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("\nBackward: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }

    printf("NULL\n");
}


// INSERT AT BEGINNING
void insert_begin() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL) {
        head->prev = newnode;
    }

    head = newnode;
}


// INSERT AT END
void insert_end() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->prev = temp;
}


// INSERT AT ANY POSITION
void insert_any() {
    struct node *newnode, *temp;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        insert_begin();
        return;
    }

    if (head == NULL) {
        printf("Invalid position\n");
        return;
    }

    temp = head;

    while (i < pos - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
}


// DELETE AT BEGINNING
void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    }

    free(temp);
}


// DELETE AT END
void delete_end() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (temp->next == NULL) {
        free(temp);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;

    free(temp);
}


// DELETE AT ANY POSITION
void delete_any() {
    struct node *temp;
    int pos, i = 1;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    if (pos == 1) {
        delete_begin();
        return;
    }

    temp = head;

    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    temp->prev->next = temp->next;

    free(temp);
}


// MAIN
int main() {
    int choice;

    do {
        printf("\n========== DOUBLY LINKED LIST ==========\n");
        printf("1. Create\n");
        printf("2. Display Forward\n");
        printf("3. Display Backward\n");
        printf("4. Insert at Beginning\n");
        printf("5. Insert at End\n");
        printf("6. Insert at Any Position\n");
        printf("7. Delete at Beginning\n");
        printf("8. Delete at End\n");
        printf("9. Delete at Any Position\n");
        printf("10. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                create();
                break;

            case 2:
                display_forward();
                break;

            case 3:
                display_backward();
                break;

            case 4:
                insert_begin();
                break;

            case 5:
                insert_end();
                break;

            case 6:
                insert_any();
                break;

            case 7:
                delete_begin();
                break;

            case 8:
                delete_end();
                break;

            case 9:
                delete_any();
                break;

            case 10:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 10);

    return 0;
}