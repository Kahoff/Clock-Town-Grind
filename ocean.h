#ifndef __ocean_INCLUDED__
#define __ocean_INCLUDED__

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "region.h"
using namespace std;



class Ocean : public Region{
public:
	Ocean( CoreData * loadedData );
	string * checkInputs( string input );
	string * adventure();
};

#endif
