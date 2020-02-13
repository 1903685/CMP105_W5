#include "Mario.h"

Mario::Mario()
{
	walk.addFrame(sf::IntRect(0, 0, 15, 21));
	walk.addFrame(sf::IntRect(15, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(30, 0, 15, 21)); 
	walk.addFrame(sf::IntRect(45, 0, 15, 21));
	walk.setFrameSpeed(1.f / 3.f);

	swim.addFrame(sf::IntRect(0, 21, 16, 20));
	swim.addFrame(sf::IntRect(16, 21, 16, 20));
	swim.addFrame(sf::IntRect(32, 21, 16, 20)); 
	swim.setFrameSpeed(1.f / 4.f);

	duck.addFrame(sf::IntRect(0, 21, 16, 20));
	duck.addFrame(sf::IntRect(16, 21, 16, 20));
	duck.addFrame(sf::IntRect(32, 21, 16, 20));
	duck.setFrameSpeed(1.f / 4.f);

	currentAnimation = &walk; 
	setTextureRect(currentAnimation->getCurrentFrame());
}

Mario::~Mario()
{
}

void Mario::update(float dt)
{
	currentAnimation->animate(dt); 
	setTextureRect(currentAnimation->getCurrentFrame()); 

	if (input->isKeyDown(sf::Keyboard::Num1)) 
	{
		currentAnimation = &walk;
		currentAnimation->reset();
		setTextureRect(currentAnimation->getCurrentFrame());
	}

}

void Mario::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::W)) 
	{
	
		currentAnimation = &swim;
	}
	else if (input->isKeyDown(sf::Keyboard::D)) 
	{
		if ((getPosition().x + getSize().x) < window->getSize().x)
		{
			walk.setFlipped(false);
			move(1000 * dt, 0);
			currentAnimation = &walk;
		}
	}
	else if (input->isKeyDown(sf::Keyboard::A))
	{
		if (getPosition().x > 0)
		{
			walk.setFlipped(true);
			move(1000 * dt * (-1), 0);
			currentAnimation = &walk;
		}
	}
	
}

void Mario::setWindow(sf::RenderWindow* win)
{
	window = win;
}
