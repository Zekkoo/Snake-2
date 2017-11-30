#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include "Map.h"
#include "Snake.h"
#define LOG(x) std::cout<<x<<std::endl

class Game
{
public:
	Game();

	void run();
private:
	void init();
	void handleEvents();
	void composeFrame();
private:
	sf::Vector2f direction;
	sf::Clock mainClock;
	sf::RenderWindow window;
	sf::Font font;
	int screenWidth, screenHeight;
	std::string screenTitle;
	int fps;
	const float fixedTimeStep;
	Map map;
	Snake snake;
};