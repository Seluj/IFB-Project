
#include "main.h"

/**
 * @file jeu.c
 * @brief fichier source contenant les fonctions relatives au jeu
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */




void jeu_multi(Grid play_grille, Joueur j1, Joueur j2, int nb_tour, int nb_jetons)
{

    Boolean test;
    int choix_mvt_utilisateur, col_precedent=-1, choix_mvt_utilisateur_precedent = 1;
    int col_choisie = 2;
    int gagnant=-1;
    char jeton;

    while(
            gagnant == -1
            && grille_pleine(play_grille) == FALSE
            && choix_mvt_utilisateur != 3){
        /*
         * on repete le contenu de la boucle, tant que personne n'a gagné,
         * que on peut insérer des jetons dans la grille,
         * et qu'aucun des joueurs ne veut sauvegarder
         */

        //on adapte la couleur en fonction de celui qui joue
        if(nb_tour % 2 == j1.numero_joueur){
            couleur(4, 0);
            printf("\nAu tour de %s :\n", j1.pseudo);
            jeton = j1.jeton;
        }else if(nb_tour % 2 == j2.numero_joueur){
            couleur(14, 0);
            printf("\nAu tour de %s :\n", j2.pseudo);
            jeton = j2.jeton;
        }

        //on demande ce que l'utilisateur veut faire
        choix_mvt_utilisateur = menu_mvt(nb_jetons);

        switch(choix_mvt_utilisateur){

            case 1: //l'utilisateur a choisi d'ajouter un jeton
                do{
                    //On demande dans quelle colonne veut-il ajouter un jeton
                    col_choisie = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);
                    test = add_token(&play_grille, col_choisie, jeton);
                }while(test == FALSE); //on répete tant que le jeton ne peux pas etre inséré
                nb_jetons++; //le nombre de jetons augmente
                break;

            case 2: //l'utilisateur choisi de retirer un jeton
                do{
                    //On demande dans quelle colonne veut-il enlever un jeton
                    col_choisie = colonne_utilisateur(play_grille, col_precedent, choix_mvt_utilisateur,
                                                     choix_mvt_utilisateur_precedent);
                    test = remove_token(&play_grille, col_choisie - 1);
                }while(test == FALSE); //on répete tant que le jeton ne peux pas etre enlevé
                nb_jetons--; //le nombre de jetons diminue
                break;

            case 3: //l'utilisateur choisi de sauvegarder la partie
                save(play_grille, nb_tour, nb_jetons, j1, j2, 2);
                break;
            default:
                break;
        }
        nb_tour++; //on augmente a chaque fois le nombre de tour pour faire alterner les joueurs
        couleur(15, 0);
        //on met a jour les informations utiles pour le tour suivant
        choix_mvt_utilisateur_precedent = choix_mvt_utilisateur;
        col_precedent = col_choisie;
        affichage_grille(play_grille); //affichage de la grille
        gagnant = check_winner(play_grille, col_choisie, j1, j2); //test du gagnant
    }

    printf("\n\n\n");
    //Annonce du gagnant
    if(gagnant == 0){ //Joueur 1 a gagné
        if(j1.jeton == 'X'){
            couleur(4, 0);
        }else{
            couleur(14, 0);
        }
        affichage_trophe();
        printf("%s a gagn%c(e) !", j1.pseudo, 130);
        couleur(15, 0);
    }else if(gagnant == 1){ //Le joueur 2 a gagné
        if(j2.jeton == 'X'){
            couleur(4, 0);
        }else{
            couleur(14, 0);
        }
        affichage_trophe();
        printf("%s a gagn%c(e) !", j2.pseudo, 130);
        couleur(15, 0);
    }else if(gagnant == -1 && grille_pleine(play_grille) == TRUE){ //Match nul, personne a gagné
        printf("Match nul !");
    }
}

void jeu_solo(Grid play_grille, Joueur j1, Joueur j2, int nb_tour, int nb_jetons)
{

    Boolean test;
    int choix_mvt, col_precedente, choix_mvt_precedent = -1;
    int col_choisie = 2, gagnant = -1;

    while(
            gagnant == -1
            && grille_pleine(play_grille) == FALSE
            && choix_mvt != 3){
        /*
         * on repete le contenu de la boucle, tant que personne n'a gagné,
         * que on peut insérer des jetons dans la grille,
         * et qu'aucun des joueurs ne veut sauvegarder
         */

        if(nb_tour % 2 == j1.numero_joueur){
            if(j1.jeton == 'X'){
                couleur(4, 0);
            }else{
                couleur(14, 0);
            }
            printf("\nAu tour de %s :\n", j1.pseudo);
            choix_mvt = menu_mvt(nb_jetons);
            switch(choix_mvt){

                case 1: //l'utilisateur choisi d'ajouter un jeton
                    do{
                        //On demande dans quelle colonne veut-il ajouter un jeton
                        col_choisie = colonne_utilisateur(play_grille, col_precedente, choix_mvt,
                                                         choix_mvt_precedent);
                        test = add_token(&play_grille, col_choisie, j1.jeton);
                    }while(test == FALSE); //on répète tant que le jeton ne peux pas etre inséré
                    nb_jetons++;
                    break;

                case 2: //l'utilisateur choisi d'enlever un jeton
                    do{
                        //On demande dans quelle colonne veut-il enlever un jeton
                        col_choisie = colonne_utilisateur(play_grille, col_precedente, choix_mvt,
                                                         choix_mvt_precedent);
                        test = remove_token(&play_grille, col_choisie - 1);
                    }while(test == FALSE); //on répete tant que le jeton ne peux pas etre enlevé
                    nb_jetons--;
                    break;

                case 3: //l'utilisateur choisi de sauvegarder la partie
                    printf("\n...Enregistrement de la grille...");
                    save(play_grille, nb_tour, nb_jetons, j1, j2, 1);
                    break;
                default:
                    break;
            }
            couleur(15, 0);
        }else if(nb_tour%2 == j2.numero_joueur){
            if(j2.jeton == 'X'){
                couleur(4, 0);
            }else{
                couleur(14, 0);
            }
            printf("\nAu tour de %s :\n", j2.pseudo);
            choix_mvt = mvt_ordi(nb_jetons);
            switch(choix_mvt){
                case 1:
                    do{
                        col_choisie = colonne_ordi(play_grille, col_precedente, choix_mvt, choix_mvt_precedent);
                        test = add_token(&play_grille, col_choisie, j2.jeton);
                    }while(test == FALSE);
                    printf("\nL'ordinateur a decid%c de mettre un jeton dans la colonne %d\n\n", 130, col_choisie);
                    nb_jetons++;
                    break;
                case 2:
                    do{
                        col_choisie = colonne_ordi(play_grille, col_precedente, choix_mvt, choix_mvt_precedent);
                        test = remove_token(&play_grille, col_choisie-1);
                    }while(test == FALSE);
                    printf("\nL'ordinateur a decid%c d'enlever un jeton dans la colonne %d\n\n", 130, col_choisie);
                    nb_jetons--;
                    break;
            }
            couleur(15, 0);
            affichage_grille(play_grille);
        }
        nb_tour++;
        choix_mvt_precedent = choix_mvt;
        col_precedente = col_choisie;
        gagnant = check_winner(play_grille, col_choisie, j1, j2);
    }

    printf("\n\n\n");
    //Annonce du gagnant
    if(gagnant == 0){
        if(j1.jeton == 'X'){ //le joueur a gagné
            couleur(4, 0);
        }else{
            couleur(14, 0);
        }
        affichage_trophe();
        printf("%s a gagn%c(e)", j1.pseudo, 130);
        couleur(15, 0);
    }else if(gagnant == 1){ //L'ordinateur a gagné
        if(j2.jeton == 'X'){
            couleur(4, 0);
        }else{
            couleur(14, 0);
        }
        affichage_trophe();
        printf("%s a gagn%c(e)", j2.pseudo, 130);
        couleur(15, 0);
    }else if(gagnant == -1 && grille_pleine(play_grille) == TRUE){ //Match nul, personne a gagné
        printf("Match nul !");
    }
}