#ifndef __desert_INCLUDED__
#define __desert_INCLUDED__

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "region.h"
using namespace std;



class Desert : public Region{
public:
	Desert( CoreData * loadedData );
	string * checkInputs( string input );
	string * adventure();
};

#endif
