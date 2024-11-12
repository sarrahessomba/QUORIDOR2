#include <stdio.h>
#include <time.h>

#define NOMBRE_JOUEURS 2

// Structure pour stocker les informations de chaque joueur
typedef struct {
    double tempsTotal; // Temps total accumulé pour chaque joueur par partie
    int points;        // Points du joueur pour calculer les malus à la fin de la partie
} Joueur;

// Fonction pour jouer un tour et calculer le temps écoulé pour le joueur
void jouerTour(Joueur *joueur) {
    time_t debutTour = time(NULL);  // Enregistre le temps de début du tour

    printf("Tour en cours. Appuyez sur 'e' pour terminer le tour.\n");
    while (getchar() != 'e');  // Attend que l'utilisateur appuie sur 'e'

    time_t finTour = time(NULL);  // Temps à la fin du tour
    double tempsEcoule = difftime(finTour, debutTour);
    joueur->tempsTotal += tempsEcoule;  // Ajoute le temps écoulé au total

    printf("Temps ecoule pour ce tour : %.0f secondes\n", tempsEcoule);
}

// Fonction pour trouver le joueur avec le plus de temps de jeu
int JoueurLePlusLongTemps(Joueur joueurs[], int nombreJoueurs) {
    int indiceMax = 0;
    for (int i = 1; i < nombreJoueurs; i++) {
        if (joueurs[i].tempsTotal > joueurs[indiceMax].tempsTotal) {
            indiceMax = i;
        }
    }
    return indiceMax;
}

int main() {
    Joueur joueurs[NOMBRE_JOUEURS] = {{0, }, {0, 10}};  // Initialisation des joueurs avec 10 points chacun

    int joueurActuel = 0;
    char commande;

    // Boucle de jeu
    while (1) {
        printf("Joueur %d, appuyez sur 's' pour commencer votre tour, 'q' pour quitter : ", joueurActuel + 1);
        scanf(" %c", &commande);
        getchar();  // attente de la frappe d'un caractère de la part de l'utilisateur pour continuer

        if (commande == 's') {
            jouerTour(&joueurs[joueurActuel]);  // Démarre le tour du joueur
            joueurActuel = (joueurActuel + 1) % NOMBRE_JOUEURS;  // Passe au joueur suivant
        } else if (commande == 'q') {
            break;  // Quitte le jeu
        }
    }

    // Fin de la partie : Calcul des pénalités
    int MalusJoueur = JoueurLePlusLongTemps(joueurs, NOMBRE_JOUEURS);
    joueurs[MalusJoueur].points -= 2;  // Pénalise le joueur avec le plus de temps à la fin de la partie

    // Affiche les résultats finaux avec le temps total de chaque joueur
    printf("\nResultats finaux :\n");
    for (int i = 0; i < NOMBRE_JOUEURS; i++) {
        printf("Joueur %d - Temps total : %.0f secondes, Points : %d\n",
               i + 1, joueurs[i].tempsTotal, joueurs[i].points);
    }

    return 0;
}

