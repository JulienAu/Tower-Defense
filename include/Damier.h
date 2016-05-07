#pragma once
#include "Engine.h"
#include "Tourelle.h"

class Damier {
public:
	Damier();
	virtual ~Damier();


    float hauteur_case = 0.2f;
    float largeur_case = 0.2f;
    int nombre_lignes = 8;
    int nombre_colonnes = 10;
    void draw();
    void tick();
    void act();
    void tourelleDetruite(int x);
    Tourelle ** tours;
};
