//
// Created by sarra on 21/11/2024.
//
#include <stdio.h>
#include "timer.h"
#include "fonction.joueur.h"

// Fonction pour jouer un tour et calculer le temps écoulé pour le joueur
#include "timer.h"

// Initialiser le chronomètre avec le temps total alloué (en secondes)
void initialiser_chronometre(Chronometre* chrono, int temps_total) {
    chrono->temps_restant = temps_total;
    chrono->debut_tour = 0; // Pas encore démarré
}

// Démarrer le chronomètre pour un joueur
void demarrer_chronometre(Chronometre* chrono) {
    chrono->debut_tour = time(NULL);
}

// Obtenir le temps restant pour le joueur
int obtenir_temps_restant(Chronometre* chrono) {
    if (chrono->debut_tour == 0) return chrono->temps_restant; // Non démarré
    time_t ecoule = time(NULL) - chrono->debut_tour;
    return chrono->temps_restant - ecoule;
}

// Vérifier si le temps est écoulé
int temps_ecoule(Chronometre* chrono) {
    return obtenir_temps_restant(chrono) <= 0;
}