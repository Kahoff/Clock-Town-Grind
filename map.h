#ifndef __map_INCLUDED__
#define __map_INCLUDED__

#include <iostream>
#include <string>
#include "gameStates.h"
#include "coreData.h"
#include "town.h"
#include "mountain.h"
#include "ocean.h"
#include "forest.h"
#include "desert.h"
using namespace std;



class Map: public State {
public:
	Region * currentLocation;
	Map( string startLocation, CoreData * loadedData );
	string * checkInputs( string input );
	bool loadRegion( string region );
};

#endif
