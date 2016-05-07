#pragma once
#include "Tourelle.h"

class Exterminateur : public Tourelle{
public:
	Exterminateur(float x , float y):Tourelle(x ,y, 0.0f , 1.0f, 0.3f , 4.0f, 0.005f, 200, 2){};
	virtual ~Exterminateur();
};


