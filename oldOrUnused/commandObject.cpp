#include "commandObject.h"

CommandObject::CommandObject( )
{

}

bool CommandObject::checkInputs( string input )
{
	if ( input == "quit" || input == "q" QUICKEXIT )
	{
		return false;
	}

	return true;
}

