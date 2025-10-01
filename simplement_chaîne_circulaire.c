#include <stdio.h>
#include <stdlib.h>

// Structure d’un noeud
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un noeud
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insertion en tête dans une liste circulaire
Node* insertAtHead(Node* tail, int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return tail;
}

// Insertion en queue (fin) dans une liste circulaire
Node* insertAtTail(Node* tail, int value) {
    Node* newNode = createNode(value);
    if (tail == NULL) {
        newNode->next = newNode;
        return newNode;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    return newNode;  // nouveau tail
}

// Affichage de la liste
void printList(Node* tail) {
    if (tail == NULL) {
        printf("Liste vide.\n");
        return;
    }
    Node* current = tail->next;
    printf("Liste circulaire : ");
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != tail->next);
    printf("\n");
}

// Programme principal
int simplement_chaine_circulaire() {
    Node* tail = NULL;
    int choix, valeur;

    do {
        printf("\nMenu :\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur a inserer en tete : ");
                scanf("%d", &valeur);
                tail = insertAtHead(tail, valeur);
                break;
            case 2:
                printf("Entrez la valeur a inserer en queue : ");
                scanf("%d", &valeur);
                tail = insertAtTail(tail, valeur);
                break;
            case 3:
                printList(tail);
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 0);

    return 0;
}