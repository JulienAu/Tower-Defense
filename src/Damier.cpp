
#include "Damier.h"
#include <stdio.h>
#include "GraphicPrimitives.h"
#include <iostream>

Damier::Damier() {
	tours = new Tourelle * [nombre_colonnes * nombre_lignes];
	for (int i = 0; i < nombre_lignes; i++) {
		for (int j = 0; j < nombre_colonnes; j++){
			tours[i * nombre_colonnes + j] = NULL;
		}
	}

}

Damier::~Damier() {
	// TODO Auto-generated destructor stub
}

void Damier::draw(){
	for(int x = 0; x < nombre_colonnes; x++){
		for(int y = 0 ; y < nombre_lignes ; y++ ){
			if ((x % 2 == 0) & (y % 2 == 0)){
				GraphicPrimitives::drawFillRect2D(-1.0f + (x * hauteur_case) ,-1.0f + (y * largeur_case) ,largeur_case,hauteur_case,0.0f,0.0f,0.0f);
			}
			else if ((x % 2 == 1) & (y % 2 == 0)){
				GraphicPrimitives::drawFillRect2D(-1.0f + (x * hauteur_case) ,-1.0f + (y * largeur_case) ,largeur_case,hauteur_case,1.0f,0.99f,1.0f);
			}
			else if ((x % 2 == 0) & (y % 2 == 1)){
							GraphicPrimitives::drawFillRect2D(-1.0f + (x * hauteur_case) ,-1.0f + (y * largeur_case) ,largeur_case,hauteur_case,1.0f,0.99f,1.0f);
						}
			else {
					GraphicPrimitives::drawFillRect2D(-1.0f + (x * hauteur_case) ,-1.0f + (y * largeur_case) ,largeur_case,hauteur_case,0.0f,0.0f,0.0f);
						}

		}
	}
	for (int i = 0; i < nombre_lignes; i++) {
		for (int j = 0; j < nombre_colonnes; j++){
			Tourelle * tmp = tours[i * nombre_colonnes + j];
			if (tmp != NULL) {
				tmp->draw();
			}
		}
	}


}

void Damier::act(){
	for (int i = 0; i < nombre_lignes; i++) {
		for (int j = 0; j < nombre_colonnes; j++){
			Tourelle * tmp = tours[i * nombre_colonnes + j];
			if (tmp != NULL) {
				tmp->act();
			}
		}
	}
}

void Damier::tourelleDetruite(int x){
	tours[x]->~Tourelle();
	tours[x]= NULL;
}


