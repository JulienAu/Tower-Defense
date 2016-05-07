#pragma once
#include <ctime>
#include "Asteroides.h"

class AsteroideMoyen : public Asteroides {
public:

	AsteroideMoyen(float x, float y) : Asteroides(x , y , 0.0f, 0.0f , 1.0f ,2.0f , 0.01f ,200 , 1.4f ,2){};

	~AsteroideMoyen();
};



