#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Goat.h"
#include "Grass.h"
#include "World.h"
#include "Creature.h"
using namespace std;
Creature::Creature(int whichid){
	id = whichid;
}
int Creature::getid(){
	return id;
}

int Creature::getdirect(){
	direct=rand()%4;
	return direct;
}
