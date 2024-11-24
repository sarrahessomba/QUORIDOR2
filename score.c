//
// Created by damien on 21/11/2024.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonction.joueur.h"
// Charger les scores depuis un fichier


// Sauvegarder les scores dans un fichier
void Sauvegarder_Scores(joueur joueur,const char * nomdufichier) {
    FILE *fichier;
    fichier=fopen(nomdufichier,"a");
    if(fichier==NULL) {
        printf("Erreur de sauvegarde de scores\n");
        return;
    }
    fprintf(fichier, "%s %d\n", joueur.nom, joueur.score);
    fclose(fichier);
    printf("Sauvergarde de score reussie\n");
}

// Trouver l'index d'un joueur dans le tableau (-1 si non trouvé)

int trouverJoueur(joueur joueurs,const char *nomdufichier) {
    FILE *fichier;
   fichier=fopen(nomdufichier,"r");
    joueur joueur;
    int i=0;
        while(fscanf("%s",joueur.nom)!=EOF) {
            if(strcasecmp(joueur.nom,joueurs.nom)==0) {
                return 1;
            }
            return -1;
        }
}

// Mise à jour du score d'un joueur
void mettreAJourScore(joueur joueurs[], int nbJoueurs, FILE * fichier,const char *nomdufichier) {
    for(int i = 0; i <nbJoueurs ; i++) {
        if (trouverJoueur(joueurs[i],nomdufichier)==-1) {
            Sauvegarder_Scores(joueurs[i],nomdufichier);
        }else if(trouverJoueur(joueurs[i],nomdufichier)==1) {
            joueurs[i].score=joueurs[i].score+5;
        }
    }
}
void afficherScores(const char * nomdufichier,joueur * joueur) {
    FILE *fichier;
    fichier=fopen(nomdufichier,"r");
    if (fichier == NULL) {
        printf("Erreur d'affichage de score.\n");
        exit(1);
    }
    while(fscanf(fichier,"%s %d",joueur->nom,&(joueur->score))!=EOF) {
        printf("%s %d\n",(joueur->nom),(joueur->score));
    }
    fclose(fichier);
    printf("Affichage des scores reussie\n");
}
