#ifndef __combat_INCLUDED__
#define __combat_INCLUDED__

#include <iostream>
#include <string>
#include "coreData.h"
using namespace std;



class Battle: public State {
	string monster;
public:
	Battle( CoreData * loadedData );
	string * checkInputs( string input );
	bool loadMonsters( string monsters );
};

#endif
