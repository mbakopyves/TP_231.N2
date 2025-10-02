#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud
typedef struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Création d'un nœud
Node* createNods(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insertion en tête
void insertHeade(Node **head, int data) {
    Node* newNode = createNods(data);
    if (*head == NULL) {
        // La liste est vide : le nœud pointe vers lui-même
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev; // dernier nœud

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;

    *head = newNode; // nouvelle tête
}

// Insertion en queue
void insertTail(Node **head, int data) {
    Node* newNode = createNods(data);
    if (*head == NULL) {
        newNode->next = newNode->prev = newNode;
        *head = newNode;
        return;
    }
    Node* last = (*head)->prev;

    newNode->next = *head;
    newNode->prev = last;

    last->next = newNode;
    (*head)->prev = newNode;
    // tête ne change pas
}

// Affichage de la liste
void displayListee(Node *head) {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* temp = head;
    printf("Liste : ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Programme principal
int insertion_T_Q_LDCc() {
    Node* head = NULL;

    insertHeade(&head, 10);
    insertHeade(&head, 20);
    insertTail(&head, 5);
    insertTail(&head, 1);

    displayListee(head);

    return 0;
}
