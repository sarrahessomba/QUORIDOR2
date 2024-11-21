#include <stdio.h>
#include "esthetique.h"

// Appel de la fonction permettant de rendre plus esthetique le plateau
// Structure pour un joueur
typedef struct {
    int id;        // ID du joueur
    char pion;     // Jeton choisi par le joueur
} Joueur;

// Esthétique supérieure et inférieure du plateau
void esthetique() {
    printf("  ");
    for (int i = 0; i < 17; i++) {
        printf(" %c", (i % 2 == 0 ? '+' : '-'));
    }
    printf("\n");
}

// Esthétique des numéros de lignes
void esthetique2(int i) {
    if (i < 10) {
        printf("%d ", i);
    } else {
        printf("%c ", 'A' + (i - 10)); // Convertit en lettres pour les numéros au-delà de 9
    }
}

// Affiche les options de pions disponibles
void afficherOptionsPions() {
    printf("Choisissez un pion pour le joueur. Voici quelques options :\n");
    int start = 33; // Premier caractère imprimable (ASCII 33)
    int end = 126;  // Dernier caractère imprimable (ASCII 126)
    for (int i = start; i <= end; i++) {
        printf("%d. %c\n", i - start + 1, (char)i);
    }
}

// Vérifie si un pion a déjà été choisi
bool pionDejaUtilise(char pion, Joueur joueurs[], int nbJoueurs) {
    for (int i = 0; i < nbJoueurs; i++) {
        if (joueurs[i].pion == pion) {
            return true;
        }
    }
    return false;
}

// Permet à un joueur de choisir un pion
void choisirPion(Joueur *joueur, Joueur joueurs[], int nbJoueurs) {
    int choix;
    char pion;
    do {
        afficherOptionsPions();
        printf("Entrez le numéro correspondant à votre choix : ");
        if (scanf("%d", &choix) != 1 || choix < 1 || choix > (126 - 33 + 1)) {
            while (getchar() != '\n'); // Vide le buffer pour gérer les entrées invalides
            printf("Entrée invalide. Réessayez.\n");
            continue;
        }
        pion = (char)(33 + choix - 1);
        if (pionDejaUtilise(pion, joueurs, nbJoueurs)) {
            printf("Ce pion est déjà utilisé par un autre joueur. Choisissez-en un autre.\n");
        } else {
            break;
        }
    } while (true);

    joueur->pion = pion;
    printf("Le pion du joueur %d est maintenant '%c'.\n", joueur->id, joueur->pion);
}

// Fonction pour afficher le plateau avec les pions personnalisés
void afficherPlateau(int N, Joueur joueurs[], char tableau[17][17]) {
    esthetique();
    for (int i = 0; i < 17; i++) {
        esthetique2(i);
        for (int j = 0; j < 17; j++) {
            int pionAffiche = 0;

            // Vérifie si un joueur est à cette position
            for (int k = 0; k < N; k++) {
                if ((i == k * 8) && (j == 8 || j == 0 || j == 16)) {
                    printf(" %c ", joueurs[k].pion);
                    pionAffiche = 1;
                    break;
                }
            }

            // Sinon, affiche le contenu standard du tableau
            if (!pionAffiche) {
                if (tableau[i][j] == CASE_VIDE) {
                    printf(" %c ", CASE_VIDE);
                } else if (tableau[i][j] == BARRIERE) {
                    printf(" %c ", BARRIERE);
                } else if (tableau[i][j] == BARRIERE_H) {
                    printf(" %c ", BARRIERE_H);
                } else {
                    printf(" %c ", tableau[i][j]);
                }
            }
        }
        printf("\n");
    }
    esthetique();
}
