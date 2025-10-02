#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} Bool;

typedef struct ListElement
{
    int value;
    struct ListElement *next;
} ListElement, *List;


List new_list(void)
{
    return NULL;
}

Bool is_empty_list(List li)
{
	if(li == NULL)
		return true;
	return false;
}

void print_list(List li)
{
    if (is_empty_list(li))
    {
        printf("La liste est vide.\n");
        return;
    }
    printf("Contenu de la liste : ");
    while (li != NULL)
    {
        printf("%d -> ", li->value);
        li = li->next;
    }
    printf("FIN\n");
}

void free_list(List li)
{
    ListElement *tmp;
    while (li != NULL)
    {
        tmp = li;
        li = li->next;
        free(tmp);
    }
}

List insert_sorted(List li, int x)
{
    ListElement *element = malloc(sizeof(*element));
    if (element == NULL)
    {
        fprintf(stderr, "Erreur : probleme allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }

    element->value = x;
    element->next = NULL;

    if (li == NULL || x < li->value)
    {
        element->next = li;
        return element;
    }

    ListElement *current = li;
    while (current->next != NULL && current->next->value < x)
    {
        current = current->next;
    }

    element->next = current->next;
    current->next = element;

    return li;
}

int main()
{
    int x, choice;
    List mylist = new_list();

    printf("REMPLISSAGE DE LA LISTE SIMPLEMENT CHAINEE \n");

    while (1)
    {
        printf("\n");
        printf("Appuyer 1 pour entrer un element \n");
        printf("Appuyer 2 pour quitter l'insertion \n");
        printf("Appuyer 3 pour afficher les elements tries\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("Entrez un element a inserer : ");
            scanf("%d", &x);
            mylist = insert_sorted(mylist, x);
        }
        else if (choice == 2)
        {
            break;
        }
        else if (choice == 3)
        {
            print_list(mylist);
        }
        else
        {
            printf("Option invalide. Veuillez reessayer.\n");
        }
    }

    free_list(mylist);
    return 0;
}

