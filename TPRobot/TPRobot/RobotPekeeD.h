//********************************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeD.h
// Interface de la classe permettant au robot 
// d'avancer en limitant les risques de patinage
// Historique :
//********************************************************
#pragma once
#include "robotpekee.h"
#include <string>
class CRobotPekeeD :
	public CRobotPekee
{
public:

	//*********************************************************************
	// M�thode: CRobotPekeeD
	// R�le: Constructeur de la classe RobotPekeeD qui initialise un robot
	//       qui avance en limitant les risques de patinage
	// Param�tres d'entr�e:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	//		un_coeffD : Coefficient � appliquer � la distance
	//		un_coeffV : Coefficient � appliquer � la vitesse
	// Param�tres de sortie :
	// 
	//*********************************************************************
	CRobotPekeeD(string un_nom,string une_adrIP,float un_coeffD,float un_coeffV);

	//********************************************
	// M�thode: ~CRobotPekeeD
	// R�le: Destructeur de la classe RobotPekeeD
	//********************************************
	~CRobotPekeeD(void);

	//******************************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer sur une distance en
	//		 limitant ses risques de patinage
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot avancera
	//******************************************************
	void avancer(float distance,int vitesseT=100);

	//******************************************************
	// M�thode: reculer
	// R�le: Permet au robot de reculer sur une distance en
	//		 limitant ses risques de patinage
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot reculera
	//******************************************************
	void reculer(float distance,int vitesseT=100);

	//*********************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer
	//*********************************
	void avancer();

	//**********************************
	// M�thode: avancer
	// R�le: Permet au robot de reculer
	//**********************************
	void reculer();
private:
	float coeffD; // Coefficient � appliquer � la distance
	float coeffV; // Coefficient � appliquer � la vitesse
};

