#ifndef __town_INCLUDED__
#define __town_INCLUDED__

#include <iostream>
#include <string>
#include "region.h"
using namespace std;



class Town : public Region{
public:
	Town( CoreData * loadedData );
	string * checkInputs( string input );
	void rest();
};

#endif
