#include <stdio.h>
#include <stdlib.h>

// Structure pour un nœud de la liste chaînée
struct Node {
    int data;
    struct Node* next;
};

// Fonction pour ajouter un nouvel élément à la fin de la liste
void append(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
}

// Fonction pour supprimer toutes les occurrences d'un élément donné dans la liste
void deleteAllOccurrences(struct Node** head_ref, int key) {
    struct Node* temp = *head_ref;
    struct Node* prev = NULL;

    // Si la clé se trouve en tête de liste
    while (temp != NULL && temp->data == key) {
        *head_ref = temp->next; // Changer la tête
        free(temp);             // Libérer l'ancienne tête
        temp = *head_ref;       // Mettre à jour temp
    }

    // Supprimer les autres occurrences
    while (temp != NULL) {
        // Chercher l'élément à supprimer
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Si l'élément n'est pas présent dans la liste
        if (temp == NULL) {
            return;
        }

        // Déraciner le nœud
        prev->next = temp->next;

        free(temp); // Libérer la mémoire

        // Mettre à jour temp pour la prochaine itération
        temp = prev->next;
    }
}

// Fonction pour afficher la liste chaînée
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Fonction principale
int main() {
    struct Node* head = NULL;
    int element_to_delete;

    // Création d'une liste chaînée d'exemple
    append(&head, 2);
    append(&head, 4);
    append(&head, 2);
    append(&head, 5);
    append(&head, 6);
    append(&head, 2);
    append(&head, 7);
    append(&head, 2);

    printf("Liste chaînée initiale : \n");
    printList(head);

    // Lecture de l'élément à supprimer depuis l'entrée utilisateur
    printf("Entrez l'élément à supprimer de la liste : ");
    scanf("%d", &element_to_delete);

    // Suppression de toutes les occurrences de l'élément
    deleteAllOccurrences(&head, element_to_delete);

    printf("Liste chaînée après suppression de toutes les occurrences de %d : \n", element_to_delete);
    printList(head);

    return 0;
}