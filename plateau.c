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
                    if(i==0 && j==8) {
                        tab[i][j]=joueur1.pion;//case initiale du joueur 1
                    }else if(i==16 && j==8) {
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
void sauvegarderPartie(int plateau[17][17],int player_turn ,joueur joueurs[], int nbJoueurs, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour sauvegarde\n");
        return;
    }

    // Sauvegarder les joueurs
    fprintf(fichier,"%d\n",nbJoueurs);
    //sauvergarde du tour
    fprintf(fichier,"%d\n",player_turn);
    for(int i=0;i<nbJoueurs;i++) {
        fprintf(fichier,"%s %d %d %d %d\n", joueurs[i].nom, joueurs[i].pion, joueurs[i].score,joueurs[i].position.x,joueurs[i].position.y);
    }

    // Sauvegarder le plateau
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            fprintf(fichier, " %d", plateau[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
    printf("Partie sauvegardee dans '%s'.\n", nomFichier);
}
void chargerPartie(int plateau[17][17], int * player_turn,joueur joueurs[], int *nbJoueurs, const char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "r");
    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier pour chargement\n");
        return;
    }
    // Charger les informations des joueurs
    fscanf(fichier, "%d", nbJoueurs);
    //Charger le tour
    fscanf(fichier, "%d", player_turn);
    for (int i = 0; i < *nbJoueurs; i++) {
        fscanf(fichier, "%s %d %d %d %d", joueurs[i].nom, &joueurs[i].pion, &joueurs[i].score,&joueurs[i].position.x, &joueurs[i].position.y);
    }

    // Charger le plateau
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            fscanf(fichier, " %d", &plateau[i][j]);
        }
    }
    fclose(fichier);
    printf("Partie chargee depuis '%s'.\n", nomFichier);
}
