#include "scores.h"

// Charger les scores depuis un fichier
void chargerScores(FILE *fichier, Joueur joueurs[], int *nbJoueurs) {
    while (fscanf(fichier, "%s %d", joueurs[*nbJoueurs].nom, &joueurs[*nbJoueurs].score) == 2) {
        (*nbJoueurs)++;
    }
}

// Sauvegarder les scores dans un fichier
void sauvegarderScores(FILE *fichier, Joueur joueurs[], int nbJoueurs) {
    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].nom, joueurs[i].score);
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
void mettreAJourScore(Joueur joueurs[], int *nbJoueurs, const char *nom, int points) {
    int index = trouverJoueur(joueurs, *nbJoueurs, nom);

    if (index == -1) {
        // Nouveau joueur
        strcpy(joueurs[*nbJoueurs].nom, nom);
        joueurs[*nbJoueurs].score = points;
        (*nbJoueurs)++;
    } else {
        // Joueur existant
        joueurs[index].score += points;
    }
}

