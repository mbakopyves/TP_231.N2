#include <stdio.h>
#include <stdlib.h>
#include "lire_supprimer_occurence_dans_LC.h"
#include "insertion_element_pour_rester_trie_dans_LSC.h"
#include "insertion_element_tri_dans_LDC.h"
#include "simplement_chaîne_circulaire.h"
#include "insertion_tete_queue_LDC-circulaire.h"

int main(){
    int choix=0;
    printf("SALUT ET BIENVENUE A CETTE NOUVELLE EXPERIENCE. CET FOIS AVEC LA MANIPULATION DES LISTE CHAINEE\n\n");
    do{
    printf("1. lire et suprimer une occurence dans une liste chainee\n");
    printf("2. insertion d'un element pour quel reste trie dans une liste simplement chainee\n");
    printf("3. insertion d'un element pour qu'elle reste trie dans une liste doublement chainee\n");
    printf("4. manipulation d'une liste simplement chainee circulaire\n");
    printf("5. insertion en en-tete et en queue dans une liste doublement chainee circulaire\n");
    printf("6.QUITER\n");
    printf("choix:\t");
    scanf("%d",&choix);
    if(choix==6){
        printf("\n\n");
        printf("------  MERCI POUR VOTRE VISITE ET A LA PROCHAINE   ------\n");
        return 0;
    }
    switch (choix){
    case 1:
        int lire_supp_occurance();
        break;
    case 2:
        insertion_pour_rester_trie_dans_LSC();
        break;
    case 3:
        insertion_element_tri_dans_LDC();
        break;
    case 4:
        simplement_chaine_circulaire();
        break;
    case 5:
        insertion_T_Q_LDCc();
        break;
    default:
        printf("choix invalide, veillez faire un choix compris dans le cadre des manipulation");
        break;
    }
}while(choix<=6);
}