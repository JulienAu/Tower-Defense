#pragma once
#include <ctime>
#include "Asteroides.h"

class AsteroideGrand : public Asteroides {
public:

	AsteroideGrand(float x, float y) : Asteroides(x , y , 0.0f, 1.0f , 0.0f ,2.0f , 0.004f ,550 , 1.8f , 3){};

	~AsteroideGrand();

};
