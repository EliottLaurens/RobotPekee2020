#include "RobotPekeeSuivi.h"

//*******************************************************************
// Méthode: CRobotPekeeSuivi
// Rôle: Constructeur de la classe RobotPekeeSuivi qui initialise un
//       robot qui avance en enregistrant ses positions
// Paramètres d'entrée:
//		un_nom : Nom du robot
//		une_adrIP : Adresse IP du robot
// Paramètres transmis à la classe mère:
//		un_nom
//		une_adrIP
//*******************************************************************
CRobotPekeeSuivi::CRobotPekeeSuivi(string un_nom,string une_adrIP):CRobotPekee(un_nom,une_adrIP)
{
	this->parcours.push_back(this->position);
}

//************************************************
// Méthode: ~CRobotPekeeSuivi
// Rôle: Destructeur de la classe RobotPekeeSuivi
//************************************************
CRobotPekeeSuivi::~CRobotPekeeSuivi(void)
{
}

//******************************************************
// Méthode: avancer
// Rôle: Permet au robot d'avancer sur une distance en
//		 enregistrant sa position à la fin
// Paramètres d'entrée :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse à laquelle le robot avancera
//******************************************************
void CRobotPekeeSuivi::avancer(float distance,int vitesseT)
{
	this->CRobotPekee::avancer(distance,vitesseT);
	this->parcours.push_back(this->position);
}

//******************************************************
// Méthode: reculer
// Rôle: Permet au robot de reculer sur une distance en
//		 enregistrant sa position à la fin
// Paramètres d'entrée :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse à laquelle le robot reculera
//******************************************************
void CRobotPekeeSuivi::reculer(float distance,int vitesseT)
{
	this->CRobotPekee::reculer(distance,vitesseT);
	this->parcours.push_back(this->position);
}

//******************************************
// Méthode: avancer
// Rôle: Permet au robot d'avancer et 
//		 d'enregistrer sa position à la fin 
//******************************************
void CRobotPekeeSuivi::avancer()
{
	this->CRobotPekee::avancer();
	this->parcours.push_back(this->position);
}

//******************************************
// Méthode: reculer
// Rôle: Permet au robot de reculer et
//		 d'enregistrer sa position à la fin	 
//******************************************
void CRobotPekeeSuivi::reculer()
{
	this->CRobotPekee::reculer();
	this->parcours.push_back(this->position);
}

//*************************************************
// Méthode: enregistrerPosition
// Rôle: Permet au robot d'enregistrer sa position
//		 actuelle dans le vecteur parcours
//*************************************************
vector<CPosition> CRobotPekeeSuivi::enregistrerPosition()
{
	this->parcours.push_back(this->position);
}

//************************************
// Méthode: getParcoursSize
// Rôle: Permet de renvoyer la valeur 
//		 actuelle du vecteur parcours
//************************************
int CRobotPekeeSuivi::getParcoursSize()
{
	return this->parcours.size();
}

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
void CRobotPekeeSuivi::connaitrePosition(float &x, float &y, float &z, int i)
{
	this->parcours.at(i).coordonnees(x,y);
	z=this->parcours.at(i).orientation();
}