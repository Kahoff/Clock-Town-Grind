#ifndef __mainMenu_INCLUDED__
#define __mainMenu_INCLUDED__

#include <iostream>
#include <string>
#include "gameStates.h"
using namespace std;

class MainMenu: public State {
public:
	MainMenu( );
	bool checkInputs( string input );
};

#endif
