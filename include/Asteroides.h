#pragma once
#include <ctime>
#include "Joueur.h"



class Asteroides {
public:
	Asteroides(float x, float y, float r_, float g_, float b_, float fr_, float vd_ , int vie_ , float size_, int type_) :
		posX(x),
		posY(y),
		r(r_),
		g(g_),
		b(b_),
		frequence(fr_),
		vitesse_deplacement(vd_),
		vie(vie_),
		size(size_),
		type(type_){};
	~Asteroides();
	void act();
	void draw();
	void setPosX(float x);
	int getType();
	void gain(Joueur *joueur);
	bool atteint(int p , int t);
	float size ;
	int vie ;
	float frequence;
	float vitesse_deplacement;
	float posX;
	float posY;
	float r;
	float g;
	float b;
	long int time1 = time(0);
	long int time2;
	int type;

};

