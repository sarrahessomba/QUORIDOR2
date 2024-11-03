//
// Created by sarra on 29/10/2024.
//
#include <stdio.h>
#include "affichage.h"
//Proposition des fonctionnalités de chaque joueur
int menu () {
    int choixx;
    do {
        printf("1. Deplacer son pion\n");
        printf("2. Placer une barriere\n");
        printf("3. Passer son tour\n");
        printf("4. Annuler le coup\n");
        scanf("%d", &choixx);
    }while(choixx != 1 && choixx != 2 && choixx != 3 && choixx != 4);
    return choixx;
}
void deplacer (int i,int x, int y,int tableau[17][17],int N) {
    tableau[x][y] = i;
    if(N==4) {
        int av_x[4] = {0,8,16,8};
        int av_y[4] = {8,0,8,16};
        tableau[av_x[i-1]][av_y[i-1]] =0;
        av_x[i-1] =x;
        av_y[i-1]=y;
        esthetique();
        for(int j=0;j<17;j++) {
            esthetique2(j);
            for(int k=0;k<17;k++) {
                printf("%d ", tableau[j][k]);
            }
            printf("\n");
        }
    }else {
        int av_x[2] = {0,16};
        int av_y[2] = {8,8};
        tableau[av_x[i-1]][av_y[i-1]] =0;
        av_x[i-1] =x;
        av_y[i-1]=y;
        esthetique();
        for(int j=0;j<17;j++) {
            esthetique2(j);
            for(int k=0;k<17;k++) {
                printf("%d ", tableau[j][k]);
            }
            printf("\n");
        }
    }
}