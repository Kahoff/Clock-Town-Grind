#ifndef __coreData_INCLUDED__
#define __coreData_INCLUDED__

#include <iostream>
#include <string>
#include "playerCharacter.h"

using namespace std;

class CoreData {
	bool northOrb, eastOrb, southOrb, westOrb;
	int numberOfOrbs;
	PlayerCharacter * mainCharacter;
public:
	CoreData( );
	bool checkOrb( string orbName );
	bool addOrb( string orbName );
	int checkStat( string statName );
	int checkHealth( );
	void changeStat( string statName, int statMod );
	void changeHealth( int healthMod );
	int checkNumberOfOrbs();
};

#endif
