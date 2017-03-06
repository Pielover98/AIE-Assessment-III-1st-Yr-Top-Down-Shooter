

#include "Boss1Weapon.h"

sf::Texture Boss1Weapon::weaponTex;

Boss1Weapon::Boss1Weapon(){
	//get settings
	m_dmg = 10 * m_diff.ReadDiffSettings();
	IOsmooth smooth;

	//set stuff
	speed = 0.5f;
	m_active = true;
	hasTargetTexture = false;

	weaponTex.loadFromFile("graphics/enemies/pew.png");
	weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(weaponTex);
	sprite.setRotation(180);
	sprite.setOrigin(23.5, 12);
}

void Boss1Weapon::Update(sf::RenderWindow &window, float &elapsedTime){
	if (m_active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		if (y <= window.getSize().y)
			y += speed * elapsedTime;
		
		else
			m_active = false;

		sprite.setPosition(x, y);
	}
}

void Boss1Weapon::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(sprite);
}

void Boss1Weapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

//sets the entity active or inactive
void Boss1Weapon::setActiveBool(bool active){
	m_active = active;
}