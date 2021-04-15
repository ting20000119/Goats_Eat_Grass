#ifndef _World_H
#define _World_H
#include "Creature.h"
class World {
	public :
		World(int numPasses,int seed);
		void mainLoop(int displayInterval);
	private:
		int pass;
		Creature *map[20][35];		
};
#endif
