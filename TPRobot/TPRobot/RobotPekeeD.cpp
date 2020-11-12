//*****************************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeD.cpp
// Code des fonctions de la classe permettant au robot 
// d'avancer en limitant les risques de patinage
// Historique :
//*****************************************************
#include "RobotPekeeD.h"

//*********************************************************************
// M�thode: CRobotPekeeD
// R�le: Constructeur de la classe RobotPekeeD qui initialise un robot
//       qui avance en limitant les risques de patinage
// Param�tres d'entr�e:
//		un_nom : Nom du robot
//		une_adrIP : Adresse IP du robot
//		un_coeffD : Coefficient � appliquer � la distance
//		un_coeffV : Coefficient � appliquer � la vitesse
// Param�tres transmis � la classe m�re:
//		un_nom
//		une_adrIP
//*********************************************************************
CRobotPekeeD::CRobotPekeeD(string un_nom,string une_adrIP,float un_coeffD,float un_coeffV):CRobotPekee(un_nom,une_adrIP)
{
	this->coeffD = un_coeffD;
	this->coeffV = un_coeffV;
}

//********************************************
// M�thode: ~CRobotPekeeD
// R�le: Destructeur de la classe RobotPekeeD
//********************************************
CRobotPekeeD::~CRobotPekeeD(void)
{
}

//******************************************************
// M�thode: avancer
// R�le: Permet au robot d'avancer sur une distance en
//		 limitant ses risques de patinage
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot avancera
//******************************************************
void CRobotPekeeD::avancer(float distance,int vitesseT)
{
	this->CRobotPekee::avancer(coeffD*distance,coeffV*vitesseT);
	this->CRobotPekee::avancer(distance-coeffD*2*distance,vitesseT);
	this->CRobotPekee::avancer(coeffD*distance,coeffV*vitesseT);
}

//******************************************************
// M�thode: reculer
// R�le: Permet au robot de reculer sur une distance en
//		 limitant ses risques de patinage
// Param�tres d'entr�e :
//		distance : Distance parcourue par le robot
//		vitesseT : Vitesse � laquelle le robot reculera
//******************************************************
void CRobotPekeeD::reculer(float distance,int vitesseT)
{
	this->CRobotPekee::reculer(coeffD*distance,coeffV*vitesseT);
	this->CRobotPekee::reculer(distance-coeffD*2*distance,vitesseT);
	this->CRobotPekee::reculer(coeffD*distance,coeffV*vitesseT);
}

//*********************************
// M�thode: avancer
// R�le: Permet au robot d'avancer
//*********************************
void CRobotPekeeD::avancer()
{
	this->CRobotPekee::avancer();
}

//**********************************
// M�thode: avancer
// R�le: Permet au robot de reculer
//**********************************
void CRobotPekeeD::reculer()
{
	this->CRobotPekee::reculer();
}