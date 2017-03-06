

#ifndef _PLAYER_H
#define _PLAYER_H

#include <string>
#include <SFML/Graphics.hpp>

class Player{
public:
	Player();

	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void reduceHealth(int pDamage);
	void increaseHealth(int heal);
	void setHealth(int mhealth);
	void setActiveBool(bool active);

	//getter
	int getHealth() const { return m_health; };
	sf::Vector2f getPosition() const { return playerSprite.getPosition(); };
	bool getActiveBool() const { return m_active; }
	

	sf::Sprite playerSprite;
private:
	//Handle the Input
	void handleInput(sf::RenderWindow& window);

	//Handle Appearance
	void setMovingTexture();
	void setStandingTexture();
	void handleRotation(sf::RenderWindow& window);

	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position
	float m_elapsedTime;	///< time that passes in one frame

	int m_health;			///< actual health

	bool m_hasMovingTexture;///< True = Texture for moving is set | False = Texture for standing is set
	bool m_active;			///< if this is true-> it is active

	sf::Texture m_playerTex;
	sf::Texture m_playerTexMoving;
};
#endif