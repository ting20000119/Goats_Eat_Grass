#ifndef _Goat_H_
#define _Goat_H_
#include<iostream>
#include<string.h>
#include <stdlib.h>
#include "Creature.h"
class Goat:public Creature {
	public:
		Goat(int nowage,int nowpoint,int i);
		int getage();
		void updateage();
		int getpoint();
		void updatepoint(int p);
		void updateaction();
		int getaction();
	private:
		int age;
		int point;
		int id;
		int act;
};

#endif
