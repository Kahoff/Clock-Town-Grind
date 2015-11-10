#include "region.h"
#include "town.h"

Town::Town( CoreData * loadedData ) : Region( loadedData )
{
	description = "\nIt's a small town.\n"
					"Everyone is running around talking about the end of the world...\n"
					"You suspect that there some magic collectable for dealing with that.\n";
	north[0] = "move";
	north[1] = "mountain";
	northText = "";
	east[0] = "move";
	east[1] = "ocean";
	eastText = "";
	south[0] = "move";
	south[1] = "forest";
	southText = "";
	west[0] = "move";
	west[1] = "desert";
	westText = "";
	restartMapText = "\n\nYou return to town.\n";

}
string * Town::checkInputs( string input )
{
	return Region::checkInputs( input );
}

void Town::rest( )
{
	cout << "\nYou feel well rested!\n";
	int totalHealth = userData->checkStat( "health" );
	int healthToHeal = totalHealth - userData->checkHealth( );
	if ( healthToHeal != 0 )
	{
		userData->changeHealth( healthToHeal );
		cout << "You recovered " << healthToHeal << " Hp!\n";
	}

}
