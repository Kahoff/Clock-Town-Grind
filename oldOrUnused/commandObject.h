#ifndef __commandObject_INCLUDED__
#define __commandObject_INCLUDED__
#define QUICKEXIT /*|| input == ""*/

#include <iostream>
#include <string>
using namespace std;

class CommandObject{
public:
	CommandObject( );
	virtual bool checkInputs( string input );
};

#endif
