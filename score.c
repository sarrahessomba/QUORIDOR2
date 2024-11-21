//
// Created by damien on 21/11/2024.
//
#include <string.h>
#include <stdio.h>
#include "fonction.joueur.h"
// Charger les scores depuis un fichier
void chargerScores(FILE *fichier, joueur joueurs[], int *nbJoueurs) {
    while (fscanf(fichier, "%s %d", joueurs[*nbJoueurs].nom, &joueurs[*nbJoueurs].score) == 2) {
        (*nbJoueurs)++;
    }
}

// Sauvegarder les scores dans un fichier
void Afficher_Scores(FILE *fichier, joueur joueurs[], int nbJoueurs) {
    for (int i = 0; i < nbJoueurs; i++) {
        fprintf(fichier, "%s %d\n", joueurs[i].nom, joueurs[i].score);
    }
}

// Trouver l'index d'un joueur dans le tableau (-1 si non trouvé)
int trouverJoueur(joueur joueurs[], int nbJoueurs, const char *nom) {
    for (int i = 0; i < nbJoueurs; i++) {
        if (strcmp(joueurs[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

// Mise à jour du score d'un joueur
void mettreAJourScore(joueur joueurs[], int *nbJoueurs, const char *nom, int points) {
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