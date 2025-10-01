#include <stdio.h>
#include <stdlib.h>

// Définition d’un nœud de la liste doublement chaînée
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur : mémoire insuffisante.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Ajouter un élément à la fin de la liste
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

// Afficher le contenu de la liste
void display(Node* head) {
    if (head == NULL) {
        printf("La liste est vide.\n");
        return;
    }
    Node* temp = head;
    printf("Contenu de la liste :\n");
    while (temp != NULL) {
        printf(" %d ", temp->data);
        if (temp->next != NULL) printf("<->"); 
        temp = temp->next;
    }
    printf("\n");
}

// Supprimer toutes les occurrences d’une valeur donnée
void deleteAllOccurrences(Node** head, int value) {
    Node* temp = *head;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            found = 1;
            Node* toDelete = temp;

            // Cas : suppression du premier élément
            if (temp->prev == NULL) {
                *head = temp->next;
                if (*head != NULL)
                    (*head)->prev = NULL;
            } 
            // Cas : suppression ailleurs
            else {
                temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
            }

            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }

    if (!found) {
        printf("La valeur %d n'existe pas dans la liste.\n", value);
    } else {
        printf("Toutes les occurrences de %d ont été supprimées.\n", value);
    }
}

// Libérer toute la liste de la mémoire
void freeList(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

// Programme principal
int main() {
    Node* head = NULL;
    int n, val, delVal;

    printf("=== Gestion d’une liste doublement chaînée ===\n\n");

    printf("Combien d'éléments voulez-vous ajouter ? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Entrez l’élément %d : ", i + 1);
        scanf("%d", &val);
        append(&head, val);
    }

    printf("\n");
    display(head);

    printf("\nntrez la valeur à supprimer (toutes ses occurrences) : ");
    scanf("%d", &delVal);

    deleteAllOccurrences(&head, delVal);

    printf("\n");
    display(head);

    // Libération de la mémoire à la fin
    freeList(head);

    printf("\nFin du programme. La mémoire a été libérée.\n");

    return 0;
}
