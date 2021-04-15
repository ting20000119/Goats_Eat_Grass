#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Creature.h"
#include "Goat.h"
#include "Grass.h"
#include "World.h"
using namespace std;
Goat::Goat(int nowage,int nowpoint,int i):Creature(1){
	age = nowage;
	point = nowpoint;
	act=i;
}
int Goat::getage(){
	return age;		
}
void Goat::updateage(){
	age=age+1;		
}
int Goat::getpoint(){
	return point;	
}

void Goat::updatepoint(int p){
	point=point+p;	
}

void Goat::updateaction(){
	act=act+1;
}

int Goat::getaction(){
	return act;	
}
