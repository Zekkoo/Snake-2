#include "Map.h"

Map::Map()
{
}

Map::Map(int x, int y)
{
	width = x;
	height = y;
	
	init();
}
void Map::init()
{
	for (int i = 0; i<width; i++)
		for (int j = 0; j < height; j++)
		{
			grid.push_back(Location(i *tileSize, j * tileSize));
		}
}
void Map::setSize(int x, int y)
{
	width = x;
	height = y;
	tileSize = 20;
	init();
}

sf::Vector2i Map::getSize()
{
	return sf::Vector2i(width, height);
}

void Map::setTileState(int x, int y, state s)
{
	getTile(x, y).currentState = s;
}

Location& Map::getTile(int x, int y)
{
	return grid.at((x*width) + y);
}

void Map::drawMap(sf::RenderWindow& w, sf::Color col)
{
	for (int i = 0; i<width; i++)
		for (int j = 0; j < height; j++)
		{
			getTile(i, j).drawTile(w, col, tileSize);
		}
}

void Location::drawTile(sf::RenderWindow & w, sf::Color col, int size)
{
	sf::RectangleShape tile;
	switch (currentState)
	{
	case BOARD:
		tile.setFillColor(boardCol);
		break;
	case SNAKE:
		tile.setFillColor(snakeCol);
		break;
	case FOOD:
		tile.setFillColor(foodCol);
		break;
	case HEAD:
		tile.setFillColor(headCol);
		break;
	default:
		tile.setFillColor(col);
		break;
	}
	
	tile.setPosition(sf::Vector2f(x * 1.1f, y * 1.1f));
	tile.setSize(sf::Vector2f(size, size));
	w.draw(tile);
}

void Map::reDraw()
{
	for(int i=0; i<width; i++)
		for (int j = 0; j < height; j++)
		{
			setTileState(i, j, state::BOARD);
		}
}
