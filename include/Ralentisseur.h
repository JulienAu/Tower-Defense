#pragma once
#include "Tourelle.h"


class Ralentisseur : public Tourelle{
public:
	Ralentisseur(float x , float y):Tourelle(x ,y, 0.30f , 0.0f, 1.0f , 1.7f, 0.02f ,0,1){};
	virtual ~Ralentisseur();
};

