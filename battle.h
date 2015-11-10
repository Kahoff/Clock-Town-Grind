#ifndef __battle_INCLUDED__
#define __battle_INCLUDED__

#include <iostream>
#include <string>
#include "gameStates.h"
#include "coreData.h"
#include "monster.h"
using namespace std;



class Battle: public State {
public:
	Monster * monster;
	string helpText;
	Battle( CoreData * loadedData );
	string * checkInputs( string input );
	bool loadBattle( string monsters );
};

void battleDisplay( Battle * currentState );

#endif
