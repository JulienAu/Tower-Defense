#include "Tourelle.h"
#include "MyControlEngine.h"


void MyControlEngine::MouseCallback(int button, int state, int x, int y){
	if(env->demarrageJeu){
		if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
			if(((y-300)/ -300.f) >= 0.6f){
				if(((x-400) / 400.f) <= 0.1f){
					if(((x-400) / 400.f) >= -0.22f){
						env->joueur->posX = 0.0f;
						sommeMinimum = 100;
					}else{
						env->joueur->posX = -0.30f;
						sommeMinimum = 250;
					}
				}else{
					env->joueur->posX = 0.40f;
					sommeMinimum = 500;
				}
			}
			else if(((env->joueur->argent >= sommeMinimum) && ((x-400) / 400.f) <= 0.4f)){
				env->ajoutTourelle((x-400) / 400.f , (y-300)/ -300.f);
			}
		}

		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			env->lancement=1;
		}
	} else {
		if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
			env->demarrageJeu=1;
		}
	}
}

