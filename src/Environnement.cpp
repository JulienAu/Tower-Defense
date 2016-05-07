#include "Environnement.h"
#include <list>
#include <algorithm>


Environnement::Environnement(){
	damier = new Damier;
	joueur=new Joueur(3 , 500);
}

Environnement::~Environnement() {
	// TODO Auto-generated destructor stub
}


void Environnement::ajoutTourelle(float x , float y){
	int px = (int)(x / damier->largeur_case + 5);
	int py = (int)(y / damier->hauteur_case + 5);
	if(damier->tours[px + py*10] == NULL){
		if(joueur->posX < 0.0f){
			damier->tours[px + py*10]= new Ralentisseur (-1.0f + (px * damier->hauteur_case) ,-1.0f + (py * damier->largeur_case));
			joueur->setArgent(-250);
		} else if(joueur->posX > 0.0f){
			damier->tours[px + py*10]= new Exterminateur (-1.0f + (px * damier->hauteur_case) ,-1.0f + (py * damier->largeur_case));
			joueur->setArgent(-500);
		} else{
			damier->tours[px + py*10]= new Tourelle (-1.0f + (px * damier->hauteur_case) ,-1.0f + (py * damier->largeur_case) , 1.0f , 0.5f, 0.3f , 1.0f, 0.01f , 50, 0 );
			joueur->setArgent(-100);
		}
	}
}


void Environnement::draw(){
	char str1[50];
	joueur->affichage(str1,"Vague : ",vague);
	GraphicPrimitives::drawText2D(str1, 0.60f , 0.90f , 0.0f , 0.0f ,0.99f);
	damier->draw();
	joueur->draw();
	for (std::list<Asteroides>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
				astero->draw();
		}
	if (!lancement){
		GraphicPrimitives::drawText2D("Clique Droit pour lancer la Vague Suivante", -0.50f , -0.10f , 1.0f , 0.0f ,0.0f);
	}
}

void Environnement::act(){
	/*Changement de Vague*/
	if((joueur->score >= objectif)){
		vague += 1;
		if(vague <= 5){
			vitesse_attaque = 2.0f / (vague * 0.50);
		} else {
		vitesse_attaque = 2.0f / (vague * 0.25);
		}
		objectif = vague * vague * 20 + joueur->score + 100;
		lancement=0;
	}

	if(lancement){
		/* Création des Astéroides */
		struct timeval tp2;
		gettimeofday(&tp2, NULL);
		time2 = tp2.tv_sec * 1000000 + tp2.tv_usec;
		if ((time2 - time1) > (vitesse_attaque * 1000000)) {
			/*Choisi aleatoirement la ligne de l'asteroide*/
			float posY = -1.0f + ((rand() % 8) - 1) * damier->hauteur_case + ((damier->hauteur_case/2) + 0.17f);

			/*Permet d'augmenter la probabilités des asteroides difficiles au fil des vagues*/
			int frequence = (rand() % 15) ;
			if((frequence <= vague) && (vague > 2)){
				int frequence2 = (rand() % 15) ;
				if(frequence2 <= vague){
					asteroides.push_front(AsteroideGrand(1.0f , posY));
				} else {
					asteroides.push_front(AsteroideMoyen(1.0f , posY));
				}
			} else {
				asteroides.push_front(Asteroides(1.0f , posY , 1.0f , 0.5f , 0.3f , 1.0f , 0.003f , 100 , 1 , 1));
			}
			struct timeval tp1;
			gettimeofday(&tp1, NULL);
			time1 = tp1.tv_sec * 1000000 + tp1.tv_usec;
		}
	}


/* Collision asteroides , projectiles et tourelles*/

	for (std::list<Asteroides>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
		int py = (int)(astero->posY / damier->hauteur_case + 5);
		int px = (int)(astero->posX / damier->largeur_case + 5);

		for(int x = 0 ; x < px ; x++){
			if(damier->tours[x + py *10] != NULL){
				float projectile = damier->tours[x + py *10]->projectiles.back();
				/* Pour chaque tourelle sur la ligne , verification si un projectile atteint l'asteroide */
				if((astero->posX <= projectile)&&(((projectile > 0.001f)&&(projectile < 1.0f))||((projectile < -0.001f)&&(projectile > -1.0f)))){
					if(damier->tours[x + py *10]->projectiles.size() != 0){
						damier->tours[x + py *10]->projectiles.pop_back();
					}
					if(astero->atteint(damier->tours[x + py *10]->puissance , damier->tours[x + py *10]->type )){
						astero->gain(joueur);
						astero=asteroides.erase(astero);
						break;
					}
				}
			}
		}
		/* Verification si l'asteroide a reussi a atteindre la tourelle */
		if((damier->tours[px + py *10] != NULL)&&(px < 10)){
			damier->tours[px + py * 10]->toucher();
			if(damier->tours[px + py * 10]->vie_tourelle == 0){
				damier->tourelleDetruite(px + py * 10);
			}
		}

	}


	for (std::list<Asteroides>::iterator astero = asteroides.begin(); astero != asteroides.end(); astero++) {
		/* Verification si l'asteroide a reussi a atteindre le joueur */
		if (astero->posX <= -1.0f){
			astero=asteroides.erase(astero);
			joueur->setVie(-1);
		} else{
		astero -> act();
		}
	}
	damier->act();
}





