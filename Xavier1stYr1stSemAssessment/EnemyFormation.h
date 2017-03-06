

#ifndef ENEMYFORMATION_H
#define ENEMYFORMATION_H

#include <SFML/Graphics.hpp>
#include "IO.h"

class EnemyFormation{
public:
	EnemyFormation();
	void Update(sf::RenderWindow &window, float elapsedTime);
	void Render(sf::RenderWindow &window);

	//setter
	void setPosition(float x, float y);
	void reduceHealth(int pDamage);
	void setDie(bool die){ m_die = die; }
	void setActiveBool(bool active);
	//getter
	int getHealth() const { return m_health; };
	int getDamage() const { return m_damage; };
	bool getDie() const { return m_die; }
	bool getActiveBool() const { return m_active; }

	sf::Sprite sprite;
private:
	void initDeath();
	void initHealthBar();
	void UpdateHealthBar();

	float m_speed;			///< the speed
	float m_xPos;			///< X-Position
	float m_yPos;			///< Y-Position

	int m_health;			///< actual health
	int m_maxHealth;		///< max amount of health;
	int m_damage;			///< Damage
	bool m_active;			///< if this is true-> it is active
	bool m_hasTargetTexture;///< true = is target | false = is not target
	bool m_die;				///< if this is true-> init death animation
	sf::Vector2f m_scale;	///< Scale to set smaller if death inits

	static sf::Texture m_texture;
	static sf::Texture m_healthTex;
	sf::RectangleShape m_healthbar;
};

#endif