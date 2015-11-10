#include "character.h"
#include "playerCharacter.h"


PlayerCharacter::PlayerCharacter( )
{
	statChange( "health", 5);
	statChange( "attack", 1);
	statChange( "defence", 0);
	healthChange( 5 );
}
