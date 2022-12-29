
#include "main.h"

/**
 * @file main.c
 * @brief fichier source contenant la fonction main
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */




int main()
{
    Grid play_grille; //grille où sera stockée le jeu
    Joueur j1, j2; //joueurs de la partie
    int nb_tour; //Nombre de tours de la partie. S'incrémente à chaque action d'un joueur/ de l'ordinateur
    int nb_jetons; //Nombre de jetons sur la grille
    int nb_joueur; //nombre de joueurs réels
    Boolean ouverture;//Variable d'ouverture du fichier et du début de partie : TRUE->OK on peut commencer a jouer FALSE->pas OK
    int choix;
    affichage_debut();
    //Boucle de vérification de l'existence d'une sauvegarde
    do{
        choix = menu_principal(); //le joueur choisi si il veut faire une nouvelle partie, charger une ancienne ou quitter.
        switch(choix){
            case 1: //on débute une nouvelle partie
                //initie toutes les composantes nécessaires au bon déroulement du jeu
                initialisation_grille(&play_grille);
                nb_tour = 0;
                nb_jetons = 0;
                nb_joueur = initialisation_joueur(&j1, &j2);
                ouverture = TRUE;
                break;
            case 2: //on reprend une partie précédente
                ouverture = load(&play_grille, &nb_tour, &nb_jetons, &j1, &j2, &nb_joueur);
                break;
            case 3: //on quitte le programme
                printf("Vous allez quitter...\n");
                ouverture = TRUE;
                break;
            default:
                break;
        }
    }while(ouverture == FALSE);

    if(choix != 3){ //si on décide de commencer une nouvelle partie/reprendre une partie précédente
        affichage_grille(play_grille);

        if(nb_joueur == 2){
            //partie à deux joueurs
            jeu_multi(play_grille, j1, j2, nb_tour, nb_jetons);

        }else if(nb_joueur == 1){
            //partie contre l'ordinateur
            jeu_solo(play_grille, j1, j2, nb_tour, nb_jetons);
        }

    }

    //libération de la mémoire si une partie a été joué
    if(choix==1 || choix == 2){
        free_memory(&play_grille);
    }
    return 0;
}
