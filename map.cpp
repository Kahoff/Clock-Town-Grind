#include "gameStates.h"
#include "map.h"
#include "town.h"
#include "mountain.h"
#include "ocean.h"
#include "forest.h"
#include "desert.h"

Map::Map( string startLocation, CoreData * loadedData  ) : State( loadedData, "map")
{
 	loadRegion( startLocation );
}

string * Map::checkInputs( string input )
{
	string * playerAction = State::checkInputs( input );
	if ( playerAction[0] != "" )
	{
		return playerAction;
	}

	playerAction = currentLocation->checkInputs( input );

	if ( playerAction[0] != "" )
	{
		if ( playerAction[0] == "move" )
		{
			system("CLS");
			if ( !( loadRegion( playerAction[1]) ) )
			{
				playerAction[0] = "quit";
			}
			else
			{
				playerAction[0] = "";
				playerAction[1] = "";
			}
		}

	}

	return playerAction;
}

 bool Map::loadRegion( string region )
{
	if ( region == "forest")
	{
		Forest * newLocation = new Forest( userData );
		cout << "You have entered the Forest\n";
		currentLocation = newLocation;
	} 
	else if ( region == "ocean")
	{
		Ocean * newLocation = new Ocean( userData );
		cout << "You have arrived at the Ocean.\n";
		currentLocation = newLocation;
	} 
	else if ( region == "mountain")
	{
		Mountain * newLocation = new Mountain( userData );
		cout << "You have arrived at the Mountains\n";
		currentLocation = newLocation;
	} 
	else if ( region == "desert")
	{
		Desert * newLocation = new Desert( userData );
		cout << "You have arrived at the Desert\n";
		currentLocation = newLocation;
	} 
	else if ( region == "town")
	{
		Town * newLocation = new Town( userData );
		int orbCount = userData->checkNumberOfOrbs();		
		if ( orbCount == 4 ) {
			cout << "\nYou Win!\n\n"
					"...your mother is so proud.\n";
			return false;
		}
		else
		{
			cout << "Welcome to Town\n";
		}
		currentLocation = newLocation;
	}

	return true;

}