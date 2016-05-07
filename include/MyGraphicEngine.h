#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Environnement.h"
#include "Tourelle.h"


class MyGraphicEngine:public GraphicEngine {

public:
    
    MyGraphicEngine(Environnement *env_):env(env_){}


    virtual void Draw();
    
    Environnement *env;

};
