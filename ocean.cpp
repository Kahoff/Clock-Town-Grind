#include "region.h"
#include "ocean.h"

Ocean::Ocean( CoreData * loadedData ) : Region( loadedData )
{
	description = "\nIt is a deep puddle.\n";
	restText = "\nYou could rest here, or you could use a bed.\n";
	north[0] = "move";
	north[1] = "mountain";
	northText = "";
	south[0] = "move";
	south[1] = "forest";
	southText = "";
	west[0] = "move";
	west[1] = "town";
	westText = "";
	restartMapText = "\n\nYou return to the ocean.\n";

}
string * Ocean::checkInputs( string input )
{
	return  Region::checkInputs( input );;
}

string * Ocean::adventure( )
{
	int searchChance;
	searchChance = rand() % 100;
	if (searchChance >= 85)
	{
		if( !( userData->checkOrb( "east" ) ) )
		{
			cout << "\n\nYou see something glitting...\n";
			cout << "\nYou found the east orb of power.\n";
			userData->addOrb("east");
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
			userData->changeStat( "attack", 3 );
			userData->changeStat( "defence", 1 );
			cout << "You gained " << 5 << " health!\n"
					"You gained " << 3 << " attack!\n"
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
	if ( searchChance < 85)
	{
		cout << "\nYou found a monster!\n";
		adventureReturn[0] = "fight";
		adventureReturn[1] = "C-Creature";
	}
	return adventureReturn;
}
