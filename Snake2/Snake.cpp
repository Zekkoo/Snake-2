#include "Snake.h"

Snake::Snake(Map& map) : map(map)
{
	sf::Vector2f p(0, 10);
	segments.push_back(p);
	currentDir.x = 1;
	currentDir.y = 0;
	length = 1;
}

void Snake::move(sf::Vector2f dir)
{
	map.setTileState(segments[0].x, segments[0].y, state::BOARD);
	if(dir.x == -(currentDir.x)) {}
	else 
		currentDir.x = dir.x;
	if (dir.y == -(currentDir.y)) {}
	else
		currentDir.y = dir.y;
	segments[0].x += currentDir.x;
	segments[0].y += currentDir.y;
	if (segments[0].x > map.getSize().x - 1) 
		segments[0].x = 0;
	if (segments[0].x < 0) 
		segments[0].x = map.getSize().x - 1;
	if (segments[0].y > map.getSize().y - 1) segments[0].y = 0;
	if (segments[0].y < 0) segments[0].y = map.getSize().y - 1;

	follow();

}

void Snake::drawToGrid(Map& map)
{
	map.setTileState(segments[0].x, segments[0].y, state::HEAD);
	for(auto const& i : segments)
		map.setTileState(i.x, i.y, state::SNAKE);
}

void Snake::grow()
{
	segments.push_back(sf::Vector2f(segments[length - 1].x, segments[length - 1].y));
	length++;
	LOG(length);
}

void Snake::follow()
{
	if (length > 1)
	{
		for (int i = length-1; i >= 1; i--)
		{
			segments[i] = segments[i - 1];
		}
	}
	
}