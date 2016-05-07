
#include <iostream>
#include "Engine.h"
#include "Environnement.h"
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"
#include "Joueur.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc,argv);

    Environnement * environnement = new Environnement();

    
    GraphicEngine * ge = new MyGraphicEngine(environnement);
    GameEngine * gme = new MyGameEngine(environnement);
    ControlEngine * ce = new MyControlEngine(environnement);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}
