#include "Level.h"
#include "Zombie.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	zombTexture.loadFromFile("gfx/animZombie.png");
	zombie.setSize(sf::Vector2f(55, 108)); 
	zombie.setPosition(100, 100); 
	zombie.setTexture(&zombTexture);
	zombie.setInput(input);
	zombie.setWindow(window);

	marTexture.loadFromFile("gfx/MarioSheetT.png");
	mario.setSize(sf::Vector2f(55, 108));
	mario.setPosition(100, 300);
	mario.setTexture(&marTexture);
	mario.setInput(input);
	mario.setWindow(window);


	// initialise game objects

}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	zombie.handleInput(dt);
	mario.handleInput(dt);

}

// Update game objects
void Level::update(float dt)
{
	zombie.update(dt);
	mario.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(zombie);
	window->draw(mario);
	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}