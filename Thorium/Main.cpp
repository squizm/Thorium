#include "SFML\Graphics.hpp"
#include "GameEngine.h"

int main()
{
	GameEngine* game = new GameEngine(640, 360, "thoriumBREED");

	// Start the game loop
	while (game->engineState != GameEngine::ENGINE_STATE::SHUTDOWN)
	{
		game->update();
		game->render();
	}
	return EXIT_SUCCESS;
}