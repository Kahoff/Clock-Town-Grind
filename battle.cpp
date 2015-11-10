#include "gameStates.h"
#include "battle.h"

Battle::Battle( CoreData * loadedData  ) : State( loadedData, "battle" )
{
	helpText = "A / Attack    - Attacks the monster.\n"
				"F / Flee      - Runs from battle, but greatly injures player.\n"
				"                * Will kill dying players. * \n";
	monster = new Monster( );
}

string * Battle::checkInputs( string input )
{
	string * playerAction = State::checkInputs( input );
	int damageToEnemy, damageToPlayer;
	int remainingHealth;
	if ( playerAction[0] != "" )
	{
		return playerAction;
	}

	playerAction[0] = "";



	if ( input == "help" || input == "h" )
	{
		cout << helpText;
	} 
	else if ( input == "attack" || input == "a" )
	{	
		system("CLS");
		if ( ( damageToEnemy = monster->statCheck( "defence" ) - userData->checkStat( "attack" ) ) > 0 )
		{
			damageToEnemy = 0;
		} 
		monster->healthChange( damageToEnemy );
		if ( monster->healthCheck() <= 0 ){
			cout << "You killed the " << monster->getName() << endl;
			playerAction[0] = "map";
		}
		else
		{
			battleDisplay( this );
			cout << "\n\nYou dealt " << -( damageToEnemy ) << " damage!\n";
			if ( ( damageToPlayer = userData->checkStat( "defence" ) - monster->statCheck( "attack" ) ) > 0 )
			{
				damageToPlayer = 0;
			} 
			userData->changeHealth( damageToPlayer );
			cout << "\nThe " << monster->getName() << " dealt "<< -( damageToPlayer ) << " damage!\n\n";
		}
		remainingHealth = userData->checkHealth( );
		if ( remainingHealth <= 0 )
		{
			cout << "The " << monster->getName() << " killed you!\n\n";
			playerAction[0] = "quit";
		}

	}
	else if ( input == "flee" || input == "f" )
	{	
		system("CLS");
		remainingHealth = userData->checkHealth( );
		if ( remainingHealth == 1 )
		{
			cout << "You were too injured to excape\n\n"
					<< "The " << monster->getName() << " killed you!\n\n";
			playerAction[0] = "quit";
		}
		else
		{
			damageToPlayer = 1 - remainingHealth;
			userData->changeHealth( damageToPlayer );
			cout << "You barely excaped\n"
					"The " << monster->getName() << " dealt "<< -( damageToPlayer ) << " damage!\n\n";
			playerAction[0] = "map";
		}

	}

	return playerAction;
}

bool Battle::loadBattle( string monsters )
{
	if ( monsters == "goblin")
	{
		monster->setMonster( 3, 1, 0, "goblin");
	} 
	else if ( monsters == "C-Creature")
	{
		monster->setMonster( 7, 2, 0, "C-Creature" );
	} 
	else if ( monsters == "Dragon")
	{
		monster->setMonster( 15, 5, 2, "Mini-Dragon" );
	} 
	else if ( monsters == "Demon from Hell!!!")
	{
		monster->setMonster( 10, 5, 6, "Demon from Hell!!!" );
	}

	return true;

}

void battleDisplay( Battle * currentState )
{
	cout << "You \3" << currentState->userData->checkHealth( ) << "/" << currentState->userData->checkStat( "health" ) << "  - VS -  "
		<< currentState->monster->healthCheck( ) << "/" << currentState->monster->statCheck( "health" ) << "\3 " << currentState->monster->getName() << endl;
}
