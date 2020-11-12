//********************************************
// Auteur Vincent Riviere
// date : 12/11/2020
// fichier: RobotPekeeLedOn.h
// Interface de la classe permettant au robot 
// d'avancer avec sa led allum�e
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
	// M�thode: CRobotPekeeLedOn
	// R�le: Constructeur de la classe RobotPekeeLedOn qui initialise un robot
	//       qui peut avancer en allumant sa led
	// Param�tres d'entr�e:
	//		un_nom : Nom du robot
	//		une_adrIP : Adresse IP du robot
	// Param�tres de sortie :
	// 
	//*************************************************************************
	CRobotPekeeLedOn(string un_nom,string une_adrIP);
	
	//************************************************
	// M�thode: ~CRobotPekeeLedOn
	// R�le: Destructeur de la classe RobotPekeeLedOn
	//************************************************
	~CRobotPekeeLedOn(void);

	//********************************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer sur une distance et �
	//		 une vitesse d�finie tout en ayant sa led allum�e
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot avancera
	//********************************************************
	void avancer(float distance,int vitesseT=100);

	//********************************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer sur une distance et �
	//		 une vitesse d�finie tout en ayant sa led allum�e
	// Param�tres d'entr�e :
	//		distance : Distance parcourue par le robot
	//		vitesseT : Vitesse � laquelle le robot avancera
	//********************************************************
	void reculer(float distance,int vitesseT=100);

	//**************************************************************
	// M�thode: avancer
	// R�le: Permet au robot d'avancer tout en ayant sa led allum�e
	//**************************************************************
	void avancer();

	//***************************************************************
	// M�thode: avancer
	// R�le: Permet au robot de reculer tout en ayant sa led allum�e
	//***************************************************************
	void reculer();
};

