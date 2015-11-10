#include "gameStates.h"
#include "mainMenu.h"

MainMenu::MainMenu( )
{

}

bool MainMenu::checkInputs( string input )
{
	if ( input == "quit" || input == "q" QUICKEXIT )
	{
		return false;
	}
	return true;
}

