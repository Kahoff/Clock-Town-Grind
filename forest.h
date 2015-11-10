#ifndef __forest_INCLUDED__
#define __forest_INCLUDED__

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "region.h"
using namespace std;



class Forest : public Region{
public:
	Forest( CoreData * loadedData );
	string * checkInputs( string input );
	string * adventure();
};

#endif
