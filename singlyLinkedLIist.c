#include <stdio.h>
#include <stdlib.h>

struct sll {
    int D;
    struct sll* l;
};

struct sll* start = NULL;
struct sll* end = NULL;

// Function prototypes
void insertFront(); // Insert element at the front of the linked list
void insertEnd();   // Insert element at the end of the linked list
void delFront();    // Delete element from the front of the linked list
void delEnd();      // Delete element from the end of the linked list
void display();     // Display the entire linked list

int main() {
    int a;
    do {
        printf("Press 1 for insertAtFront\n");
        printf("Press 2 for insertAtEnd\n");
        printf("Press 3 for deleteAtFront\n");
        printf("Press 4 for deleteAtEnd\n");
        printf("Press 5 for display\n");
        printf("Press 0 to exit\n");
        scanf("%d", &a);

        switch (a) {
        case 1:
            insertFront();
            break;
        case 2:
            insertEnd();
            break;
        case 3:
            delFront();
            break;
        case 4:
            delEnd();
            break;
        case 5:
            display();
            break;
        default:
            break;
        }
    } while (a != 0);
    return 0;
}

void insertFront() {
    struct sll* p;
    int el;
    p = (struct sll*)malloc(sizeof(struct sll));
    printf("Enter the element: ");
    scanf("%d", &el);
    p->D = el;
    p->l = start;
    start = p;
}

void insertEnd() {
    struct sll* p;
    int el;
    p = (struct sll*)malloc(sizeof(struct sll));
    printf("Enter the element: ");
    scanf("%d", &el);
    p->D = el;
    p->l = NULL;
    if (start == NULL) {
        // If the list is empty, set both start and end to the new node
        start = p;
        end = p;
    } else {
        // Otherwise, add the new node to the end and update the end pointer
        end->l = p;
        end = p;
    }
}

void display() {
    struct sll* p;
    if (start == NULL) {
        printf("Empty linked list\n");
        return;
    }
    p = start;
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d ", p->D);
        p = p->l;
    }
    printf("\n");
    printf("start=%p\n", (void*)start);
    printf("end=%p\n", (void*)end);
}

void delFront() {
    struct sll* p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    p = start;
    start = p->l;
    free(p);
}

void delEnd() {
    struct sll* p;
    if (start == NULL) {
        printf("List is empty\n");
        return;
    }
    if (start->l == NULL) {
        // If there is only one element, delete it and set both start and end to NULL
        printf("The element deleted is %d\n", start->D);
        free(start);
        start = NULL;
        end = NULL;
        return;
    }
    p = start;
    while (p->l->l != NULL) {
        // Traverse to the second last element
        p = p->l;
    }
    printf("The element deleted is %d\n", p->l->D);
    free(p->l);
    p->l = NULL;
    end = p;
}
