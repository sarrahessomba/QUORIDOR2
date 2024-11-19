#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sauvegarde.h"
void sauvegarder_partie(int tableau[17][17], int joueurs_x[4], int joueurs_y[4], int N, int joueur_actuel){

    FILE *fichier = fopen("sauvegarde_partie.txt", "w");
    if (fichier == NULL) {
        printf("Erreur : Impossible de sauvegarder la partie.\n");
        return;
    } 

    // Sauvegarde du nombre de joueurs
    fprintf(fichier, "%d\n", N);

    // Sauvegarde du tour actuel
    fprintf(fichier, "%d\n", joueur_actuel);

    // Sauvegarde des positions des joueurs
    for (int i = 0; i < N; i++) {
        fprintf(fichier, "%d %d\n", joueurs_x[i], joueurs_y[i]);
    }

    // Sauvegarde du plateau
    for (int i = 0; i < 17; i++) {
        for (int j = 0; j < 17; j++) {
            fprintf(fichier, "%d ", tableau[i][j]);
        }
        fprintf(fichier, "\n");
    }

    fclose(fichier);
    printf("Partie sauvegarde!\n");
}
