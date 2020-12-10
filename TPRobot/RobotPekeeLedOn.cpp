//*****************************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeLedOn.cpp
// Code des fonctions de la classe permettant au robot 
// d'avancer avec sa led allumée
// Historique :
//*****************************************************
#include "RobotPekeeLedOn.h"


//*************************************************************************
// Méthode: CRobotPekeeLedOn
// Rôle: Constructeur de la classe RobotPekeeLedOn qui initialise un robot
//       qui peut avancer en allumant sa led
// Paramètres d'entrée:
//		un_nom : Nom du robot
//		une_adrIP : Adresse IP du robot
// Paramètres transmis à la classe mère:
//		un_nom
//		une_adrIP
//*************************************************************************
CRobotPekeeLedOn::CRobotPekeeLedOn(string un_nom,string une_adrIP):CRobotPekee(un_nom,une_adrIP)
{

}

//************************************************
// Méthode: ~CRobotPekeeLedOn
// Rôle: Destructeur de la classe RobotPekeeLedOn
//************************************************
CRobotPekeeLedOn::~CRobotPekeeLedOn(void)
{

}

//********************************************************
// Méthode: avancer
// Rôle: Permet au robot d'avancer sur une distance et à
//		 une vitesse définie tout en ayant sa led allumée
// Paramètres d'entrée :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse à laquelle le robot avancera
//********************************************************
void CRobotPekeeLedOn::avancer(float distance,int vitesseT)
{
	this->LedOn();
	this->CRobotPekee::avancer(distance,vitesseT);
	this->LedOff();
}

//********************************************************
// Méthode: reculer
// Rôle: Permet au robot de reculer sur une distance et à
//		 une vitesse définie tout en ayant sa led allumée
// Paramètres d'entrée :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse à laquelle le robot reculera
//********************************************************
void CRobotPekeeLedOn::reculer(float distance,int vitesseT)
{
	this->LedOn();
	this->CRobotPekee::reculer(distance,vitesseT);
	this->LedOff();
}

//**************************************************************
// Méthode: avancer
// Rôle: Permet au robot d'avancer tout en ayant sa led allumée
//**************************************************************
void CRobotPekeeLedOn::avancer()
{
	this->LedOn();
	this->CRobotPekee::avancer();
	this->LedOff();
}

//***************************************************************
// Méthode: avancer
// Rôle: Permet au robot de reculer tout en ayant sa led allumée
//***************************************************************
void CRobotPekeeLedOn::reculer()
{
	this->LedOn();
	this->CRobotPekee::reculer();
	this->LedOff();
}