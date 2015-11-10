#include "execute.h"
#include "battle.h"
#include "coreData.h"
#include "map.h"

void mainLoop( CoreData * userData )
{
	string userInput;
	string * stateChange;


	Map * map = new Map( "town" , userData );
	Battle * battle = new Battle( userData );

	State * currentState = map;

	while (true)
	{
		cout << "> ";
		getline (cin, userInput);
		cin.clear();
		transform(userInput.begin(), userInput.end(), userInput.begin(), ::tolower);

		stateChange = currentState->checkInputs( userInput );

		if ( stateChange[0] == "quit" )
		{
			break;
		}
		else if ( stateChange[0] == "fight" )
		{
			system("CLS");
			battle->loadBattle( stateChange[1] );
			battleDisplay( battle );
			currentState = battle;
		}
		else if ( stateChange[0] == "map" )
		{
			cout << map->currentLocation->restartMapText << endl;
			currentState = map;
		}



	}
	
}
