#include <stdio.h>
#include <stdlib.h>

struct dll {
    struct dll* l;
    int data;
    struct dll* r;
};

struct dll* start = NULL;
struct dll* end = NULL;

// Function prototypes
void IFDLL();   // Insert element at the front of the linked list
void IEDLL();   // Insert element at the end of the linked list
void DFDLL();   // Delete element from the front of the linked list
void DEDLL();   // Delete element from the end of the linked list
void display(); // Display the entire linked list

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
            IFDLL();
            break;
        case 2:
            IEDLL();
            break;
        case 3:
            DFDLL();
            break;
        case 4:
            DEDLL();
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

// Insert element at the front of the linked list
void IFDLL() {
    struct dll* p;
    int el;
    p = (struct dll*)malloc(sizeof(struct dll));
    printf("Enter the element: ");
    scanf("%d", &el);
    p->l = NULL;
    p->data = el;
    if (start == NULL) {
        p->r = NULL;
        start = p;
        end = p;
    } else {
        p->r = start;
        start->l = p;
        start = p;
    }
}

// Insert element at the end of the linked list
void IEDLL() {
    struct dll* p;
    int el;
    p = (struct dll*)malloc(sizeof(struct dll));

    printf("Enter the element: ");
    scanf("%d", &el);
    p->data = el;
    p->r = NULL;
    if (end == NULL) {
        p->l = NULL;
        p->data = el;
        end = p;
        start = p;
    } else {
        p->l = end;
        end->r = p;
        end = p;
    }
}

// Display the entire linked list
void display() {
    struct dll* p;
    if (start == NULL) {
        printf("Empty linked list\n");
        return;
    }
    p = start;
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->r;
    }
    printf("\n");
}

// Delete element from the front of the linked list
void DFDLL() {
    struct dll* p;
    if (start == NULL) {
        printf("Stack empty\n");
        return;
    }
    if (start == end) {
        p = start;
        p->l = NULL;
        start = NULL;
        end = NULL;
        free(p);
    } else {
        p = start;
        p = p->r;
        p->l = NULL;
        start = p;
    }
}

// Delete element from the end of the linked list
void DEDLL() {
    struct dll* p;
    if (start == NULL) {
        printf("Stack empty\n");
        return;
    }
    if (start == end) {
        p = end;
        p->r = NULL;
        end = NULL;
        start = NULL;
        free(p);
    } else {
        p = end;
        p = p->l;
        p->r = NULL;
        end = p;
    }
}
