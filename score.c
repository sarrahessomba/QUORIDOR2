#include "score.h"

// Charger les scores depuis un fichier
void chargerScores(FILE *fichier, Joueur joueurs[], int *nbJoueurs) {
    while (*nbJoueurs < MAX_JOUEURS && fscanf(fichier, "%s %d %d", joueurs[*nbJoueurs].nom, &joueurs[*nbJoueurs].score, &joueurs[*nbJoueurs].pion) == 3) {
        (*nbJoueurs)++;
    }
}

// Sauvegarder les scores dans un fichier
void sauvegarderScores(FILE *fichier, Joueur joueurs[], int nbJoueurs) {
    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(fichier, "%s %d %d\n", joueurs[i].nom, joueurs[i].score, joueurs[i].pion);
    }
}

// Trouver l'index d'un joueur dans le tableau (-1 si non trouvé)
int trouverJoueur(Joueur joueurs[], int nbJoueurs, const char *nom) {
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(joueurs[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Mise à jour du score d'un joueur
void mettreAJourScore(Joueur joueurs[], int *nbJoueurs, const char *nom, int points, int pion) {
    int index = trouverJoueur(joueurs, *nbJoueurs, nom);

    if (index == -1) {
        // Nouveau joueur
        if (*nbJoueurs < MAX_JOUEURS) {
            strcpy(joueurs[*nbJoueurs].nom, nom);
            joueurs[*nbJoueurs].score = points;
            joueurs[*nbJoueurs].pion = pion;
            (*nbJoueurs)++;
        } else {
            printf("Le tableau des joueurs est plein, impossible d'ajouter %s.\n", nom);
        }
    } else {
        // Joueur existant
        joueurs[index].score += points;
        joueurs[index].pion = pion; // Mise à jour du pion
    }
}
