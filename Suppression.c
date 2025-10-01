#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un nœud
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d’un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d’allocation mémoire\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insertion en fin de liste
void append(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Affichage de la liste
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Suppression de toutes les occurrences d'une valeur
void deleteAllOccurrences(Node** head, int value) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == value) {
            Node* toDelete = temp;

            // Cas : suppression de la tête
            if (temp->prev == NULL) {
                *head = temp->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            } 
            // Cas : suppression au milieu ou fin
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            temp = temp->next;
            free(toDelete); // Libération mémoire
        } else {
            temp = temp->next;
        }
    }
}

// Programme principal
int main() {
    Node* head = NULL;
    int n, val, delVal;

    printf("Combien d'elements voulez-vous inserer ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Element %d : ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }

    printf("\nListe initiale :\n");
    display(head);

    printf("\nEntrez la valeur a supprimer (toutes occurrences) : ");
    scanf("%d", &delVal);

    deleteAllOccurrences(&head, delVal);

    printf("\nListe apres suppression de %d :\n", delVal);
    display(head);

    return 0;
}
