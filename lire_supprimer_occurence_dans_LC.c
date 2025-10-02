#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Création d’un nouveau nœud
Node* createNodee(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insertion en tête (pour remplir la liste rapidement)
void insertHead(Node **head, int data) {
    Node* newNode = createNodee(data);
    newNode->next = *head;
    *head = newNode;
}

// Suppression d’une occurrence
void deleteOccurrence(Node **head, int key) {
    if (*head == NULL) {
        printf("Liste vide, rien à supprimer.\n");
        return;
    }

    Node* temp = *head;
    Node* prev = NULL;

    // Cas 1 : la tête contient la valeur
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // nouvelle tête
        free(temp);         // libérer la mémoire
        printf("Occurrence %d supprimée (en tête).\n", key);
        return;
    }

    // Cas 2 : chercher la valeur ailleurs
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // Si non trouvé
    if (temp == NULL) {
        printf("Valeur %d non trouvée dans la liste.\n", key);
        return;
    }

    // Déconnecter le nœud trouvé
    prev->next = temp->next;
    free(temp);
    printf("Occurrence %d supprimée.\n", key);
}

// Affichage de la liste
void displayList(Node *head) {
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
int lire_supp_occurance() {
    Node* head = NULL;

    // Insertion de quelques valeurs
    insertHead(&head, 10);
    insertHead(&head, 20);
    insertHead(&head, 30);
    insertHead(&head, 40);

    printf("Liste initiale :\n");
    displayList(head);

    // Suppression d’une occurrence
    deleteOccurrence(&head, 30);
    displayList(head);

    deleteOccurrence(&head, 40);
    displayList(head);

    deleteOccurrence(&head, 99); // valeur absente
    displayList(head);

    return 0;
}
