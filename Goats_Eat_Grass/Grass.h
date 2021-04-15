
#ifndef _Grass_H_
#define _Grass_H_
#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Creature.h"
class Grass:public Creature {
	public:
		Grass(int nowage,int i);
		int getage();
		void updateage();
		int getpoint();
		void updatepoint(int p);
		void updateaction();
		int getaction();
	private:
		int age;
		int id;
		int point;
		int act;
};
#endif
