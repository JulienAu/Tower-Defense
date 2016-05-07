#include "GraphicPrimitives.h"
#include "Joueur.h"

Joueur::~Joueur() {
	// TODO Auto-generated destructor stub
}

void Joueur::setArgent(int x){
	argent = argent + x;
}

void Joueur::setVie(int x){
	vie = vie + x;
}

void Joueur::setScore(int x){
	score = score +x ;
}


void Joueur::draw(){
	char str1[50];
	char str2[50];
	char str3[50];
    affichage(str1,"Joueur Argent $ : ",argent);
    affichage(str2,"Joueur vie : ",vie);
    affichage(str3,"Joueur Score : ",score);
	GraphicPrimitives::drawText2D(str1, -0.98f , 0.90f , 1.0f , 1.0f ,0.99f);
	GraphicPrimitives::drawText2D(str2, -0.98f , 0.80f , 1.0f , 1.0f ,0.99f);
	GraphicPrimitives::drawText2D(str3, -0.98f , 0.70f , 1.0f , 1.0f ,0.99f);
	GraphicPrimitives::drawText2D("Ralentisseur", -0.50f , 0.70f , 0.30f , 0.0f, 1.0f );
	GraphicPrimitives::drawFillTriangle2D(-0.45f, 0.90f , -0.35f, 0.85f,-0.45f, 0.80f, 0.30f , 0.0f, 1.0f );
	GraphicPrimitives::drawText2D("250$", -0.45f , 0.63f , 1.0f , 1.0f, 1.0f );
	GraphicPrimitives::drawText2D("Tourelle", -0.15f , 0.70f , 1.0f , 0.5f, 0.3f  );
	GraphicPrimitives::drawFillTriangle2D(-0.15f, 0.90f , -0.05f, 0.85f,-0.15f, 0.80f, 01.0f , 0.5f, 0.3f );
	GraphicPrimitives::drawText2D("100$", -0.10f , 0.63f , 1.0f , 1.0f, 1.0f );
	GraphicPrimitives::drawText2D("Exterminateur", 0.15f , 0.70f , 0.0f , 1.0f, 0.3f );
	GraphicPrimitives::drawFillTriangle2D(0.25f, 0.90f , 0.35f, 0.85f,0.25f, 0.80f, 0.0f , 1.0f, 0.3f );
	GraphicPrimitives::drawText2D("500$", 0.25f , 0.63f , 1.0f , 1.0f, 1.0f );
	GraphicPrimitives::drawFillRect2D(posX, 0.95f , 0.05f, 0.05f, 1.0f, 1.0f , 0.0f );
}

void Joueur::affichage(char s[],char * str,int n){
	strcpy(s,str);
    std::string nb = std::to_string(n);
    char const* pchar = nb.c_str();
    strncat(s,pchar,10);
}
