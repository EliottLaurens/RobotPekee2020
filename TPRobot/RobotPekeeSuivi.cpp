#include "RobotPekeeSuivi.h"

//*******************************************************************
// M�thode: CRobotPekeeSuivi
// R�le: Constructeur de la classe RobotPekeeSuivi qui initialise un
//       robot qui avance en enregistrant ses positions
// Param�tres d'entr�e:
//		un_nom : Nom du robot
//		une_adrIP : Adresse IP du robot
// Param�tres transmis � la classe m�re:
//		un_nom
//		une_adrIP
//*******************************************************************
CRobotPekeeSuivi::CRobotPekeeSuivi(string un_nom,string une_adrIP):CRobotPekee(un_nom,une_adrIP)
{
	this->parcours.push_back(this->position);
}

//************************************************
// M�thode: ~CRobotPekeeSuivi
// R�le: Destructeur de la classe RobotPekeeSuivi
//************************************************
CRobotPekeeSuivi::~CRobotPekeeSuivi(void)
{
}

//******************************************************
// M�thode: avancer
// R�le: Permet au robot d'avancer sur une distance en
//		 enregistrant sa position � la fin
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot avancera
//******************************************************
void CRobotPekeeSuivi::avancer(float distance,int vitesseT)
{
	this->CRobotPekee::avancer(distance,vitesseT);
	this->parcours.push_back(this->position);
}

//******************************************************
// M�thode: reculer
// R�le: Permet au robot de reculer sur une distance en
//		 enregistrant sa position � la fin
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot reculera
//******************************************************
void CRobotPekeeSuivi::reculer(float distance,int vitesseT)
{
	this->CRobotPekee::reculer(distance,vitesseT);
	this->parcours.push_back(this->position);
}

//******************************************
// M�thode: avancer
// R�le: Permet au robot d'avancer et 
//		 d'enregistrer sa position � la fin 
//******************************************
void CRobotPekeeSuivi::avancer()
{
	this->CRobotPekee::avancer();
	this->parcours.push_back(this->position);
}

//******************************************
// M�thode: reculer
// R�le: Permet au robot de reculer et
//		 d'enregistrer sa position � la fin	 
//******************************************
void CRobotPekeeSuivi::reculer()
{
	this->CRobotPekee::reculer();
	this->parcours.push_back(this->position);
}

//*************************************************
// M�thode: enregistrerPosition
// R�le: Permet au robot d'enregistrer sa position
//		 actuelle dans le vecteur parcours
//*************************************************
vector<CPosition> CRobotPekeeSuivi::enregistrerPosition()
{
	this->parcours.push_back(this->position);
}

//************************************
// M�thode: getParcoursSize
// R�le: Permet de renvoyer la valeur 
//		 actuelle du vecteur parcours
//************************************
int CRobotPekeeSuivi::getParcoursSize()
{
	return this->parcours.size();
}

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
void CRobotPekeeSuivi::connaitrePosition(float &x, float &y, float &z, int i)
{
	this->parcours.at(i).coordonnees(x,y);
	z=this->parcours.at(i).orientation();
}