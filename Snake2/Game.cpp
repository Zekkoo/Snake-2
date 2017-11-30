#include "Game.h"

Game::Game()
	:fixedTimeStep(1.0f / 60.0f), snake(map), direction(1,0)
{
	map.setSize(20, 20);
	screenWidth = 800;
	screenHeight = 600;
	screenTitle = "Snake 2.0";
	font.loadFromFile("Geomanist-Regular.otf");
}
/*Game loop*/
void Game::run() 
{
	init();


	sf::Clock fpsClock;
	sf::Clock frameClock;
	sf::Time timeSinceLastFrame = sf::Time::Zero;
	sf::Time fpsTime = sf::Time::Zero;
	int frames = 0;
	float accumulator = 0;


	while (window.isOpen())
	{
		timeSinceLastFrame = fpsClock.restart();
		accumulator += timeSinceLastFrame.asSeconds();
		
		
		while(accumulator > fixedTimeStep)
		{
			fpsTime = frameClock.restart();
			fps = frames *  (1.0f / fpsTime.asSeconds());
			frames = 0;
			accumulator -= fixedTimeStep;


			handleEvents();
			composeFrame();


			frames++;
		}		
		
	}
}

void Game::init()
{
	window.create(sf::VideoMode(screenWidth, screenHeight), screenTitle);
	window.setVerticalSyncEnabled(false);
}

void Game::handleEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::D)
			{
				direction.x = 1;
				direction.y = 0;
			}
			if (event.key.code == sf::Keyboard::A)
			{
				direction.x = -1;
				direction.y = 0;
			}
			if (event.key.code == sf::Keyboard::W)
			{
				direction.x = 0;
				direction.y = -1;
			}
			if (event.key.code == sf::Keyboard::S)
			{
				direction.x = 0;
				direction.y = 1;
			}
			if (event.key.code == sf::Keyboard::Space)
				snake.grow();
		default:
			break;
		}
	}
}

void Game::composeFrame()
{
	window.clear();
	map.reDraw();
	/*DRAWING TO SCREEN*/
	sf::Text fpsText;
	fpsText.setFont(font);
	fpsText.setString(std::to_string(fps));
	map.setTileState(2, 2, state::FOOD);
	
	if (mainClock.getElapsedTime().asSeconds() > 0.5f)
	{
		mainClock.restart();
		snake.move(direction);
	}
	snake.drawToGrid(map);
	
	map.drawMap(window, sf::Color::Blue);
	window.draw(fpsText);
	/*******************/
	window.display();
}
