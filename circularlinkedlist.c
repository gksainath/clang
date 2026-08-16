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

        if (newnode == NULL) {
            printf("Memory allocation failed\n");
            return;
        }

        printf("Enter data: ");
        scanf("%d", &x);

        newnode->data = x;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            newnode->next = head;
        }
        else {
            temp = head;

            while (temp->next != head) {
                temp = temp->next;
            }

            temp->next = newnode;
            newnode->next = head;
        }

        printf("Continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');
}


// DISPLAY
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(HEAD)\n");
}


// INSERT AT BEGINNING
void insert_begin() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    }
    else {
        temp = head;

        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newnode;
        head = newnode;
    }
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

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
        return;
    }

    temp = head;

    while (temp->next != head) {
        temp = temp->next;
    }

    temp->next = newnode;
    newnode->next = head;
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

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    temp = head;

    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }

    if (i != pos - 1) {
        printf("Invalid position\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}


// DELETE AT BEGINNING
void delete_begin() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    last = head;

    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}


// DELETE AT END
void delete_end() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}


// DELETE AT ANY POSITION
void delete_any() {
    struct node *temp, *prev;
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

    while (i < pos && temp->next != head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != pos) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}


// MAIN
int main() {
    int choice;

    do {
        printf("\n========== CIRCULAR LINKED LIST ==========\n");
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