#include "RobotPekee.h"
#include "RobotPekeeLedOn.h"
#include "RobotPekeeD.h"
#include "RobotPekeeSuivi.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main()
{
try
{
	// Allocation dynamique d'un seul robot car pas de polymorphisme pour CRobotSuivi
	int choixRobot=4;
	int pos=0;// Remplacer par 0
	/*
	loat coeffD=0.3,coeffV=0.3;
	// Creation d'un pointeur sur la classe mère afin d'utiliser le polymorphisme
	CRobotPekee *robot;

	// Choix du type de robot
	do
	{
		cout<<"Quel type de robot souhaitez-vous creer ?"<<endl;
		cout<<"1 - Robot classique"<<endl;
		cout<<"2 - Robot qui se deplace avec la led allumee"<<endl;
		cout<<"3 - Robot qui limite le patinage"<<endl;
		cout<<"4 - Robot dont la position est suivie"<<endl;
		cin>>choixRobot;
	}
	while(choixRobot<1 && choixRobot>4);
	switch(choixRobot)
	{
	case 1:
		{
			// Allocation dynamique d'un robot de type CRobotPekee
			robot = new CRobotPekee("Pekee","localhost");
		}
		break;
	case 2:
		{
			// Allocation dynamique d'un robot de type CRobotPekeeLedOn
			robot = new CRobotPekeeLedOn("Pekee","localhost");
		}
		break;
	case 3:
		{
			cout<<"Quels seront les coefficients de distance et de de vitesse du robot ?"<<endl;
			cout<<"Coefficient de distance :";
			cin>>coeffD;
			cout<<"Coefficient de vitesse :";
			cin>>coeffV;
			// Allocation dynamique d'un robot de type CRobotPekeeD
			robot = new CRobotPekeeD("Pekee","localhost",coeffD,coeffV);
		}
		break;
		case 4:
		{
			// Allocation dynamique d'un robot de type CRobotPekeeSuivi
			robot = new CRobotPekeeSuivi("Pekee","localhost");
		}
		break;
	default:
		{
			cout<<"Erreur dans la creation du robot"<<endl;	
		}
	}
	*/
	CRobotPekeeSuivi * robot = new CRobotPekeeSuivi("Pekee","localhost");
	cout << "Connexion avec le robot :" << endl;
	cout << "-------------------------" << endl;

	// Les méthodes du robot sont appelées de manière dynamique
	if (robot->estConnecte())
	{
		cout << "connexion avec le robot ok \n";
		
		int vitesseT=100;
		int vitesseA=45;
		int nbclign;
		int rep;
		float distance;
		float angle;
		float x,y,z;

	
	

	do
	{
		cout << "Commande du robot" << endl;
		cout << "**************************" << endl<< endl;

		cout << "Que doit faire le robot ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner a gauche  " << endl;
		cout << "4 - Tourner a droite" << endl;
		cout << "5 - Clignoter" << endl;
		cout << "6 - Avancer sur une distance" << endl;
		cout << "7 - Reculer sur une distance" << endl;
		cout << "8 - Tourner a gauche sur un angle" << endl;
		cout << "9 - Tourner a droite sur un angle" << endl;
		cout << "10 - Connaitre la position actuelle du robot" << endl;
		if(choixRobot=4)
		{
			cout << "11 - Connaitre une position specifique du parcours" << endl;
			cout << "12 - Connaitre toutes les positions du parcours" << endl;
		}
		cout << "0 - Fin commande du robot" <<endl;

		cin >> rep;

		switch (rep)
		{
			case 1 :		
						//  AVANCER
						robot->avancer();
						break;

			case 2 :	
						//  RECULER
						robot->reculer();
						break;

			case 3 :	
						//  TOURNER A GAUCHE
						robot->tournerG();
						break;

			case 4 :	
						//  TOURNER A DROITE
						robot->tournerD();
						break;

			case 5 :	
						// CLIGNOTER
						cout << "Combien de cligntements souhaitez vous ? :" <<endl;
						cin >> nbclign;
						robot->clignoter(nbclign);
						break;

			case 6 :	//  AVANCER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robot->avancer(distance,vitesseT);
						break;

			case 7 :	//  RECULER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robot->reculer(distance,vitesseT);
						break;

			case 8 :	//  TOURNER A GAUCHE sur une distance
						cout << "Quel angle de déplacement ? :" <<endl;
						cin >> angle;
						robot->tournerG(angle,vitesseA);
						break;

			case 9 :	//  TOURNER A DROITE sur une distance
						cout << "Quel angle de déplacement ? :" <<endl;
						cin >> angle;
						robot->tournerD(angle,vitesseA);
						break;

			case 10 :	//  Connaitre la position du robot
						robot->connaitrePosition(x,y,z);
						cout << "Les coordonnees actuelles du robot sont : x = "<< x << " y = "<< y << " angle = " << z << endl;
						break;

			case 11 :	// Connaitre une position spécifique du robot
						cout << "Quelle position souhaitez-vous connaitre ? "<< endl;
						cin >> pos;
						robot->connaitrePosition(x,y,z,pos-1);
						cout << "Les coordonnees du robot a la "<< pos <<"e position sont : x = "<< x << " y = "<< y << " angle = " << z << endl;
						break;
						
			case 12 :	// Connaitre toutes les positions du parcours du robot
						for(int i=0;i<robot->getParcoursSize();i++)
						{
							robot->connaitrePosition(x,y,z,i);
							cout << "Les coordonnees du robot a la "<< i+1 <<"e position sont : x = "<< x << " y = "<< y << " angle = " << z << endl;
						}
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
		robot->Disconnect();
		
			
	}
	else
	{
		cout << "probleme de connexion avec le robot  \n";
		cout << "pour sortir : appuyer sur une touche\n";

	}

	return 0 ;
}
catch(runtime_error & e)
{
	cout << e.what() << endl;
}
catch(out_of_range & e)
{
	cout << "Erreur : La position demandee n est pas enregistree" << endl;
}
}



















