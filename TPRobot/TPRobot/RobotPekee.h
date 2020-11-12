#pragma once
#include "c:\wany\maeva2004\oxygen\pekeev1\c++\includes\librobotpekee.h"
#include "Position.h"
#include <string>
using namespace std;
class CRobotPekee :
	public WRobotPekee
{
public:
	CRobotPekee(string un_nom, string une_adrIP);
	~CRobotPekee(void);
	bool estConnecte();
	virtual void avancer();
	virtual void reculer();
	void tournerG();
	void tournerD();
	void clignoter(int nbclign);
	virtual void avancer(float distance,int vitesseT=100);
	virtual void reculer(float distance,int vitesseT=100);
	void tournerG(float angle,int vitesseA=45);
	void tournerD(float angle,int vitesseA=45);
	void connaitrePosition(float &x, float &y);

private:
	string nom;
	string adresseIP;
	bool connexion;
	CPosition position;
};

