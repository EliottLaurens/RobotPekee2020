#include "RobotPekee.h"
#include <iostream>
#include <stdexcept>
using namespace std;


CRobotPekee::CRobotPekee(string un_nom,string une_adrIP):position(0,0,0)
{
	this->nom=un_nom;
	this->adresseIP=une_adrIP;
	char *adr = new char[this->adresseIP.length() + 1];
	strcpy(adr, this->adresseIP.c_str());
	char *n = new char[this->nom.length() + 1];
	strcpy(n, this->nom.c_str());
	if(this->Connect(adr,n))
	{
		this->connexion=true;
	}
	else
	{
		throw runtime_error("Erreur : La connexion a echoue");
	}
	delete [] adr;
	delete [] n;

}


CRobotPekee::~CRobotPekee(void)
{
	if(this->connexion)
	{
		this->Disconnect();
	}	
}

bool CRobotPekee::estConnecte()
{
	return this->connexion;
}

void CRobotPekee::avancer()
{
	this->SetSpeed(100,0);
}

void CRobotPekee::reculer()
{
	this->SetSpeed(-100,0);
}

void CRobotPekee::tournerG()
{
	this->SetSpeed(0,-90);
}

void CRobotPekee::tournerD()
{
	this->SetSpeed(0,90);
}

void CRobotPekee::clignoter(int nbclign)
{
	if(nbclign>0)
	{
		for(int i=1;1<nbclign;i++)
		{
			this->LedOn();
			Sleep(500);
			this->LedOff();
			Sleep(500);
		}
		this->LedOn();
		Sleep(500);
		this->LedOff();
	}
}

void CRobotPekee::avancer(float distance,int vitesseT)
{
	float x,y,angle;
	x=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(vitesseT,0);
		this->GetPosition(x,y,angle);

	}while(distance > x);
	position.deplacer(distance);
}

void CRobotPekee::reculer(float distance,int vitesseT)
{
	float x,y,angle;
	x=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed((-1)*vitesseT,0);
		this->GetPosition(x,y,angle);

	}while((-1)*distance < x);
	position.deplacer(-distance);
}

void CRobotPekee::tournerG(float angle,int vitesseA)
{
	float x,y,a;
	a=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(0,(-1)*vitesseA);
		this->GetPosition(x,y,a);

	}while((-1)*angle < a);
}

void CRobotPekee::tournerD(float angle, int vitesseA)
{
	float x,y,a;
	a=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(0,vitesseA);
		this->GetPosition(x,y,a);

	}while(angle > a);
}

void CRobotPekee::connaitrePosition(float &x, float &y, float &z, int i)
{
	this->position.coordonnees(x,y);
	z=this->position.orientation();


}

