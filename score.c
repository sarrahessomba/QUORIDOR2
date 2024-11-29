//
// Created by damien on 21/11/2024.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonction.joueur.h"
// Charger les scores depuis un fichier


// Sauvegarder les scores dans un fichier
int mettre_a_jour_score(joueur tab_joueur[], int N, const char* nomFichier) {
    joueur joueurFichier;
    FILE *fichier = fopen(nomFichier, "r");
    FILE *fichiertemp = fopen("tempscore.txt", "w");

    if (fichier == NULL || fichiertemp == NULL) {
        printf("Erreur d'ouverture du fichier pour mise a jour.\n");
        if (fichier != NULL) fclose(fichier);
        if (fichiertemp != NULL) fclose(fichiertemp);
        return -1;
    }

    // Tableau pour garder la trace des joueurs déjà traités
    char noms_deja_vus[100][50]; // Maximum 100 joueurs de 50 caractères
    int nb_vus = 0;

    while (fscanf(fichier, "%s %d", joueurFichier.nom, &joueurFichier.score) != EOF) {
        int found = 0;

        // Vérifier si ce joueur a déjà été traité (pour ignorer les doublons)
        for (int k = 0; k < nb_vus; k++) {
            if (strcasecmp(noms_deja_vus[k], joueurFichier.nom) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {//si found est faux==0
            // Ajouter le nom à la liste des joueurs déjà vus
            strcpy(noms_deja_vus[nb_vus], joueurFichier.nom);
            nb_vus++;

            // Mise à jour si le joueur existe dans tab_joueur
            for (int i = 0; i < N; i++) {
                if (strcasecmp(tab_joueur[i].nom, joueurFichier.nom) == 0) {
                    joueurFichier.score = tab_joueur[i].score + joueurFichier.score;
                    break;
                }
            }

            // Écrire le score mis à jour ou inchangé dans le fichier temporaire
            fprintf(fichiertemp, "%s %d\n", joueurFichier.nom, joueurFichier.score);
        }
    }

    // Ajouter les nouveaux joueurs qui n'étaient pas dans le fichier
    for (int i = 0; i < N; i++) {
        int exists = 0;

        for (int k = 0; k < nb_vus; k++) {
            if (strcasecmp(noms_deja_vus[k], tab_joueur[i].nom) == 0) {
                exists = 1;
                break;
            }
        }

        if (!exists) {
            fprintf(fichiertemp, "%s %d\n", tab_joueur[i].nom, tab_joueur[i].score);
        }
    }

    fclose(fichier);
    fclose(fichiertemp);

    remove(nomFichier);
    rename("tempscore.txt", nomFichier);

    return 0;
}

int sauvegardescore(joueur tab_joueur[],int N,const char * nomFichier) {
    FILE* fichier=NULL;
    fichier=fopen(nomFichier,"a");
    if(fichier==NULL) {
        printf("Erreur de sauvegarde\n");
        return -1;
    }
    for(int i=0;i<N;i++) {
        fprintf(fichier,"%s %d\n",tab_joueur[i].nom,tab_joueur[i].score);
    }
    fclose(fichier);
    return 0;
}

int afficherScores(const char * nomdufichier) {
    joueur joueurfichier;
    FILE *fichier;
    fichier=fopen(nomdufichier,"r");
    if (fichier == NULL) {
        printf("Erreur d'affichage de score.\n");
        return -1;
    }
    while(fscanf(fichier,"%s %d",joueurfichier.nom,&(joueurfichier.score))!=EOF) {
        if(joueurfichier.score>0) {
            printf("%s %d\n",(joueurfichier.nom),(joueurfichier.score)-5);
        }else {
            printf("%s %d\n",(joueurfichier.nom),(joueurfichier.score));
        }
    }
    fclose(fichier);
    printf("Affichage des scores reussie\n");
    return 0;
}
