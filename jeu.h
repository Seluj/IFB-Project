
#ifndef PROJET_IFB_JEU_H
#define PROJET_IFB_JEU_H

/**
 * @file jeu.h
 * @brief fichier header contenant les prototypes des fonctions relatives au jeu
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */


/**
 * fonction principale d'un jeu à deux joueurs réels
 * @param play_grille grille de jeu
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 * @param nb_jetons compteur du nombre de jetons dans la grille
 */
void jeu_multi(Grid play_grille, Joueur j1, Joueur j2, int nb_tour, int nb_jetons);

/**
 * fonction principale d'un jeu en solo contre un ordinateur
 * @param play_grille grille de jeu
 * @param j1 joueur 1
 * @param j2 joueur 2
 * @param nb_tour compteur du nombre de tours
 * @param nb_jetons compteur du nombre de jetons dans la grille
 */
void jeu_solo(Grid play_grille, Joueur j1, Joueur j2, int nb_tour, int nb_jetons);

#endif //PROJET_IFB_JEU_H
