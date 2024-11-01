//
// Created by sarra on 26/10/2024.
//
#include <stdio.h>
#include "affichage.h"
void plateau(int N,int tableau[17][17]) {
    if(N==4) {
        esthetique();
        for(int i = 0; i < 17; i++) {
           esthetique2(i);
            for(int j = 0; j < 17; j++) {
                if(i%2==0 && j%2 == 0) {
                    if(i==0 && j==8) {
                        tableau[i][j] = 1;
                        printf("%d ", tableau[i][j]);
                    }else if(i==8 && j==0) {
                        tableau[i][j] = 2;
                        printf("%d ", tableau[i][j]);
                    }else if(i==16 && j==8) {
                        tableau[i][j] = 3;
                        printf("%d ", tableau[i][j]);
                    }else if(i==8 && j==16) {
                        tableau[i][j] = 4;
                        printf("%d ", tableau[i][j]);
                    }else {
                        tableau[i][j] = 0;
                        printf("%d ", tableau[i][j]);
                    }
                }else if (i%2 !=0 || j%2 !=0) {
                    //6=Pas de barriere
                    tableau[i][j] =6 ;
                    printf("%d ", tableau[i][j]);
                }
            }
            printf("\n");
        }
    } else {
        esthetique();
        for(int i = 0; i < 17; i++) {
            esthetique2(i);
            for(int j = 0; j < 17; j++) {
                if(i%2==0 && j%2 == 0) {
                    if(i==0 && j==8) {
                        tableau[i][j] = 1;
                        printf("%d ", tableau[i][j]);
                    }else if(i==16 && j==8) {
                        tableau[i][j] = 2;
                        printf("%d ", tableau[i][j]);
                    }else {
                        tableau[i][j] = 0;
                        printf("%d ", tableau[i][j]);
                    }
                }else {
                    tableau[i][j] = 6;
                    printf("%d ", tableau[i][j]);
                }
            }
            printf("\n");
        }
    }
}