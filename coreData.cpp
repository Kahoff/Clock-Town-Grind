#include "playerCharacter.h"
#include "coreData.h"


CoreData::CoreData( )
{
	mainCharacter = new PlayerCharacter();
	southOrb = false;
	northOrb = false;
	westOrb = false;
	eastOrb = false;
	numberOfOrbs = 0;
}

bool CoreData::checkOrb( string orbName )
	{
		if ( orbName == "north" )
		{
			if ( northOrb == true )
			{
				return true;
			}

		}
		else if ( orbName == "east" )
		{
			if ( eastOrb == true )
			{
				return true;
			}

		}
		else if ( orbName == "south" )
		{
			if ( southOrb == true )
			{
				return true;
			}

		}
		else if ( orbName == "west" )
		{
			if ( westOrb == true )
			{
				return true;
			}

		}

		return false;

	}

bool CoreData::addOrb( string orbName )
	{

		if ( orbName == "north" )
		{
			if ( northOrb == false )
			{
				northOrb = true;
				numberOfOrbs++;
				return true;
			}

		}
		else if ( orbName == "east" )
		{
			if ( eastOrb == false )
			{
				eastOrb = true;
				numberOfOrbs++;
				return true;
			}

		}
		else if ( orbName == "south" )
		{
			if ( southOrb == false )
			{
				southOrb = true;
				numberOfOrbs++;
				return true;
			}

		}
		else if ( orbName == "west" )
		{
			if ( westOrb == false )
			{
				westOrb = true;
				numberOfOrbs++;
				return true;
			}

		}

		return false;
	}


int CoreData::checkStat( string statName )
{
	if ( statName == "health")
	{
		return mainCharacter->statCheck( "health" );
	}
	else if ( statName == "attack")
	{
		return mainCharacter->statCheck( "attack" );
	}
	else if ( statName == "defence")
	{
		return mainCharacter->statCheck( "defence" );
	}

	return -1;
}

int CoreData::checkHealth( )
{
	return mainCharacter->healthCheck();
}

void CoreData::changeStat( string statName, int statMod )
{
	if ( statName == "health")
	{
		mainCharacter->statChange( "health", statMod );
	}
	else if ( statName == "attack")
	{
		mainCharacter->statChange( "attack", statMod );
	}
	else if ( statName == "defence")
	{
		mainCharacter->statChange( "defence", statMod );
	}

}

void CoreData::changeHealth( int healthMod )
{
	mainCharacter->healthChange( healthMod );
}

int CoreData::checkNumberOfOrbs()
{
	return numberOfOrbs;
}
