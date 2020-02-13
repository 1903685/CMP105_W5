#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"
class Zombie :public GameObject
{
 public:
	Zombie();
	~Zombie();
	void update(float dt) override;
	void handleInput(float );
	void setWindow(sf::RenderWindow*);
	//void setFlipped();
private:
	sf::RenderWindow* window;

 protected:
	Animation walk;
};

