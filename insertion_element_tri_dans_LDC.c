#include <stdio.h>
#include <stdlib.h>

// Définition de la structure
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Création d'un nouveau nœud
Node* createNod(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Erreur d'allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insertion triée
void insertSorted(Node** head, int data) {
    Node* newNode = createNod(data);
    Node* current = *head;

    if (*head == NULL) { // Liste vide
        *head = newNode;
        return;
    }

    if (data < (*head)->data) { // Insertion en tête
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Insertion au milieu ou fin
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Suppression d'un élément
void deleteElement(Node** head, int data) {
    Node* current = *head;
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    if (current == NULL) {
        printf("❌ Élément %d non trouvé.\n", data);
        return;
    }

    if (current->prev != NULL) {
        current->prev->next = current->next;
    } else {
        *head = current->next;
    }

    if (current->next != NULL) {
        current->next->prev = current->prev;
    }

    free(current);
    printf("✅ Élément %d supprimé.\n", data);
}

// Recherche d’un élément
void searchElement(Node* head, int data) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == data) {
            printf("🔎 Élément %d trouvé dans la liste.\n", data);
            return;
        }
        current = current->next;
    }
    printf("❌ Élément %d non trouvé.\n", data);
}

// Affichage avant
void displayForward(Node* head) {
    Node* current = head;
    printf("➡️ Liste (tête → queue): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Affichage arrière
void displayBackward(Node* head) {
    if (head == NULL) {
        printf("Liste vide.\n");
        return;
    }

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    printf("⬅️ Liste (queue → tête): ");
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

// Compter les éléments
int countElements(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Vider toute la liste
void clearList(Node** head) {
    Node* current = *head;
    Node* temp;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    printf("♻️ Liste vidée avec succès.\n");
}

// Programme principal
int insertion_element_tri_dans_LDC() {
    Node* head = NULL;
    int choix, valeur;

    do {
        printf("\n===== MENU LISTE DOUBLE CHAÎNÉE TRIÉE =====\n");
        printf("1. Insérer un élément\n");
        printf("2. Supprimer un élément\n");
        printf("3. Rechercher un élément\n");
        printf("4. Afficher liste (tête → queue)\n");
        printf("5. Afficher liste (queue → tête)\n");
        printf("6. Compter le nombre d'éléments\n");
        printf("7. Vider la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez la valeur à insérer : ");
                scanf("%d", &valeur);
                insertSorted(&head, valeur);
                break;
            case 2:
                printf("Entrez la valeur à supprimer : ");
                scanf("%d", &valeur);
                deleteElement(&head, valeur);
                break;
            case 3:
                printf("Entrez la valeur à rechercher : ");
                scanf("%d", &valeur);
                searchElement(head, valeur);
                break;
            case 4:
                displayForward(head);
                break;
            case 5:
                displayBackward(head);
                break;
            case 6:
                printf("📊 La liste contient %d élément(s).\n", countElements(head));
                break;
            case 7:
                clearList(&head);
                break;
            case 0:
                printf("👋 Fin du programme.\n");
                break;
            default:
                printf("⚠️ Choix invalide.\n");
        }
    } while (choix != 0);

    clearList(&head); // Nettoyage avant de quitter
    return 0;
}