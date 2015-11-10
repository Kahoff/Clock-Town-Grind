#include "region.h"
#include "forest.h"

Forest::Forest( CoreData * loadedData ) : Region( loadedData )
{
	description = "\n\nIt is a spooooooky forest.\n\n"
						"Boo\n";
	restText = "\nSleep? \nAlone in the woods?\n"
				"Oh sure, the smart ones always get eaten first.\n";
	north[0] = "move";
	north[1] = "town";
	northText = "";
	east[0] = "move";
	east[1] = "ocean";
	eastText = "";
	west[0] = "move";
	west[1] = "desert";
	westText = "";
	restartMapText = "\n\nYou return to the forest.\n";

}
string * Forest::checkInputs( string input )
{
	return  Region::checkInputs( input );;
}

string * Forest::adventure( )
{
	int searchChance;
	searchChance = rand() % 100;
	if (searchChance >= 75)
	{
		if( !( userData->checkOrb( "south" ) ) )
		{
			cout << "\n\nYou see something glitting...\n";
			cout << "\nYou found the south orb of power.\n";
			userData->addOrb("south");
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
			userData->changeStat( "attack", 1 );
			userData->changeStat( "defence", 1 );
			cout << "You gained " << 5 << " health!\n"
					"You gained " << 1 << " attack!\n"
					"You gained " << 1 << " defence!\n";

			adventureReturn[0] = "";
			adventureReturn[1] = "";

		}
		else
		{
			cout << "\nYou see something glitting...\n\n\n";
			searchChance = 0;
		}
	}
	if ( searchChance < 75)
	{
		cout << "\nYou found a monster!\n";
		adventureReturn[0] = "fight";
		adventureReturn[1] = "goblin";
	}
	return adventureReturn;
}
