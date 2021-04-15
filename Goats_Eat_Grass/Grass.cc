#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "World.h"
using namespace std;

Grass::Grass(int nowage,int i):Creature(2){	
	age = nowage;
	act=i;
}
int Grass::getage(){
	return age;		
}
void Grass::updateage(){
	age=age+1;		
}
int Grass::getpoint(){
	return point;	
}
void Grass::updatepoint(int p){
	point=point+p;	
}

void Grass::updateaction(){
	act=act+1;
}

int Grass::getaction(){
	return act;	
}
