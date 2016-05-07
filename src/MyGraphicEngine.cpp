
#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
	if(env->demarrageJeu){
		if(env->joueur->vie > 0){
			env->draw();
		}else{
			char str1[50];
		    env->joueur->affichage(str1,"Votre Score Final est de : ",env->joueur->score);
			GraphicPrimitives::drawText2D(str1, -0.25f , -0.25f , 1.0f , 1.0f ,0.99f);
			GraphicPrimitives::drawText2D("GAME OVER" , -0.1f , 0.00f , 1.0f , 1.0f ,0.99f);

		}
	} else {
		GraphicPrimitives::drawText2D("Bienvenue dans ce Jeu , voici les regles :" , -0.4f , 0.9f , 1.0f , 1.0f ,0.0f);
		GraphicPrimitives::drawText2D(" - Vous devez survivre au differentes vagues d'asteroides" , -0.90f , 0.75f , 1.0f , 1.0f ,0.0f);
		GraphicPrimitives::drawText2D(" - Vous avez 3 equipement differents pour vous defendre" , -0.90f , 0.65f , 1.0f , 1.0f ,0.0f);
		GraphicPrimitives::drawText2D(" - Interdit de Defendre dans les 3 dernieres colonnes du Damier" , -0.90f , 0.55f , 1.0f , 1.0f ,0.0f);
		GraphicPrimitives::drawText2D(" - Voici vos Vaisseaux :" , -0.90f , 0.45f , 1.0f , 1.0f ,0.0f);
		GraphicPrimitives::drawText2D("Ralentisseur : ", -0.90f , 0.30f , 0.30f , 0.0f, 1.0f );
		GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.35f , -0.45f, 0.30f,-0.55f, 0.25f, 0.30f , 0.0f, 1.0f );
		GraphicPrimitives::drawText2D(" Prix : 250$    Il permet de ralentir les asteroides", -0.35f , 0.30f , 0.30f , 0.0f, 1.0f );
		GraphicPrimitives::drawText2D("Tourelle",  -0.90f , 0.15f , 1.0f , 0.5f, 0.3f  );
		GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.20f , -0.45f, 0.15f,-0.55f, 0.10f, 1.0f , 0.5f, 0.3f );
		GraphicPrimitives::drawText2D("Prix 100$    Il tire a grande cadence et inflige de faible degats", -0.35f , 0.15f , 01.0f , 0.5f, 0.3f );
		GraphicPrimitives::drawText2D("Exterminateur",  -0.90f , 0.0f, 0.0f , 1.0f, 0.3f );
		GraphicPrimitives::drawFillTriangle2D(-0.55f, 0.05f , -0.45f, 0.0f,-0.55f, -0.05f, 0.0f , 1.0f, 0.3f );
		GraphicPrimitives::drawText2D("Prix 500$    Il tire a faible cadence et inflige de gros degats", -0.35f , 0.0f , 0.0f , 1.0f, 0.3f );

		GraphicPrimitives::drawText2D(" Que la force soit avec vous ! Bon courage !  " , -0.40f , -0.40f , 1.0f , 1.0f ,0.0f);

		GraphicPrimitives::drawText2D("(Clique droit pour continuer) " , 0.4f , -0.9f , 1.0f , 0.0f ,0.0f);



	}
}

