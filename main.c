#include <stdio.h>
#include "plateau.h"
int main() {
    int choix;
    int N;
    printf("1. JOUER\n");
    printf("2. SORTIE\n");
    scanf("%d",&choix);
    switch(choix) {
        case 1:
            printf("Entrer le nombre de joueurs (2 ou 4) jouers\n");
            scanf("%d",&N);
            while(N!=2 && N!=4) {
                printf("Entrer 2 ou 4!\n");
                scanf("%d",&N);
            }
        //O= case vide 6=pas de moitié d un barriere i=pion su joueur i 7= presence de moitié d'une barriere
            plateau(N);

        break;
        case 2:
            return 0;
        break;
        default:
            printf("Erreur\n");
    }
    return 0;
}
