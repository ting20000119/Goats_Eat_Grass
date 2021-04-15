#ifndef _Creature_H_
#define _Creature_H_
#include<iostream>
#include<string.h>
#include <stdlib.h>
class Creature{
	public:		
		Creature(int whichid);
		int getid();
		int getdirect();
		virtual void updateaction()=0;
		virtual int getaction()=0;
		virtual	void updateage()=0;
		virtual	int getage()=0;
		virtual int getpoint()=0;
		virtual	void updatepoint(int p)=0;

	private:
		int act;
		int id;
		int direct;
};

#endif
