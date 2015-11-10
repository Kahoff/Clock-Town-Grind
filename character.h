#ifndef __character_INCLUDED__
#define __character_INCLUDED__

#include <iostream>
#include <string>

using namespace std;

class Character {
	int totalHp, currentHp, attackPower, defence;
public:
	Character( );
	virtual int statCheck( string statName );
	virtual void statChange( string statName, int statModifier );
	virtual int healthCheck( );
	virtual void healthChange( int healthModifier );
};

#endif
