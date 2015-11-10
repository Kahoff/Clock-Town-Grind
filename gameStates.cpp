#include "gameStates.h"
#include "coreData.h"

State::State( CoreData * loadedData, string name )
{
	for (int i = 0; i < 2; i++)
	{
		inputReturn[i] = "";
	}
	userData = loadedData;
	stateName = name;
	helpText = 
	helpText = "\nCommand         Action\n"
				  "Q / Quit      - Quits the game.\n"
				  "H / Help      - Prints a list of commands and what they do.\n"
				  "C / Character - Prints your current status.\n";
}

string * State::checkInputs( string input )
{
	if ( input == "quit" || input == "q" QUICKEXIT )
	{
		inputReturn[0] = "quit";
	}
	else if ( input == "help" || input == "h" )
	{
		cout << helpText;
	}
	else if ( input == "character" || input == "c" )
	{
		cout << "\nHp: " << userData->checkHealth( ) << "/" << userData->checkStat( "health" ) << endl
				<< "Attack: " << userData->checkStat( "attack" ) << endl
				<< "Defence: " << userData->checkStat( "defence" ) << endl;
	}
	else
	{
		inputReturn[0] = "";		
	}

	return inputReturn;
}

string State::checkState()
{
	return stateName;
}
