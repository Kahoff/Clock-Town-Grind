#include "region.h"
#include "desert.h"

Desert::Desert( CoreData * loadedData ) : Region( loadedData )
{
	description = "\nThe world's largest litter box.\n";
	restText = "\nAlways rest before a desert, and after dessert.\n";
	north[0] = "move";
	north[1] = "mountain";
	northText = "";
	east[0] = "move";
	east[1] = "town";
	eastText = "";
	south[0] = "move";
	south[1] = "forest";
	southText = "";
	restartMapText = "\n\nYou return to the desert.\n";

}
string * Desert::checkInputs( string input )
{
	return  Region::checkInputs( input );;
}

string * Desert::adventure( )
{
	int searchChance;
	searchChance = rand() % 100;
	if (searchChance >= 99)
	{
		if( !( userData->checkOrb( "west" ) ) )
		{
			cout << "\n\nYou see something glitting...\n";
			cout << "\nYou found the west orb of power.\n";
			userData->addOrb("west");
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
	if ( searchChance < 99)
	{
		cout << "\nYou found a monster!\n";
		adventureReturn[0] = "fight";
		adventureReturn[1] = "Demon from Hell!!!";
	}
	return adventureReturn;
}
