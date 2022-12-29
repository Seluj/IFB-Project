
#ifndef PROJET_IFB_ORDINATEUR_H
#define PROJET_IFB_ORDINATEUR_H

/**
 * @file ordinateur.h
 * @brief fichier header contenant les prototypes des fonctions relatives au jeu de l'ordinateur
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */

/**
 * choix du mouvement de l'ordinateur
 * @param nb_jetons Nombre de jetons dans la grille
 * @return le choix du mouvement : 1 pour poser un jeton, 2 pour en retirer un
 *         Il ne peux pas enregistrer la partie
 */
int mvt_ordi(int nb_jetons);

/**
 * générer une colonne aléatoire pour l'ordinateur
 * @param g grille de jeu
 * @param col colonne précédente
 * @param choix_mouvement choix voulu
 * @param choix_mouvement_precedent choix précédent
 * @return retourne le numéro de la colonne choisie
 */
int colonne_ordi(Grid g, int col_precedent, int choix_mvt, int choix_mvt_precedent);

#endif //PROJET_IFB_ORDINATEUR_H
