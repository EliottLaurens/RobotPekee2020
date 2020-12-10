#pragma once
#include "robotpekee.h"
#include <vector>
#include <string>
class CRobotPekeeSuivi :
	public CRobotPekee
{
public:

	//*******************************************************************
	// M�thode: CRobotPekeeSuivi
	// R�le: Constructeur de la classe RobotPekeeSuivi qui initialise un
	//       robot qui avance en enregistrant ses positions
	// Param�tres d'entr�e:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	// Param�tres de sortie :
	// 
	//*******************************************************************
	CRobotPekeeSuivi(string un_nom,string une_adrIP);

	//************************************************
	// M�thode: ~CRobotPekeeSuivi
	// R�le: Destructeur de la classe RobotPekeeSuivi
	//************************************************
	~CRobotPekeeSuivi(void);
	
	//******************************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer sur une distance en
	//		 enregistrant sa position � la fin
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot avancera
	//******************************************************
	void avancer(float distance,int vitesseT=100);

	//******************************************************
	// M�thode: reculer
	// R�le: Permet au robot de reculer sur une distance en
	//		 enregistrant sa position � la fin
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot reculera
	//******************************************************
	void reculer(float distance,int vitesseT=100);

	//******************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer et 
	//		 d'enregistrer sa position � la fin 
	//******************************************
	void avancer();

	//******************************************
	// M�thode: reculer
	// R�le: Permet au robot de reculer et
	//		 d'enregistrer sa position � la fin	 
	//******************************************
	void reculer();

	//*************************************************
	// M�thode: enregistrerPosition
	// R�le: Permet au robot d'enregistrer sa position
	//		 actuelle dans le vecteur parcours
	//*************************************************
	vector <CPosition> enregistrerPosition();

	//************************************
	// M�thode: getParcoursSize
	// R�le: Permet de renvoyer la valeur 
	//		 actuelle du vecteur parcours
	//************************************
	int getParcoursSize();

	//******************************************************
	// M�thode: connaitrePosition
	// R�le: Permet de conna�tre une position sp�cifique du
	//		 robot sur le vecteur parcours
	// Param�tres d'entr�e :
	//		i : position que l'on souhaite conna�tre
	// Param�tres de sortie : 
	//		x : abscisse de la position
	//		y : ordonn�e de la position
	//		z : angle de la position
	//******************************************************
	void connaitrePosition(float &x, float &y, float &z, int i=0);

private:

	vector <CPosition> parcours; // Vecteur permettant d'enregistrer toutes les positions du robot
};

