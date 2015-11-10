/* Project Clock Town Grind
	A simple Rpg where the player must leave town to find 4 stones of power to win the game.
	There are 5 reigons. Town, which heals the player if they remain there, Forest, Ocean, 
	Mountians, Desert, which all have their own orbs but also can spawn moster is remained at.
	Combat is Fight or run.
*/
#include <string>
#include <cstdlib>
#include "loadCore.h"
#include "coreData.h"
#include "intro.h"
#include "execute.h"
#include "quit.h"

void mainLoop();

int main()
{
	system("CLS");
	CoreData * userData;
	userData = loadCore();
	intro();
	mainLoop( userData );
	quit();
	return 0;
}