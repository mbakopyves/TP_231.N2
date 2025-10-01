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
    printf("NULL\n");
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
    int a;
    List mylist=new_list();
    printf("Entrer le nombre a inserer \n");
    scanf("%d",&a);
    mylist=insert_sorted(mylist,a);
    mylist=insert_sorted(mylist,5);
    mylist=insert_sorted(mylist,51);
    mylist=insert_sorted(mylist,2);
    mylist=insert_sorted(mylist,15);
    mylist=insert_sorted(mylist,21);
    mylist=insert_sorted(mylist,12);
    print_list(mylist);
    free_list(mylist);
    return 0;
}
