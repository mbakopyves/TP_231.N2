#include <stdio.h>
#include <stdlib.h>

// Structure pour la liste simplement chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Fonction pour créer un nouveau nœud
Node* creerNoeud(int data) {
    Node* nouveau = (Node*)malloc(sizeof(Node));
    if (nouveau == NULL) {
        printf("Erreur d'allocation mémoire\n");
        exit(1);
    }
    nouveau->data = data;
    nouveau->next = NULL;
    return nouveau;
}

// Fonction pour ajouter un élément en tête
Node* ajouterTete(Node* head, int data) {
    Node* nouveau = creerNoeud(data);
    nouveau->next = head;
    return nouveau;
}

// Fonction pour supprimer toutes les occurrences d'une valeur
Node* supprimerOccurrences(Node* head, int value) {
    Node* current = head;
    Node* prev = NULL;
    Node* toDelete = NULL;
    
    // Supprimer toutes les occurrences en tête
    while (current != NULL && current->data == value) {
        toDelete = current;
        current = current->next;
        free(toDelete);
    }
    head = current;
    
    // Supprimer les occurrences dans le reste de la liste
    if (current != NULL) {
        prev = current;
        current = current->next;
        
        while (current != NULL) {
            if (current->data == value) {
                toDelete = current;
                prev->next = current->next;
                current = current->next;
                free(toDelete);
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
    
    return head;
}

// Fonction pour afficher la liste
void afficherListe(Node* head) {
    Node* current = head;
    printf("Liste : ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Fonction pour libérer la mémoire
void libererListe(Node* head) {
    Node* current = head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

// Programme principal
int main() {
    printf("Suppression de toutes les occurrences \n");
    
    // Création de la liste de test
    Node* head = NULL;
    head = ajouterTete(head, 2);
    head = ajouterTete(head, 4);
    head = ajouterTete(head, 2);
    head = ajouterTete(head, 5);
    head = ajouterTete(head, 2);
    head = ajouterTete(head, 3);
    head = ajouterTete(head, 2);
    
    printf("Liste originale :\n");
    afficherListe(head);
    
    // Supprimer toutes les occurrences de 2
    int valeurASupprimer = 2;
    head = supprimerOccurrences(head, valeurASupprimer);
    
    printf("Après suppression de toutes les occurrences de %d :\n", valeurASupprimer);
    afficherListe(head);
    
    // Libérer la mémoire
    libererListe(head);
    
    return 0;
}
