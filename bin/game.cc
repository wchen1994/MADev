/*
A touhou like game
*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cmath>
#include <list>
#include <cstdlib>

#include "GameObject.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main(){
	Game game;
	game.Run();

	return 0;
}
