#pragma once
#include "Damier.h"
#include "Tourelle.h"
#include "Ralentisseur.h"
#include "Exterminateur.h"
#include <ctime>
#include "Asteroides.h"
#include "AsteroideMoyen.h"
#include "AsteroideGrand.h"
#include "Joueur.h"

class Environnement {
public:

	Environnement();
	virtual ~Environnement();
	void draw();
	void ajoutTourelle(float x , float y);
	void act();

	int demarrageJeu=0;
	int lancement = 0;
	int vague = 1;
	int objectif = vague * 100;
	std::list<Asteroides> asteroides;
	Damier *damier;
	Joueur *joueur ;
	float vitesse_attaque = 2.0f;
	long int time1 = time(0);
	long int time2;
};

