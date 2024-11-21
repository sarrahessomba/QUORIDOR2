#ifndef ESTHETIQUE_H
#define ESTHETIQUE_H

#include <stdbool.h>

// Définition des constantes pour le plateau
#define MAX_PLAYERS 4
#define CASE_VIDE '·'
#define BARRIERE '|'
#define BARRIERE_H '-'

// Propriétés des pions par défaut
#define PION_J1 '@'
#define PION_J2 '#'
#define PION_J3 '$'
#define PION_J4 '%'

// Structure pour représenter un joueur
typedef struct {
    int id;        // ID du joueur
    char pion;     // Jeton choisi par le joueur
} Joueur;

// Prototypes des fonctions

// Affichage des éléments esthétiques du plateau
void esthetique();
void esthetique2(int i);

// Affiche les options disponibles pour choisir un pion
void afficherOptionsPions();

// Vérifie si un pion a déjà été choisi
bool pionDejaUtilise(char pion, Joueur joueurs[], int nbJoueurs);

// Permet à un joueur de choisir un pion
void choisirPion(Joueur *joueur, Joueur joueurs[], int nbJoueurs);

// Affiche le plateau avec les pions et le contenu personnalisé
void afficherPlateau(int N, Joueur joueurs[], char tableau[17][17]);

#endif // ESTHETIQUE_H
