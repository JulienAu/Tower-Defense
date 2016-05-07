#include <list>
#include <sys/time.h>
#include "Tourelle.h"
#include "GraphicPrimitives.h"


Tourelle::~Tourelle() {
	// TODO Auto-generated destructor stub
}


void Tourelle::draw() {
	GraphicPrimitives::drawFillTriangle2D(posX, posY + 0.5 * length, posX + length, posY, posX, posY - 0.5 * length, r, g, b);
	for (std::list<float>::iterator project = projectiles.begin(); project != projectiles.end(); project++) {
		if(type == 1){
			GraphicPrimitives::drawFillRect2D(*project, posY, 0.02f, 0.02f, 0.01f, 0.30f, 0.8f);

		}else if(type == 2){
			GraphicPrimitives::drawFillRect2D(*project, posY - 0.025f, 0.05f, 0.05f, 0.0f , 1.0f, 0.5f );

		}
		else{
			GraphicPrimitives::drawFillRect2D(*project, posY, 0.02f, 0.02f, 1.0f, 0.25f, 0.01f);
		}
	}
}

void Tourelle::act() {
	struct timeval tp2;
	gettimeofday(&tp2, NULL);
	time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
	if ((time2 - time1) > (vitesse_attaque * 1000000)) {
	projectiles.push_front(posX + length);
	struct timeval tp1;
			gettimeofday(&tp1, NULL);
			time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
		}
	for (std::list<float>::iterator project = projectiles.begin(); project != projectiles.end(); project++) {
		*project = *project + vitesse_projectile;
	}
	if (projectiles.back() > 1.0f) {
		projectiles.pop_back();
	}
}

void Tourelle::toucher(){
	vie_tourelle = vie_tourelle - 1;
}

