#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud de la liste doublement chaînée
typedef struct Node {
    int data;           // La valeur du nœud
    struct Node* prev;  // Pointeur vers le nœud précédent
    struct Node* next;  // Pointeur vers le nœud suivant
} Node;

// Crée un nouveau nœud avec une valeur donnée
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Allocation de mémoire pour le nœud
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Ajoute un nœud à la fin de la liste
void addNodeToEnd(Node** head, int value) {
    Node* newNode = createNode(value);  // Crée un nouveau nœud avec la valeur donnée
    if (*head == NULL) {
        *head = newNode;  // Si la liste est vide, ce nœud devient le premier
    } else {
        Node* current = *head;
        // On parcourt la liste jusqu'à la fin
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;  // Le dernier nœud pointe vers le nouveau nœud
        newNode->prev = current;  // Le nouveau nœud pointe vers l'ancien dernier nœud
    }
}

// Affiche les éléments de la liste
void displayList(Node* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Supprime toutes les occurrences d'une valeur dans la liste
void removeOccurrences(Node** head, int value) {
    Node* current = *head;

    while (current != NULL) {
        if (current->data == value) {
            // Si le nœud à supprimer est le premier
            if (current->prev == NULL) {
                *head = current->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;  // Si la liste n'est pas vide après la suppression, on ajuste le précédent du premier nœud
                }
            } else {
                // Si ce nœud est au milieu ou à la fin
                current->prev->next = current->next;
                if (current->next != NULL) {
                    current->next->prev = current->prev;
                }
            }
            Node* temp = current;  // On garde une référence au nœud à supprimer pour libérer la mémoire après
            current = current->next;  // On passe au suivant
            free(temp);  // Libération de la mémoire du nœud supprimé
        } else {
            current = current->next;  // Si ce nœud n'a pas la valeur à supprimer, on passe au suivant
        }
    }
}

// Fonction principale
int main() {
    Node* head = NULL;  // Initialisation de la liste vide

    // Ajout d'éléments à la liste
    addNodeToEnd(&head, 1);
    addNodeToEnd(&head, 2);
    addNodeToEnd(&head, 3);
    addNodeToEnd(&head, 2);
    addNodeToEnd(&head, 4);

    printf("Liste avant suppression :\n");
    displayList(head);

    // Suppression de toutes les occurrences de '2'
    removeOccurrences(&head, 2);

    printf("\nListe après suppression des occurrences de 2 :\n");
    displayList(head);

    return 0;
}
