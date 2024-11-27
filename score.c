//
// Created by damien on 21/11/2024.
//
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "fonction.joueur.h"
// Charger les scores depuis un fichier


// Sauvegarder les scores dans un fichier

/*
int Sauvegarder_Scores(joueur joueur[],int N, const char *nomdufichier) {
    FILE *fichier = fopen(nomdufichier, "a");
    if (fichier == NULL) {
        perror("Erreur de sauvegarde de scores");
        return -1;
    }
    for(int i=0;i<N;i++) {
        fprintf(fichier, "%s %d\n", joueur[i].nom, joueur[i].score);
    }
    fclose(fichier);
    printf("Sauvegarde du score réussie\n");
    return 0;
}
int trouverJoueur(joueur *joueurr, const char *nomdufichier) {
    FILE *fichier = fopen(nomdufichier, "r");
    if (fichier == NULL) {
        perror("Erreur d'ouverture du fichier pour recherche");
        return -1;
    }
    joueur joueurFichier;
    while (fscanf(fichier, "%s %d", joueurFichier.nom, &joueurFichier.score) != EOF) {
        if (strcasecmp(joueurr->nom, joueurFichier.nom) == 0) { // Noms identiques (sans distinction de casse)
            fclose(fichier);
            return joueurFichier.score;
        }
    }
    fclose(fichier);
    return -1; // Non trouvé
}
void mettreAJourScore(joueur joueurs[], int nbJoueurs, const char *nomdufichier) {
    FILE *fichier = fopen(nomdufichier, "r");
    FILE *tempFichier = fopen("temp_scores.txt", "w");
    if (fichier == NULL || tempFichier == NULL) {
        perror("Erreur lors de l'ouverture des fichiers pour mise à jour");
        exit(1);
    }

    joueur joueurFichier;
    int trouve;
    // Mettre à jour les scores dans le fichier temporaire
    while (fscanf(fichier, "%s %d", joueurFichier.nom, &joueurFichier.score) != EOF) {
        trouve = 0;
        for (int i = 0; i < nbJoueurs; i++) {
            if (strcasecmp(joueurFichier.nom, joueurs[i].nom) == 0) {
                joueurFichier.score += joueurs[i].score; // Mettre à jour le score
                trouve = 1;
                joueurs[i].score = 0; // Score déjà traité
                break;
            }
        }
        fprintf(tempFichier, "%s %d\n", joueurFichier.nom, joueurFichier.score);
    }

    // Ajouter les nouveaux joueurs non trouvés
    for (int i = 0; i < nbJoueurs; i++) {
        if (joueurs[i].score > 0) {
            fprintf(tempFichier, "%s %d\n", joueurs[i].nom, joueurs[i].score);
        }
    }

    fclose(fichier);
    fclose(tempFichier);

    // Remplace le fichier d'origine par le fichier temporaire
    remove(nomdufichier);
    rename("temp_scores.txt", nomdufichier);

    printf("Mise à jour des scores terminée\n");
}
/*int Sauvegarder_Scores(joueur joueur[],int N,const char* nomfichier) {
    FILE *fichier=NULL;
    fichier=fopen(nomfichier,"a");
    if(fichier==NULL) {
        printf("Erreur de sauvegarde de scores\n");
       return -1;
    }
    for(int i=0;i<N;i++) {
        fprintf(fichier, "%s %d\n", joueur[i].nom, joueur[i].score);
    }
        fclose(fichier);
        printf("Sauvergarde de score reussie\n");
}

// Trouver l'index d'un joueur dans le tableau (-1 si non trouvé)

int trouverJoueur(joueur joueurs,const char* nomfichier) {
    FILE *fichier=NULL;
   fichier=fopen(nomfichier,"r");
    joueur joueur;
    if(fichier==NULL) {
        printf("fichier inexixtant\n");
        return -2;
    }
        while(fscanf(fichier,"%s %d",joueur.nom,&joueur.score)!=EOF) {
            if(strcasecmp(joueur.nom,joueurs.nom)==0) {
                joueur.score=joueur.score+joueurs.score;
                return joueur.score;
            }
        }
    fclose(fichier);
    return -1;
}

// Mise à jour du score d'un joueur
int mettreAJourScore(joueur joueurs[], int nbJoueurs,const char* nomfichier) {
    FILE *fichier=NULL;
    FILE *fichiertemp=NULL;
    fichier=fopen(nomfichier,"r");
    fichiertemp=fopen("fichiertempscore.txt","w");
    if(fichier==NULL||fichiertemp==NULL) {
        printf("Erreur de mis a jour de scores\n");
        return -1;
    }
    for(int i = 0; i <nbJoueurs ; i++) {
       int d;
        d=trouverJoueur(joueurs[i],nomfichier);
        if(d==-1) {
            fprintf(fichiertemp,"%s %d\n",joueurs[i].nom, joueurs[i].score);
        }
        fprintf(fichiertemp,"%s %d\n",joueurs[i].nom,d);
    }
    fclose(fichiertemp);
    fclose(fichier);
    remove(nomfichier);
    rename("fichiertempscore.txt",nomfichier);
    printf("Mis a jour reussi\n");
}*/
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
