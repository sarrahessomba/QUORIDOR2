//
// Created by sarra on 26/10/2024.
//
#include <stdio.h>
#include "affichage.h"
#include "fonction.joueur.h"
void init_tab(int tab[17][17],int N,joueur joueur1,joueur joueur2,  joueur joueur3,joueur joueur4) {
    if(N==2){
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 17; j++) {
                if(i%2==0 && j%2==0) {
                    if(i==joueur1.position.x && j==joueur1.position.y) {
                        tab[i][j]=joueur1.pion;//case initiale du joueur 1
                    }else if(i==joueur2.position.x && j==joueur2.position.y) {
                        tab[i][j]=joueur2.pion;//case initiale du joueur 2
                    }else {
                        tab[i][j]=0;// Autres cases vides
                    }
                }else {
                    tab[i][j]=6;//cases des demis barrieres vides
                }
            }
        }
    }else { //par défaut N=4
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 17; j++) {
                if(i%2==0 && j%2==0) {
                    if(i==0 && j==8) {
                        tab[i][j]=joueur1.pion;//case initiale du joueur 1
                    }else if(i==16 && j==8) {
                        tab[i][j]=joueur3.pion;//case initiale du joueur 3
                    }else if(i==8 && j==0) {
                        tab[i][j]=joueur2.pion; //case initiale du joueur 2
                    }else if(i==8 && j==16) {
                        tab[i][j]=joueur4.pion;//case initiale du joueur 4
                    } else {
                        tab[i][j]=0;// autres cases vides
                    }
                }else {
                    tab[i][j]=6;//cases des demis barrieres vides
                }
            }
        }
    }
}
void affichage_plateau(int tab[17][17]) {
    esthetique();
    for (int i = 0; i < 17; i++) {
        esthetique2(i);
        for (int j = 0; j < 17; j++) {
            printf("%d ",tab[i][j]);
        }
        printf("\n");
    }
}

/*
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
}*/