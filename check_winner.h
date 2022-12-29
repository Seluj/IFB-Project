
#ifndef PROJET_IFB_CHECK_WINNER_H
#define PROJET_IFB_CHECK_WINNER_H

/**
 * @file check_winner.h
 * @brief fichier header contenant les prototypes des fonctions relatives au test du gagnant
 * @author Ondine H., Loïs B. et Jules F.
 * @date juin 2021
 */


 /**
  * Verifie si suffisament de jetons sont alignés pour déclarer une victoire
  * @param g grille de jeu
  * @param colonne largeur du jetons à tester
  * @param j1 joueur 1
  * @param j2 joueur 2
  * @return 0 si le premier joueur a gagné, 1 si c’est le second, et -1 si aucun des joueurs n’a gagné
  */
int check_winner(Grid g, int colonne, Joueur j1, Joueur j2);

/**
 * Compte le nombre de jetons dans une direction donnée
 * @param g grille
 * @param jeton jeton à tester
 * @param ligne Hauteur du jeton à tester
 * @param colonne largeur du jeton à tester
 * @param dir_x direction horizontale
 * @param dir_y direction verticale
 * @return retourne le nombre de jetons alignés dans la direction donnée
 */
int nb_jetons_dir(Grid g, char jeton, int ligne, int colonne, int dir_x, int dir_y);

/**
 * calcule la maximum entre deux nombres
 * @param a premier nombre
 * @param b second nombre
 * @return retourne le plus grand
 */
int maximum(int a, int b);

/**
 * renvoi le plus grand nombre de jetons alignés, qu'importe la direction
 * @param g grille
 * @param jeton jeton à tester
 * @param ligne Hauteur du jeton à tester
 * @param colonne Largeur du jeton à tester
 * @return retourne le nombre maximum de jetons de la plus grande ligne
 */
int nb_jetons_alignes(Grid g, char jeton, int ligne, int colonne);

/**
 * Vérifie si les coordonnées {ligne colonne} sont bien dans la grille
 * @param g grille de jeu
 * @param ligne index de ligne
 * @param colonne index de colonne
 * @return retourne TRUE si la position est dans la grille et FALSE sinon
 */
Boolean position_valide(Grid g, int ligne, int colonne);

#endif //PROJET_IFB_CHECK_WINNER_H
