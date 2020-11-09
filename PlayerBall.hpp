#ifndef PLAYERBALL_HPP
#define PLAYERBALL_HPP
#include <iostream>
#include "LCD.hpp"


/**
 * @enum Direction
 * @brief Liste les mouvements possibles
 * @details Liste les 8 mouvements possible pour le personnage ou la balle
 */
enum class Direction {
	/// @brief Vers le haut de l'écran
	North, 
	
	/// @brief Vers le bas de l'écran
	South, 
	
	/// @brief Vers la droite de l'écran
	East, 
	
	/// @brief Vers la gauche de l'écran
	West, 
	
	/// @brief Vers le haut à droite de l'écran
	North_East, 
	
	/// @brief Vers le haut à gauche de l'écran
	North_West, 
	
	/// @brief Vers le bas à droite de l'écran
	South_East, 
	
	/// @brief Vers le bas à gauche de l'écran
	South_West
};


/**
 * @brief Classe mère de Player et Ball
 * @details Cette classe sert de classe mère aux classes PLayer et Ball,
 * évitant ainsi de répéter des attributs semblables. 
 * Elle ne doit pas être instanciée directement.
 */

class PlayerBall {
protected:
	int m_rad;
	int m_color;
	int m_x;
	int m_y;
	int m_speed;

public:
	/** @brief Constructeur (/!\ à ne pas utiliser directement /!\)
	 * @details Le contructeur doit être appelé via une classe fille
	 * @param[in] rad Le rayon de sa représentation
	 * @param[in] color Sa couleur
	 * @param[in] x Sa position X
	 * @param[in] y Sa position Y
	 * @param[in] speed Sa vitesse de déplacement
	 */
	PlayerBall(int rad, int color, int x, int y, int speed); 

	/**
	 * @brief Permet de faire bouger le personnage ou la balle
	 * @details Teste si le déplacement et appelle la méthode d'affichage pour afficher la nouvelle position.
	 * @param[in] direction Direction du mouvement (voir enum class Direction)
	 * @post Le personnage ou la balle aura bougé dans la bonne direction en fonciton de sa vitesse.
	 * @returns 
	 */
	Direction move(Direction direction); // Traitement correct de la vitesse (m_speed correspondant à la norme du vecteur directeur)
	
	/**
	 * @brief Permet d'afficher le personnage ou la balle
	 * @details Prend les anciennes coordonnées pour effacer l'ancienne balle et la
	 * remplacer par la nouvelle aux nouvelles coordonnées. Les nouvelles coordonnées sont 
	 * les coordonnées stockés dans les attributs de l'objet
	 * @param[in] new_x Nouvelle position X de la balle
	 * @param[in] new_y Nouvelle position Y de la balle
	 * @post Le personnage ou la balle sera affiché à sa position m_x et m_y et son ancienne position sera supprimée
	 */
	void display(int new_x, int new_y);
};


#endif


