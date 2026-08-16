#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
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

        printf("Enter data: ");
        scanf("%d", &x);

        newnode->data = x;
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
        }

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}


// DISPLAY
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}


// INSERT BEGIN
void insert_begin() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}


// INSERT END
void insert_end() {
    struct node *newnode, *temp = head;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newnode;
    }
}


// INSERT ANY POSITION
void insert_any() {
    struct node *newnode, *temp;
    int pos, i = 1;

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;

    while (i < pos - 1 && temp != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


// DELETE BEGIN
void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    temp = head;
    head = head->next;

    free(temp);
}


// DELETE END
void delete_end() {
    struct node *temp = head;
    struct node *prev = NULL;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}


// DELETE ANY POSITION
void delete_any() {
    struct node *temp, *prev = NULL;
    int pos, i = 1;

    if (head == NULL) {
        printf("List empty\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1) {
        printf("Invalid position\n");
        return;
    }

    temp = head;

    if (pos == 1) {
        head = head->next;
        free(temp);
        return;
    }

    while (i < pos && temp != NULL) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


// MAIN MENU
int main() {
    int choice;

    do {
        printf(" LINKED LIST MENU \n");
        printf("1. Create\n");
        printf("2. Display\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert at Any Position\n");
        printf("6. Delete at Beginning\n");
        printf("7. Delete at End\n");
        printf("8. Delete at Any Position\n");
        printf("9. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                create();
                break;

            case 2:
                display();
                break;

            case 3:
                insert_begin();
                break;

            case 4:
                insert_end();
                break;

            case 5:
                insert_any();
                break;

            case 6:
                delete_begin();
                break;

            case 7:
                delete_end();
                break;

            case 8:
                delete_any();
                break;

            case 9:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 9);

    return 0;
}