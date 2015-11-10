#ifndef __mountain_INCLUDED__
#define __mountain_INCLUDED__

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "region.h"
using namespace std;



class Mountain : public Region{
public:
	Mountain( CoreData * loadedData );
	string * checkInputs( string input );
	string * adventure();
};

#endif
