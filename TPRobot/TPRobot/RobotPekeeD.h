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
	// Méthode: CRobotPekeeD
	// Rôle: Constructeur de la classe RobotPekeeD qui initialise un robot
	//       qui avance en limitant les risques de patinage
	// Paramètres d'entrée:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	//		un_coeffD : Coefficient à appliquer à la distance
	//		un_coeffV : Coefficient à appliquer à la vitesse
	// Paramètres de sortie :
	// 
	//*********************************************************************
	CRobotPekeeD(string un_nom,string une_adrIP,float un_coeffD,float un_coeffV);

	//********************************************
	// Méthode: ~CRobotPekeeD
	// Rôle: Destructeur de la classe RobotPekeeD
	//********************************************
	~CRobotPekeeD(void);

	//******************************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer sur une distance en
	//		 limitant ses risques de patinage
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot avancera
	//******************************************************
	void avancer(float distance,int vitesseT=100);

	//******************************************************
	// Méthode: reculer
	// Rôle: Permet au robot de reculer sur une distance en
	//		 limitant ses risques de patinage
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot reculera
	//******************************************************
	void reculer(float distance,int vitesseT=100);

	//*********************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer
	//*********************************
	void avancer();

	//**********************************
	// Méthode: avancer
	// Rôle: Permet au robot de reculer
	//**********************************
	void reculer();
private:
	float coeffD; // Coefficient à appliquer à la distance
	float coeffV; // Coefficient à appliquer à la vitesse
};

