//***********************************************************************
// Date : 09/09/2020		Auteur : MP Pinaud
// Nom du fichier : PilotagePekee.cpp
// Rôle : Pilotage à distance du robot Pekee avec des commandes simples
//**********************************************************************


#include <iostream>
using namespace std;

#include "libRobotPekee.h"



//***********************************************************************
// Déclaration des fonctions
//**********************************************************************

void avancer_robot(WRobotPekee &robot, float vitesse, float distance);
void reculer_robot(WRobotPekee &robot, float vitesse, float distance);


//*********************************************************************




//**********************************************************************
// Fonction : main
// Rôle : se connecter au robot et le commander
//**********************************************************************

{
	WRobotPekee robot;  // 
int main(void)Instance de WRobotPekee
	bool connecte=false;  // indique si la connexion avec le robot est faite
	// Connexion au robot simulé

	
	cout << "Connexion avec le robot :" << endl;
	cout << "-------------------------" << endl;

	connecte = robot.Connect("localhost", "Pekee");

	if (connecte)
	{
		cout << "connexion avec le robot ok \n";
		
		wint16	vitesse = 100 ,	// vitesse de translation en mm/s
		vrotation  = 45   ; 	// vitesse de rotation en degre/s;

		float distance;    // distance du déplacement

		int rep;		// choix de l'utilisateur

	
	

	do
	{
		cout << "Commande du robot" << endl;
		cout << "**************************" << endl<< endl;

		cout << "Que doit faire le robot ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner à gauche  " << endl;
		cout << "4 - Tourner à droite" << endl;
		cout << "5 - Allumer la led" << endl;
		cout << "6 - Eteindre la led" << endl;
		cout << "7 - Avancer sur une distance" << endl;
		cout << "8 - Reculer sur une distance" << endl;

		
		cout << "0 - Fin commande du robot" <<endl;

		cin >> rep;

		switch (rep)
		{
			case 1 :		
					//  AVANCER
					robot.SetSpeed(vitesse,0);
					break;
			case 2 :	
					//  RECULER
					robot.SetSpeed((-1)*vitesse,0);
					break;
					
						
			case 3 :	
					//  TOURNER A GAUCHE
					robot.SetSpeed(0,-90);
					break;

			case 4 :	
					//  TOURNER A DROITE
					robot.SetSpeed(0,90);
					break;

			case 5 :	
					// ALLUMER LA LED
					robot.LedOn();
					break;
			
			case 6 :	
					//  ETEINDRE LA LED
					robot.LedOff();
					break;

			case 7 :	//  AVANCER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						avancer_robot(robot, vitesse, distance);
						break;
			case 8 :	//  RECULER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						reculer_robot(robot, vitesse, distance);
						break;
			case 0 :	
						{
							cout << "Fin commande du robot" <<endl;
							cout << "*********************" << endl;
							break;
						}
			default :	cout << "Erreur de saisie" <<endl;
						break;
		} 
	} while (rep != 0);
			
						
	
		// Déconnexion au robot
		robot.Disconnect();
		
			
	}
	else
	{
		cout << "probleme de connexion avec le robot  \n";
		cout << "pour sortir : appuyer sur une touche\n";

	}

	return 0 ;
}



//**********************************************************************
// Fonction : avancer_robot
// Rôle : avance le robot 
// Entrées :	robot : robot à piloter
//				vitesse : vitesse de déplacement
//				distance : distance à parcourir
//**********************************************************************	
void avancer_robot(WRobotPekee &robot,float vitesse, float distance)
{
	float x,y,angle;
	x=0;
	robot.ResetPosition();
	do
	{
		robot.SetSpeed(vitesse,0);
		robot.GetPosition(x,y,angle);

	}while(distance > x);
}

//**********************************************************************
// Fonction : reculer_robot
// Rôle : recule le robot 
// Entrées :	robot : robot à piloter
//				vitesse : vitesse de déplacement
//				distance : distance à parcourir
//**********************************************************************	
void reculer_robot(WRobotPekee &robot,float vitesse, float distance)
{
	float x,y,angle;
	x=0;
	robot.ResetPosition();
	do
	{
		robot.SetSpeed((-1)*vitesse,0);
		robot.GetPosition(x,y,angle);

	}while((-1)*distance < x);
}