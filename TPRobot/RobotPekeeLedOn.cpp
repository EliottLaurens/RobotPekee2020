//*****************************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeLedOn.cpp
// Code des fonctions de la classe permettant au robot 
// d'avancer avec sa led allum�e
// Historique :
//*****************************************************
#include "RobotPekeeLedOn.h"


//*************************************************************************
// M�thode: CRobotPekeeLedOn
// R�le: Constructeur de la classe RobotPekeeLedOn qui initialise un robot
//       qui peut avancer en allumant sa led
// Param�tres d'entr�e:
//		un_nom : Nom du robot
//		une_adrIP : Adresse IP du robot
// Param�tres transmis � la classe m�re:
//		un_nom
//		une_adrIP
//*************************************************************************
CRobotPekeeLedOn::CRobotPekeeLedOn(string un_nom,string une_adrIP):CRobotPekee(un_nom,une_adrIP)
{

}

//************************************************
// M�thode: ~CRobotPekeeLedOn
// R�le: Destructeur de la classe RobotPekeeLedOn
//************************************************
CRobotPekeeLedOn::~CRobotPekeeLedOn(void)
{

}

//********************************************************
// M�thode: avancer
// R�le: Permet au robot d'avancer sur une distance et �
//		 une vitesse d�finie tout en ayant sa led allum�e
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot avancera
//********************************************************
void CRobotPekeeLedOn::avancer(float distance,int vitesseT)
{
	this->LedOn();
	this->CRobotPekee::avancer(distance,vitesseT);
	this->LedOff();
}

//********************************************************
// M�thode: reculer
// R�le: Permet au robot de reculer sur une distance et �
//		 une vitesse d�finie tout en ayant sa led allum�e
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot reculera
//********************************************************
void CRobotPekeeLedOn::reculer(float distance,int vitesseT)
{
	this->LedOn();
	this->CRobotPekee::reculer(distance,vitesseT);
	this->LedOff();
}

//**************************************************************
// M�thode: avancer
// R�le: Permet au robot d'avancer tout en ayant sa led allum�e
//**************************************************************
void CRobotPekeeLedOn::avancer()
{
	this->LedOn();
	this->CRobotPekee::avancer();
	this->LedOff();
}

//***************************************************************
// M�thode: avancer
// R�le: Permet au robot de reculer tout en ayant sa led allum�e
//***************************************************************
void CRobotPekeeLedOn::reculer()
{
	this->LedOn();
	this->CRobotPekee::reculer();
	this->LedOff();
}