#include "Zombie.h"

Zombie::Zombie()
{
	walk.addFrame(sf::IntRect(0, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(55, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(110, 0, 55, 108));
	walk.addFrame(sf::IntRect(165, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(220, 0, 55, 108)); 
	walk.addFrame(sf::IntRect(275, 0, 55, 108));  
	walk.addFrame(sf::IntRect(330, 0, 55, 108));
	walk.addFrame(sf::IntRect(385, 0, 55, 108)); 
	walk.setFrameSpeed(1.f / 10.f);
}

Zombie::~Zombie()
{
}

void Zombie::update(float dt)
{

	walk.animate(dt); setTextureRect(walk.getCurrentFrame());
}

void Zombie::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Right))
	{
		if ((getPosition().x + getSize().x) < window->getSize().x)
		{
			walk.setFlipped(false);
			move(1000 * dt, 0);
		}
	}

	if (input->isKeyDown(sf::Keyboard::Left))
	{
		if (getPosition().x > 0)
		{
			walk.setFlipped(true);
			move(1000 * dt * (-1), 0);
		}
	}
}

void Zombie::setWindow(sf::RenderWindow* wi)
{
	
	window = wi;
}
