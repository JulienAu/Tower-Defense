#include <sys/time.h>
#include "GraphicPrimitives.h"
#include "Asteroides.h"

Asteroides::~Asteroides(){};

void Asteroides::draw() {
	GraphicPrimitives::drawFillRect2D(posX , posY ,0.04f * size,0.06f *size, r, g, b);
	//GraphicPrimitives::drawFillPolygone2D()(posX , posY ,0.04f * size,0.06f *size, r, g, b);

}

void Asteroides::act() {
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
	if ((time2 - time1) > (frequence * 1000000)) {
	struct timeval tp1;
			gettimeofday(&tp1, NULL);
			time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
		}
	posX = posX - vitesse_deplacement;

	if ((vie <= 0)) {
		this->~Asteroides();
	}
}

void Asteroides::setPosX(float x){
	posX = posX - x ;
}

int Asteroides::getType(){
	return type;
}

bool Asteroides::atteint(int puissance , int type_){
	if(type_ == 1){
		vitesse_deplacement = vitesse_deplacement * 0.7;
	}else {
		if(type == 1){
			size = size * 0.7 ;
			posY = posY + 0.01f;
			vie = vie - puissance;
		} else if(type == 2){
			size = size * 0.8 ;
			posY = posY + 0.006f;
			vie = vie - puissance;
		} else {
			size = size * 0.9 ;
			posY = posY + 0.003f;
			vie = vie - puissance;
		}
	}
	return vie<=0;
}

void Asteroides::gain(Joueur *joueur){
	if(type == 1){
		joueur->setArgent(75);
		joueur->setScore(20);
	}else if(type == 2){
		joueur->setArgent(150);
		joueur->setScore(40);
	}
	else {
		joueur->setArgent(300);
		joueur->setScore(80);
	}
}


