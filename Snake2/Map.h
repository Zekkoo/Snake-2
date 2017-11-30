#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
enum state { BOARD, HEAD, SNAKE, FOOD };
struct Location
{
	Location(int x, int y):x(x), y(y), currentState(BOARD)
	{
		boardCol = sf::Color::White;
		snakeCol = sf::Color::Green;
		foodCol = sf::Color::Red;
		headCol = sf::Color::Yellow;
	}
	int x, y;	
	sf::Color boardCol, snakeCol, foodCol, headCol;
	state currentState;
	void drawTile(sf::RenderWindow& w, sf::Color col, int size);
};

class Map
{
public:
	Map();
	Map(int x, int y);
	void setSize(int x, int y);
	sf::Vector2i getSize();
	void setTileState(int x, int y, state s);
	Location& getTile(int x, int y);
	void drawMap(sf::RenderWindow& w, sf::Color col);
	void reDraw();
private:
	void init();
	int tileSize;
	int width, height;
	std::vector<Location> grid;
};