#ifndef __monster_INCLUDED__
#define __monster_INCLUDED__

#include <iostream>
#include <string>
#include "character.h"

using namespace std;

class Monster : public Character {
	string monsterName;
public:
	Monster();
	void setMonster( int setHp, int setAttack, int setDefence, string name );
	string getName();
};

#endif
