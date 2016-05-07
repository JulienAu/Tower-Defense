#pragma once

#include "Engine.h"
#include "Environnement.h"
#include "Tourelle.h"

class MyGameEngine:public GameEngine {

public:
    
    MyGameEngine(Environnement *env_):env(env_){}
    


    virtual void idle();
    
    Environnement *env;
};
