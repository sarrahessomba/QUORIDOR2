#include <stdio.h>

int main(void) {
    int choix;int N;char pseudo[20]={0};
    printf("1. JOUER\n");
    printf("2. SORTIE\n");
    scanf("%d",&choix);
    switch(choix) {
        case 1:
            printf("Entrer le nombre de joueurs\n (2 ou 4)\n");
        scanf("%d",&N);
        if(N!=2 && N!=4) {
            do {
                printf("2 ou 4 joueurs!\n");
                scanf("%d",&N);
            }while(N!=2 && N!=4);
        }
            for(int i=0;i<N;i++) {
                printf("Pseudo du joueur %d \n (Entrer un seul caractere)\n",i+1);
                scanf(" %c",&pseudo[i]);
            }
        break;
    }
    return 0;
}
