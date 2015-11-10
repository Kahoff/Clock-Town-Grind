#include "character.h"
#include "monster.h"


Monster::Monster( )
{
	
}

void Monster::setMonster( int setHp, int setAttack, int setDefence, string name )
{
	statChange( "health", ( setHp - statCheck( "health" ) ) );
	statChange( "attack", ( setAttack - statCheck( "attack" ) )  );
	statChange( "defence", ( setDefence  - statCheck( "defence" ) ) );
	healthChange( ( setHp - healthCheck( ) ) );
	monsterName = name;
}

string Monster::getName()
{
	return monsterName;
}
