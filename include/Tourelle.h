#pragma once
#include <list>
#include <sys/time.h>
#include <ctime>


class Tourelle {

public:

	Tourelle(float x, float y, float r_, float g_, float b_, float vit_att , float vit_proj , int puissance_, int type_) :
		posX(x + 0.05f),
		posY(y + 0.1f),
		vitesse_attaque(vit_att),
		vitesse_projectile(vit_proj),
		type(type_),
		puissance(puissance_),
		r(r_),
		g(g_),
		b(b_){}
	virtual ~Tourelle();
	void draw();
	void act();
	void cibleAtteinte();
	void toucher();

	float posX;
	float posY;
	float r;
	float g;
	float b;
	float length = 0.1f;
	std::list<float> projectiles;
	long int time1 = time(0);
	long int time2;
	float vitesse_attaque;
	float vitesse_projectile;
	int puissance;
	int vie_tourelle = 1;
	int type;

};
