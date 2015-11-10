#include "character.h"


Character::Character( )
{
	totalHp = 0;
	currentHp = 0;
	attackPower = 0;
	defence = 0;
}

int Character::statCheck( string statName )
{
	if ( statName == "health")
	{
		return totalHp;
	}
	else if ( statName == "attack")
	{
		return attackPower;
	}
	else if ( statName == "defence")
	{
		return defence;
	}

	return -1;

}

void Character::statChange( string statName, int statModifier )
{
	if ( statName == "health")
	{
		totalHp += statModifier;
	}
	else if ( statName == "attack")
	{
		attackPower += statModifier;
	}
	else if ( statName == "defence")
	{
		defence += statModifier;
	}

}

int Character::healthCheck( )
{
	return currentHp;
}

void Character::healthChange( int healthModifier )
{
	currentHp  += healthModifier;
}
