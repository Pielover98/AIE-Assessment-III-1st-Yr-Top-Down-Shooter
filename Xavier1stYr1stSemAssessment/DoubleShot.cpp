
#include "DoubleShot.h"
#include <math.h>

sf::Texture DoubleShot::m_doubleTex;

DoubleShot::DoubleShot(float playerPosX, float playerPosY, sf::RenderWindow& window){
	m_active = true;
	m_isPew = false;

	//set direction up
	dirX = sf::Mouse::getPosition(window).x - playerPosX;
	dirY = sf::Mouse::getPosition(window).y - playerPosY;
	dir = sqrt((dirX*dirX) + (dirY*dirY));

	//get direction vector and normalize it
	m_direction.x = sf::Mouse::getPosition(window).x - playerPosX;
	m_direction.y = sf::Mouse::getPosition(window).y - playerPosY;
	m_direction = normalize(m_direction);


	m_doubleTex.loadFromFile("graphics/weapons/double.png");

	m_doubleTex.setSmooth(false);
	sprite.setTexture(m_doubleTex);
}

void DoubleShot::Update(float elapsedTime){
	if (m_active){
		float x = sprite.getPosition().x;
		float y = sprite.getPosition().y;

		sprite.move(m_direction * elapsedTime);
		if (y < 0.0f || y > 900.0f || x < 0.0f || x > 900.0f){
			m_active = false;
		}
	}

}

void DoubleShot::Render(sf::RenderWindow &window){
	if (m_active)
		window.draw(sprite);
}

void DoubleShot::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}


sf::Vector2f DoubleShot::normalize(sf::Vector2f& source){
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0.0f){
		return sf::Vector2f(source.x / length, source.y / length);
	}
	else
		return source;
}

//sets the entity active or inactive
void DoubleShot::setActiveBool(bool active){
	m_active = active;
}