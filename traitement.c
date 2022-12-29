
#include "main.h"

/**
 * @file traitement.c
 * @brief fichier source contenant les fonctions relatives aux calculs
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */


void initialisation_grille(Grid* grille)
{
    int size;

    //Controle d'aquistion avec message d'erreur du nombre de jeton à aligner
    printf("Entrer le nombre de jetons %c aligner pour gagner : ", 133);
    scanf("%d", &size);
    fflush((stdin));
    while(size <= 2 || size >= 9){
        printf("Nombre de jetons invalides vous pouvez mettre entre 3 et 8, veuillez recommencer\n");
        printf("Entrer le nombre de jetons %c aligner pour gagner : ", 133);
        scanf("%d", &size);
        fflush((stdin));
    }
    //génération de la grille
    grille->hauteur = size+2;
    grille->largeur = size+2;
    grille->grille = (char**) malloc(sizeof(char*) * grille->hauteur);
    for(int i = 0; i < grille->hauteur; i++){
        grille->grille[i] = (char*) malloc(sizeof(char) * grille->largeur);
        for(int j = 0; j < grille->largeur; j++){
            grille->grille[i][j] = '_';
        }
    }
}

int initialisation_joueur(Joueur* j1, Joueur* j2)
{
    srand(time(0));
    int couleur, alea, nb_joueur;
    char tab[2] ={'X', 'O'};
    nb_joueur = menu_nb_de_joueur();

    if(nb_joueur == 1){ //Le joueur joue contre l'ordinateur on le laisse choisir sa couleur et on demande son pseudo
        strcpy(j2->pseudo, "L'ordinateur");
        printf("Quel est votre pseudo (max 100 caract%cres) ?\n", 138);
        gets(j1->pseudo);
        fflush(stdin);
        do{
            printf("Voulez-vous %ctre rouge (1) ou jaune (2) : ", 136);
            scanf("%d", &couleur);
            fflush(stdin);
        }while(couleur != 1 && couleur != 2);

        j1->jeton = tab[couleur-1];
        if(couleur-1 == 0){
            j2->jeton = tab[1];
        }else{
            j2->jeton = tab[0];
        }
    }else if(nb_joueur == 2){ //Deux joueurs on demande leur pseudo
        printf("Joueur 1 : Quel est votre pseudo (max 100 caract%cres) ?\n", 138);
        gets(j1->pseudo);
        fflush(stdin);
        printf("Joueur 2 : Quel est votre pseudo (max 100 caract%cres) ?\n", 138);
        gets(j2->pseudo);
        fflush(stdin);
        j1->jeton = tab[0];
        j2->jeton = tab[1];
        printf("%s est rouge (X) et %s est jaune (O)\n\n", j1->pseudo, j2->pseudo);
    }

    //Définition de l'initiative
    alea = rand()%2;
    j1->numero_joueur = alea;
    if(alea == 0){
        j2->numero_joueur = 1;
        printf("%s joue en premier\n"
               "%s joue en second\n",
               j1->pseudo,
               j2->pseudo);
    }else if(alea == 1){
        j2->numero_joueur = 0;
        printf("%s joue en premier\n"
               "%s joue en second\n",
               j2->pseudo,
               j1->pseudo);
    }
    return nb_joueur;
}

Boolean add_token(Grid* g, int indice, char jeton)
{
    int i = 0;

    //fait "descendre" le jeton
    while(g->grille[indice-1][i] == '_'){
        i++;
    }

    //si le i reste à 0 c'est que la colonne est pleine
    if(i==0){
        return FALSE;
    }else{
        g->grille[indice-1][i-1] = jeton;
        return TRUE;
    }
}

Boolean remove_token(Grid* g, int colonne)
{
    int i = 0;

    //fait "descendre" le jeton
    while(g->grille[colonne][i] == '_'){
        i++;
    }

    //si le i est égale a la taille du tableau c'est que la colonne est vide
    if(i == g->hauteur){
        return FALSE;
    }else{
        g->grille[colonne][i] = '_';
        return TRUE;
    }
}

int colonne_utilisateur(Grid g, int col_precedente, int choix_mouvement, int choix_mouvement_precedent)
{
    int resultat;

    //test du choix de l'utilisateur
    switch(choix_mouvement){
        case 1:
            //test du choix précédent
            if(choix_mouvement_precedent == 2){
                do{
                    printf("Vous avez choisi la colonne : ");
                    scanf("%d", &resultat);
                    fflush(stdin);
                    if(resultat == col_precedente){
                        printf("Vous ne pouvez pas remettre de jetons dans cette case pour ce tour\n");
                    }
                }while(resultat > g.largeur || resultat == col_precedente || resultat <= 0);
            }else{
                do{
                    printf("Vous avez choisi la colonne : ");
                    scanf("%d", &resultat);
                    fflush(stdin);
                }while(resultat > g.largeur || resultat <= 0);
            }
            break;

        case 2:
            do{
                printf("Vous avez choisi la colonne : ");
                scanf("%d", &resultat);
                fflush(stdin);
            }while(resultat > g.largeur);
            break;
    }
    return resultat;
}

void save(Grid g, int nb_tour, int nb_jetons, Joueur j1, Joueur j2, int nb_joueur)
{
    FILE* fichier;
    fichier = fopen("save.txt", "w+");
    fprintf(fichier, "%d\n", nb_jetons);
    fprintf(fichier, "%d\n", nb_tour);
    fprintf(fichier, "%d\t", g.largeur);
    fprintf(fichier, "%d\n", g.hauteur);
    fprintf(fichier, "%d\n", nb_joueur);
    fprintf(fichier, "%s\n", j1.pseudo);
    fprintf(fichier, "%c\t%d\n", j1.jeton, j1.numero_joueur);
    fprintf(fichier, "%s\n", j2.pseudo);
    fprintf(fichier, "%c\t%d\n", j2.jeton, j2.numero_joueur);
    for(int i = 0; i < g.hauteur; i++){
        for(int j = 0; j < g.largeur; j++){
            fprintf(fichier, " %c ", g.grille[j][i]);
        }
        fprintf(fichier, "\n");
    }
}

Boolean load(Grid* g, int* nb_tour, int* nb_jetons, Joueur* j1, Joueur* j2, int* nb_joueur)
{
    FILE* fichier;
    fichier = fopen("save.txt", "r");
    if(fichier != NULL){
        printf("\tOk, je charge la grille pr%cc%cdente...\n", 130, 130);
        fscanf(fichier, "%d\n", nb_jetons);
        fscanf(fichier, "%d\n", nb_tour);
        fscanf(fichier, "%d\t", &g->largeur);
        fscanf(fichier, "%d\n", &g->hauteur);
        fscanf(fichier, "%d\n", nb_joueur);
        fscanf(fichier, "%s\n", j1->pseudo);
        fscanf(fichier, "%c\t%d\n", &j1->jeton, &j1->numero_joueur);
        fscanf(fichier, "%s\n", j2->pseudo);
        fscanf(fichier, "%c\t%d\n", &j2->jeton, &j2->numero_joueur);
        g->grille = (char **) malloc(sizeof(char *) * g->hauteur);
        for(int i = 0; i < g->hauteur; i++){
            g->grille[i] = (char *) malloc(sizeof(char) * g->largeur);
        }
        for(int i = 0; i < g->hauteur; i++){
            for(int j = 0; j < g->largeur; j++){
                fscanf(fichier, " %c ", &g->grille[j][i]);
            }
            fscanf(fichier, "\n");
        }
        return TRUE;
    }else{
        printf("Impossible de g%cn%crer la grille", 130, 130);
        return FALSE;
    }
}

Boolean grille_pleine(Grid g)
{
    int s = 0;
    for(int j = 0; j < g.largeur; j++){
        if(g.grille[j][0] == '_'){
            s++;
        }
    }
    if(s == 0){
        return TRUE;
    }else{
        return FALSE;
    }
}

void free_memory(Grid* grille)
{
    for(int i = 0; i < grille->hauteur; i++){
        free(grille->grille[i]);
    }
    free(grille->grille);
}