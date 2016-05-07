#pragma once
#include <string.h>

class Joueur {
public:
	Joueur(int v_ , int a_):vie(v_),argent(a_){};
	virtual ~Joueur();

	void setArgent(int x);
	void setVie(int x);
	void setScore(int x);
	void draw();
	void affichage(char s[],char * str,int n);

	int argent;
	int vie;
	int score =0;
	float posX=0.00f;
};

