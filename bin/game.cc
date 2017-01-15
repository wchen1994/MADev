/*
A touhou like game
*/
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream> 
#include <cmath>
#include <list>
#include <cstdlib>

#include "Scene.hpp"
#include "GameObject.hpp"
#include "Player.hpp"
#include "Game.hpp"

int main(){
	Scene *pScene;
	Game game;
	pScene = &game;
	pScene->Run();
//	game.Run();

	return 0;
}
