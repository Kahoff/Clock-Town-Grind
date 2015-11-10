#ifndef __region_INCLUDED__
#define __region_INCLUDED__

#include <iostream>
#include <string>
#include "coreData.h"
using namespace std;



class Region {
public:
	string description, restText, southText, northText, eastText, westText, adventureText, helpText;
	string restartMapText;
	string south[2], east[2], west[2], north[2], adventureReturn[2];
	string returnNothing[2];
	CoreData * userData;
	Region( CoreData * loadedData );
	virtual string * checkInputs( string input );
	virtual string * adventure();
	virtual void rest();
};

#endif
