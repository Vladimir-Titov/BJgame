#include "main.hpp"

int	main()
{
	Game	game;

	srand(static_cast<unsigned int>(time(0)));
	rand();
	game.start();
	return (0);
}