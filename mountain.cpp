#include "region.h"
#include "mountain.h"

Mountain::Mountain( CoreData * loadedData ) : Region( loadedData )
{
	description = "\nIt's a whole range of lonely mountains.\n";
	restText = "\nThere isn't much up here, but your pretty sure you would"
				"\nfall if you tried to sit.\n";
	east[0] = "move";
	east[1] = "ocean";
	eastText = "";
	south[0] = "move";
	south[1] = "town";
	southText = "";
	west[0] = "move";
	west[1] = "desert";
	westText = "";
	restartMapText = "\n\nYou return to the mountians.\n";

}
string * Mountain::checkInputs( string input )
{
	return  Region::checkInputs( input );;
}

string * Mountain::adventure( )
{
	int searchChance;
	searchChance = rand() % 100;
	if (searchChance >= 95)
	{
		if( !( userData->checkOrb( "north" ) ) )
		{
			cout << "\n\nYou see something glitting...\n";
			cout << "\nYou found the north orb of power.\n";
			userData->addOrb("north");
			int orbCount = userData->checkNumberOfOrbs();			
			if ( orbCount < 4 )
			{
				cout << "You now have " << orbCount << " of 4 orbs!\n";
			}
			else
			{
				cout << "You now have all of the orbs!\n"
						"Return to town!";
			}
			userData->changeStat( "health", 5 );
			userData->changeStat( "attack", 2 );
			userData->changeStat( "defence", 2 );
			cout << "You gained " << 5 << " health!\n"
					"You gained " << 2 << " attack!\n"
					"You gained " << 2 << " defence!\n";

			adventureReturn[0] = "";
			adventureReturn[1] = "";

		}
		else
		{
			cout << "\nYou see something glitting...\n\n\n";
			searchChance = 0;
		}
	}
	if ( searchChance < 95)
	{
		cout << "\nYou found a monster!\n";
		adventureReturn[0] = "fight";
		adventureReturn[1] = "Dragon";
	}
	return adventureReturn;
}
