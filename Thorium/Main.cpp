#include "SFML\Graphics.hpp"
#include "GameEngine.h"

int main()
{
	GameEngine* game = new GameEngine(720, 405, "thoriumBREED");

	// Start the game loop
	while (GameEngine::engineState != GAME_STATE_SHUTDOWN)
	{
		game->update();
		game->render();
	}
	return EXIT_SUCCESS;
}