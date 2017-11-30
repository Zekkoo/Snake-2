#pragma once
#include "Map.h"
#include <iostream>
#define LOG(x) std::cout<<x<<std::endl
class Snake
{
public:
	Snake(Map& map);
	void grow();
	void follow();
	void move(sf::Vector2f dir);
	void drawToGrid(Map& map);

private:
	sf::Vector2f currentDir;
	std::vector<sf::Vector2f> segments;
	Map& map;
	int length;
};