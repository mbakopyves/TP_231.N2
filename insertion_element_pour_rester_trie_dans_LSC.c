#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d’un nouveau nœud
Node* createNo(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée dans une liste simplement chaînée
void insertSorteds(Node **head, int data) {
    Node* newNode = createNo(data);

    // Cas 1 : liste vide OU nouvelle valeur plus petite que la tête
    if (*head == NULL || data < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Cas 2 : trouver la bonne position
    Node* current = *head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    // Insérer après current
    newNode->next = current->next;
    current->next = newNode;
}

// Affichage de la liste
void displayListe(Node *head) {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* temp = head;
    printf("Liste : ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Programme principal
int insertion_pour_rester_trie_dans_LSC() {
    Node* head = NULL;

    insertSorteds(&head, 30);
    insertSorteds(&head, 10);
    insertSorteds(&head, 20);
    insertSorteds(&head, 25);
    insertSorteds(&head, 5);

    displayListe(head);

    return 0;
}
