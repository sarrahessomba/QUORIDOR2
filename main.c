#include <stdio.h>
#include "plateau.h"
#include "fonction.joueur.h"
int main() {
    int choix,x,y,condition;
    int N; int choixmenu;
    int plateaujeu[17][17]={{0}};
    printf("1. JOUER\n");
    printf("2. SORTIE\n");
    scanf("%d",&choix);
    switch(choix) {
        case 1:
            printf("Entrer le nombre de joueurs (2 ou 4) joueurs\n");
            scanf("%d",&N);
            while(N!=2 && N!=4) {
                printf("Entrer 2 ou 4!\n");
                scanf("%d",&N);
            }
        //O= case vide 6=pas de moitié d un barriere i=pion du joueur i 7= presence de moitié d'une barriere
            plateau(N,plateaujeu);
            for (int i=1; i<=N;i++) {
                printf("Tour du joueur %d\n",i);
                choixmenu = menu();
                switch(choixmenu) {
                    case 1:
                        do {
                            printf("X=\n");
                            scanf("%d",&x);
                            printf("y=\n");
                            scanf("%d",&y);
                            if((x%2 == 0 && y%2 == 0)) {
                                deplacer(i,x,y,plateaujeu,N);
                                condition = 0;
                            }else {
                                printf("Coordonnees invalides\n");
                                condition=1;
                            }
                        }while(condition==1);
                    break;

                }
            }
        break;
        case 2:
            return 0;
        break;
        default:
            printf("Erreur\n");
    }
    return 0;
}
