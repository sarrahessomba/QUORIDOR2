

#include <stdio.h>
#include "Aide.h"

void afficherAide() {
    printf("Regles du jeu :\n");
    printf("- Chaque joueur doit atteindre le bord oppose du plateau pour gagner.\n");
    printf("- A chaque tour, un joueur peut deplacer son pion ou placer une barriere ou meme passer son tour.\n");
    printf("- Les barrieres peuvent etre placees pour bloquer l'adversaire, mais elles ne doivent pas definitivement bloquer l'acces au cote oppose.\n");
    printf("- Un pion peut sauter au-dessus un autre pion (adjacent) si aucune barriere ne le bloque.\n");
    printf("- Le jeu se termine lorsqu'un joueur atteint le bord oppose de sa ligne de départ.\n");

}

void afficherScores() {
    FILE *file = fopen("scores.txt", "r");
    if (file == NULL) {
        printf("Aucun score sauvegardé$e pour le moment.\n");
        return;
    }

    char nom[50];
    int score;
    printf("Scores des joueurs :\n");
    while (fscanf(file, "%s %d", nom, &score) != EOF) {
        printf("Joueur: %s, Score: %d\n", nom, score);
    }
}


    void reprendre_partie(int plateau[17][17], int *N) {
        FILE *file = fopen("sauvegarde_partie.txt", "r");
        if (file == NULL) {
            printf("Aucune partie sauvegardee trouvee.\n");
            return;
        }

        // nombre de joueurs
        fscanf(file, "%d", N);

        // Chargement du plateau
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < 17; j++) {
                fscanf(file, "%d", &plateau[i][j]);
            }
        }

        fclose(file);
        printf("Partie chargée avec succès ! Vous pouvez continuer.\n");
    }





