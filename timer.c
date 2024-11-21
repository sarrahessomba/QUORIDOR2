//
// Created by sarra on 21/11/2024.
//
#include <stdio.h>
#include "timer.h"
#include "fonction.joueur.h"

// Fonction pour jouer un tour et calculer le temps écoulé pour le joueur
void jouerTour(joueur *joueur) {
    time_t debutTour = time(NULL);  // Enregistre le temps de début du tour

    printf("Tour en cours. Appuyez sur 'e' pour terminer le tour.\n");
    while (getchar() != 'e');  // Attend que l'utilisateur appuie sur 'e'

    time_t finTour = time(NULL);  // Temps à la fin du tour
    double tempsEcoule = difftime(finTour, debutTour);
    joueur->tempsTotal += tempsEcoule;  // Ajoute le temps écoulé au total

    printf("Temps écoulé pour ce tour : %.0f secondes\n", tempsEcoule);
}

// Fonction pour trouver le joueur avec le plus de temps de jeu
int JoueurLePlusLongTemps(joueur joueurs[], int nombreJoueurs) {
    int indiceMax = 0;
    for (int i = 1; i < nombreJoueurs; i++) {
        if (joueurs[i].tempsTotal > joueurs[indiceMax].tempsTotal) {
            indiceMax = i;
        }
    }
    return indiceMax;
}