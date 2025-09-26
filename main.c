#include <stdio.h>
#include <stdlib.h>
// appelle des different prototype

int main(){
    int choix=0;
    printf("SALUT ET BIENVENUE A CETTE NOUVELLE EXPERIENCE. CET FOIS AVEC LA MANIPULATION DES LISTE CHAINEE");
    // liste des different operation de manipulation
    printf("choix:\t");
    scanf("%d",&choix);
    switch (choix){
    case 1:
        //fonction 1
        break;
    case 2:
        //fonction 2
        break;
    case 3:
        //fonction 3
        break;
    case 4:
        //fonction 4
        break;
    case 5:
        //fonction 5
        break;
    default:
        printf("choix invalide, veillez faire un choix compris dans le cadre des manipulation");
        break;
    }
    return 0;
}