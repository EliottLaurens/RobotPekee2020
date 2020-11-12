//********************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeLedOn.h
// Interface de la classe permettant au robot 
// d'avancer avec sa led allumée
// Historique :
//********************************************
#pragma once
#include "robotpekee.h"
#include <string>
class CRobotPekeeLedOn :
	public CRobotPekee
{
public:
	
	//*************************************************************************
	// Méthode: CRobotPekeeLedOn
	// Rôle: Constructeur de la classe RobotPekeeLedOn qui initialise un robot
	//       qui peut avancer en allumant sa led
	// Paramètres d'entrée:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	// Paramètres de sortie :
	// 
	//*************************************************************************
	CRobotPekeeLedOn(string un_nom,string une_adrIP);
	
	//************************************************
	// Méthode: ~CRobotPekeeLedOn
	// Rôle: Destructeur de la classe RobotPekeeLedOn
	//************************************************
	~CRobotPekeeLedOn(void);

	//********************************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer sur une distance et à
	//		 une vitesse définie tout en ayant sa led allumée
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot avancera
	//********************************************************
	void avancer(float distance,int vitesseT=100);

	//********************************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer sur une distance et à
	//		 une vitesse définie tout en ayant sa led allumée
	// Paramètres d'entrée :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse à laquelle le robot avancera
	//********************************************************
	void reculer(float distance,int vitesseT=100);

	//**************************************************************
	// Méthode: avancer
	// Rôle: Permet au robot d'avancer tout en ayant sa led allumée
	//**************************************************************
	void avancer();

	//***************************************************************
	// Méthode: avancer
	// Rôle: Permet au robot de reculer tout en ayant sa led allumée
	//***************************************************************
	void reculer();
};

