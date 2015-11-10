#ifndef __gameStates_INCLUDED__
#define __gameStates_INCLUDED__
#define QUICKEXIT /*|| input == ""*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "coreData.h"
using namespace std;

class State{
	string stateName, helpText;
public:
	string inputReturn[2];
	CoreData * userData;
	State( CoreData * loadedData, string name );
	virtual string * checkInputs( string input );
	virtual string checkState();
};

#endif
