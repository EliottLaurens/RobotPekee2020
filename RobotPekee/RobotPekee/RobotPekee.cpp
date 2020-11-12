#include "RobotPekee.h"
#include <iostream>
using namespace std;



CRobotPekee::CRobotPekee(string un_nom,string une_adrIP):position(0,0,0)
{
	this->nom = un_nom;
	this->adresseIP = une_adrIP;

	char adr[16];
	strcpy(adr,this->adresseIP.c_str());
	char n[10];
	strcpy(n,this->nom.c_str());

	this->connexion = this->Connect(adr,n);
}


CRobotPekee::~CRobotPekee(void)
{
	if(this->connexion==true)
	{
		this->Disconnect();
	}
	this->connexion=false;
}

bool CRobotPekee::estConnecte()
{
	return this->connexion;
}

void CRobotPekee::avancer()
{
	float x,y,angle;
	this->ResetPosition();
	this->SetSpeed(100,0);
	this->GetPosition(x,y,angle);
	position.deplacer(x);
}

void CRobotPekee::reculer()
{
	float x,y,angle;
	this->ResetPosition();
	this->SetSpeed(-100,0);
	this->GetPosition(x,y,angle);
	position.deplacer(-x);
}

void CRobotPekee::tournerG()
{
	float x,y,angle;
	this->ResetPosition();
	this->SetSpeed(0,-90);
	this->GetPosition(x,y,angle);
	position.orienter(angle);
}

void CRobotPekee::tournerD()
{
	float x,y,angle;
	this->ResetPosition();
	this->SetSpeed(0,90);
	this->GetPosition(x,y,angle);
	position.orienter(angle);
}

void CRobotPekee::clignoter(int nbclign)
{
	for(int i = 0; i <= nbclign;i++)
	{
		this->LedOn();
		Sleep(500);
		this->LedOff();
		Sleep(500);
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
	position.deplacer(x);
}

void CRobotPekee::reculer(float distance,int vitesseT)
{
	float x,y,angle;
	x=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(-vitesseT,0);
		this->GetPosition(x,y,angle);

	}while(-distance < x);
	position.deplacer(-x);
}

void CRobotPekee::tournerG(float distance,int vitesseA)
{
	float x,y,angle;
	angle=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(0,-vitesseA);
		this->GetPosition(x,y,angle);

	}while((-1)*distance > angle);
	position.orienter(angle);
}

void CRobotPekee::tournerD(float distance,int vitesseA)
{
	float x,y,angle;
	angle=0;
	this->ResetPosition();
	do
	{
		this->SetSpeed(0,vitesseA);
		this->GetPosition(x,y,angle);

	}while(distance > angle);
	position.orienter(angle);
}

void CRobotPekee::afficherPosition(float &x,float &y)
{
	position.coordonnees(x,y);
}