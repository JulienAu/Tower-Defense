
#include "MyGameEngine.h"


void MyGameEngine::idle(){
	if(env->demarrageJeu){
		if(env->joueur->vie > 0){
			env->act();
		}
	}
}
