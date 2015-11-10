#include "region.h"


/*	cout << "L / Load   - Loads a Player Profile.\n" ;
	cout << "D / Delete - Deletes an unwanted Player Profile.\n" ;
	cout << "H / Help   - Lists user commands and their use.\n" ;
	cout << "Q / Quit   - Exits the game.\n\n"*/

Region::Region( CoreData * loadedData )
{
	userData = loadedData;
	restartMapText = "\n...\n";
	description = "\n\n...\n";
	restText = "\nYou can't rest here!\n"; 
	southText = "\nYou can't go that way.\n"; 
	northText = "\nYou can't go that way.\n"; 
	eastText = "\nYou can't go that way.\n"; 
	westText = "\nYou can't go that way.\n"; 
	adventureText = "\nYou can't adventure here!\n"; 
	helpText = 	  "L / Look      - Gives a discription of the area.\n"
				  "R / Rest      - Player rests to recover health, if the area is safe.\n"
				  "A / Adventure - Player looks for adventure, if any is to be had.\n"
				  "N / North     - Player moves north.\n"
				  "E / East      - Player moves east.\n"
				  "S / South     - Player moves south.\n"
				  "W / West      - Player moves west.\n";
	for (int i = 0; i < 2; i++)
	{
		south[i] = "";
		north[i] = "";
		east[i] = "";
		west[i] = "";
		adventureReturn[i] = "";
		returnNothing[i] = "";
	} 

}

string * Region::checkInputs( string input )
{	
	if ( input == "help" || input == "h" )
	{
		cout << helpText;
	}
	else if ( input == "look" || input == "l" )
	{
		cout << description;
	}
	else if ( input == "rest" || input == "r" )
	{
		rest();
	}
	else if ( input == "adventure" || input == "a" )
	{
		return adventure();
	}
	else if ( input == "south" || input == "s" ) 
	{
		cout << southText;
		return south;
	}
	else if ( input == "north" || input == "n" ) 
	{
		cout << northText;
		return north;
	}
	else if ( input == "east" || input == "e" ) 
	{
		cout << eastText;
		return east;
	}
	else if ( input == "west" || input == "w" ) 
	{
		cout << westText;
		return west;
	}

	return returnNothing;
}

string * Region::adventure()
{
	cout << adventureText;
	return adventureReturn;
}

void Region::rest()
{
	cout << restText;
}
