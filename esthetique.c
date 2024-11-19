#include <stdio.h>
#include "esthetique.h"

// Appel de la fonction permettant de rendre plus esthetique le plateau
void plateau(int N, char tableau[17][17]) {
    esthetique();

    for (int i = 0; i < 17; i++) {
        esthetique2(i);
      //esthétique de chaque pion
        for (int j = 0; j < 17; j++) {
            if (i % 2 == 0 && j % 2 == 0) {
                if (i == 0 && j == 8) {
                    tableau[i][j] = PION_J1;
                    printf(" %c ", tableau[i][j]);
                } else if (i == 8 && j == 0) {
                    tableau[i][j] = PION_J2;
                    printf(" %c ", tableau[i][j]);
                } else if (i == 16 && j == 8 && N == 4) {
                    tableau[i][j] = PION_J3;
                    printf(" %c ", tableau[i][j]);
                } else if (i == 8 && j == 16 && N == 4) {
                    tableau[i][j] = PION_J4;
                    printf(" %c ", tableau[i][j]);
                } else {
                    tableau[i][j] = CASE_VIDE;
                    printf(" %c ", tableau[i][j]);
                }
                //esthétique des barrières
            } else if (i % 2 != 0 && j % 2 == 0) {
                tableau[i][j] = BARRIERE_H;
                printf(" %c ", tableau[i][j]);
            } else if (i % 2 == 0 && j % 2 != 0) {
                tableau[i][j] = BARRIERE;
                printf(" %c ", tableau[i][j]);
            } else {
                tableau[i][j] = ' ';
                printf(" %c ", tableau[i][j]);
            }
        }
        printf("\n");
    }
    esthetique(); // Bordure inférieure du plateau
}
