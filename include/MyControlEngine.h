#pragma once
#include "Engine.h"
#include "Environnement.h"


class MyControlEngine:public ControlEngine {


public:
    MyControlEngine(Environnement *env_ ):env(env_){}
    

    virtual void MouseCallback(int button, int state, int x, int y) ;

    Environnement * env;
    int sommeMinimum = 100;
};
