#include <stdbool.h>
#include <stdio.h>

#define TAILLE 17 // Taille du plateau adaptée pour 17x17

// Définition du plateau et des barrières
char plateau[TAILLE][TAILLE];

// Fonction prototype
bool est_bloque(int joueur_x, int joueur_y, int cible);

// BFS pour vérifier si un chemin existe
bool chemin_existe(int x, int y, int cible) {
    bool visite[TAILLE][TAILLE] = {false};
    int queue[TAILLE * TAILLE][2], debut = 0, fin = 0;
    queue[fin][0] = x;
    queue[fin][1] = y;
    fin++;
    visite[x][y] = true;

    // Directions possibles
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (debut < fin) {
        int cx = queue[debut][0];
        int cy = queue[debut][1];
        debut++;

        // Si la ligne cible est atteinte
        if (cx == cible) return true;

        // Parcours des voisins
        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // Vérification des limites et des barrières
            if (nx >= 0 && nx < TAILLE && ny >= 0 && ny < TAILLE &&
                !visite[nx][ny] && plateau[nx][ny] == '.') {
                queue[fin][0] = nx;
                queue[fin][1] = ny;
                fin++;
                visite[nx][ny] = true;
            }
        }
    }

    return false; // Aucun chemin trouvé
}

// Fonction principale : détecter le blocage
bool est_bloque(int joueur_x, int joueur_y, int cible) {
    // Vérifie si le joueur peut atteindre sa cible
    if (!chemin_existe(joueur_x, joueur_y, cible)) {
        return true; // Pas de chemin vers la cible
    }

    return false; // Au moins un chemin existe
}

int main() {
    // Initialisation d'exemple
    // '.' représente une case vide
    // 'B' représente une barrière
    for (int i = 0; i < TAILLE; i++)
        for (int j = 0; j < TAILLE; j++)
            plateau[i][j] = '.';

    plateau[8][8] = 'B'; // Exemple de barrière

    // Position et cible du joueur (exemple pour un joueur)
    int joueur_x = 0, joueur_y = 8, cible = 16;

    if (est_bloque(joueur_x, joueur_y, cible)) {
        printf("La partie est bloquée !\n");
    } else {
        printf("La partie peut continuer.\n");
    }

    return 0;
