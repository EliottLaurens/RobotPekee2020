//***********************************************************************
// Date : 09/09/2020		Auteur : MP Pinaud
// Nom du fichier : PilotagePekee.cpp
// Rôle : Pilotage à distance du robot Pekee avec des commandes simples
//**********************************************************************


#include <iostream>
using namespace std;

#include "libRobotPekee.h"
#include "RobotPekee.h"






//**********************************************************************
// Fonction : main
// Rôle : se connecter au robot et le commander
//**********************************************************************

int main(void)
{
	CRobotPekee robot ("pekee","localhost");
	int rep;
	int nbclign;
	float distance;
	bool connecter;
	int vitesse;
	float x,y;
	do
	{
	cout << "Commande du robot" << endl;
	cout << "**************************" << endl<< endl;
	cout << "Que doit faire le robot ?" << endl;
	cout << "1 - es que le robot est connecte ?" << endl;
	cout << "2 - Avancer" << endl;
	cout << "3 - Reculer" << endl;
	cout << "4 - Tourner à gauche  " << endl;
	cout << "5 - Tourner à droite" << endl;
	cout << "6 - clignoter" << endl;
	cout << "7 - Avancer sur une distance" << endl;
	cout << "8 - Reculer sur une distance" << endl;
	cout << "9 - Tourner à gauche sur une distance" << endl;
	cout << "10 - Tourner à droite sur une distance" << endl;
	cout << "11 - Afficher la position" << endl;

	cin >> rep;
	switch (rep)
	{
		case 1 :		
			//  Es que le robot est connecte ?
			connecter = robot.estConnecte();
			if (connecter == true)
			{
				cout << "connexion avec le robot ok \n";
			}
			else
			{
				cout << "connexion avec le robot pas ok \n";
			}
			break;
		case 2 :		
			//  AVANCER
			robot.avancer();
			break;
		case 3 :	
			//  RECULER
			robot.reculer();
			break;
					
						
		case 4 :	
			//  TOURNER A GAUCHE
			robot.tournerG();;
			break;

		case 5 :	
			//  TOURNER A DROITE
			robot.tournerD();
			break;

		case 6 :	
			// Clignoter
			cout << "Nombre de clignotement" <<endl;
			cin >> nbclign;
			robot.clignoter(nbclign);
			break;

		case 7 :	
			//  AVANCER sur une distance a une vitesse
			cout << "Quelle distance de déplacement ? :" <<endl;
			cin >> distance;
			cout << "Quelle vitesse de déplacement ? :" <<endl;
			cin >> vitesse;
			robot.avancer(distance,vitesse);
			break;
		case 8 :	
			//  RECULER sur une distance a une vitesse
			cout << "Quelle distance de déplacement ? :" <<endl;
			cin >> distance;
			cout << "Quelle vitesse de déplacement ? :" <<endl;
			cin >> vitesse;
			robot.reculer(distance,vitesse);
			break;
		case 9 :	
			//  Tourner à gauche sur une distance
			cout << "Quelle radian de rotation ? :" <<endl;
			cin >> distance;
			cout << "Quelle vitesse de rotation ? :" <<endl;
			cin >> vitesse;
			robot.tournerG(distance,vitesse);
			break;
		case 10 :	
			//  Tourner à droite sur une distance
			cout << "Quelle radian de rotation ? :" <<endl;
			cin >> distance;
			cout << "Quelle vitesse de rotation ? :" <<endl;
			cin >> vitesse;
			robot.tournerD(distance,vitesse);
			break;
		case 11 :
			// Afficher la position
			robot.afficherPosition(x,y);
			cout << "x = " << x <<" y = "<< y <<endl;
			break;
			
		default :	cout << "Erreur de saisie" <<endl;
						break;
		} 
	} while (rep != 0);
			
						
	
	// Déconnexion au robot
	robot.Disconnect();
		
			
	
	

	return 0 ;
}



