#pragma once
#include "robotpekee.h"
#include <vector>
#include <string>
class CRobotPekeeSuivi :
	public CRobotPekee
{
public:

	//*******************************************************************
	// Méthode: CRobotPekeeSuivi
	// Rôle: Constructeur de la classe RobotPekeeSuivi qui initialise un
	//       robot qui avance en enregistrant ses positions
	// Paramètres d'entrée:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	// Paramètres de sortie :
	// 
	//*******************************************************************
	CRobotPekeeSuivi(string un_nom,string une_adrIP);

	//************************************************
	// Méthode: ~CRobotPekeeSuivi
	// Rôle: Destructeur de la classe RobotPekeeSuivi
	//************************************************
	~CRobotPekeeSuivi(void);
	
	//******************************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer sur une distance en
	//		 enregistrant sa position à la fin
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot avancera
	//******************************************************
	void avancer(float distance,int vitesseT=100);

	//******************************************************
	// Méthode: reculer
	// Rôle: Permet au robot de reculer sur une distance en
	//		 enregistrant sa position à la fin
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot reculera
	//******************************************************
	void reculer(float distance,int vitesseT=100);

	//******************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer et 
	//		 d'enregistrer sa position à la fin 
	//******************************************
	void avancer();

	//******************************************
	// Méthode: reculer
	// Rôle: Permet au robot de reculer et
	//		 d'enregistrer sa position à la fin	 
	//******************************************
	void reculer();

	//*************************************************
	// Méthode: enregistrerPosition
	// Rôle: Permet au robot d'enregistrer sa position
	//		 actuelle dans le vecteur parcours
	//*************************************************
	vector <CPosition> enregistrerPosition();

	//************************************
	// Méthode: getParcoursSize
	// Rôle: Permet de renvoyer la valeur 
	//		 actuelle du vecteur parcours
	//************************************
	int getParcoursSize();

	//******************************************************
	// Méthode: connaitrePosition
	// Rôle: Permet de connaître une position spécifique du
	//		 robot sur le vecteur parcours
	// Paramètres d'entrée :
	//		i : position que l'on souhaite connaître
	// Paramètres de sortie : 
	//		x : abscisse de la position
	//		y : ordonnée de la position
	//		z : angle de la position
	//******************************************************
	void connaitrePosition(float &x, float &y, float &z, int i=0);

private:

	vector <CPosition> parcours; // Vecteur permettant d'enregistrer toutes les positions du robot
};

