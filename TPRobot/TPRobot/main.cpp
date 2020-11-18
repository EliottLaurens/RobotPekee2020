#include "RobotPekee.h"
#include "RobotPekeeLedOn.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	CRobotPekeeLedOn robot("Pekee","localhost");
	cout << "Connexion avec le robot :" << endl;
	cout << "-------------------------" << endl;

	// Les méthodes du robot sont appelées de manière dynamique
	if (robot.estConnecte())
	{
		cout << "connexion avec le robot ok \n";
		
		int vitesseT=100;
		int vitesseA=45;
		int nbclign;
		int rep;
		float distance;
		float angle;
		float x,y;

	
	

	do
	{
		cout << "Commande du robot" << endl;
		cout << "**************************" << endl<< endl;

		cout << "Que doit faire le robot ?" << endl;
		cout << "1 - Avancer" << endl;
		cout << "2 - Reculer" << endl;
		cout << "3 - Tourner à gauche  " << endl;
		cout << "4 - Tourner à droite" << endl;
		cout << "5 - Clignoter" << endl;
		cout << "6 - Avancer sur une distance" << endl;
		cout << "7 - Reculer sur une distance" << endl;
		cout << "8 - Tourner a gauche sur un angle" << endl;
		cout << "9 - Tourner a droite sur un angle" << endl;
		cout << "10 - Connaitre la position du robot" << endl;


		
		cout << "0 - Fin commande du robot" <<endl;

		cin >> rep;

		switch (rep)
		{
			case 1 :		
					//  AVANCER
					robot.avancer();
					break;
			case 2 :	
					//  RECULER
					robot.reculer();
					break;
					
						
			case 3 :	
					//  TOURNER A GAUCHE
					robot.tournerG();
					break;

			case 4 :	
					//  TOURNER A DROITE
					robot.tournerD();
					break;

			case 5 :	
					// CLIGNOTER
					cout << "Combien de cligntements souhaitez vous ? :" <<endl;
					cin >> nbclign;
					robot.clignoter(nbclign);
					break;

			case 6 :	//  AVANCER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robot.avancer(distance,vitesseT);
						break;
			case 7 :	//  RECULER sur une distance
						cout << "Quelle distance de déplacement ? :" <<endl;
						cin >> distance;
						robot.reculer(distance,vitesseT);
						break;

			case 8 :	//  TOURNER A GAUCHE sur une distance
						cout << "Quel angle de déplacement ? :" <<endl;
						cin >> angle;
						robot.tournerG(angle,vitesseA);
						break;

			case 9 :	//  TOURNER A DROITE sur une distance
						cout << "Quel angle de déplacement ? :" <<endl;
						cin >> angle;
						robot.tournerD(angle,vitesseA);
						break;

			case 10 :	//  Connaitre la position du robot
						robot.connaitrePosition(x,y);
						cout << "Les coordonnees du robot sont : x = "<< x << " y = "<< y << endl;
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




















