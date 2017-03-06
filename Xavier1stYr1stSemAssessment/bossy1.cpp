

#include "bossy1.h"

sf::Texture bossy1::m_enemyTex;
sf::Texture bossy1::m_healthTex;

bossy1::bossy1(){
	//get settings
	IOdiff diff;
	IOsmooth smooth;

	//init stuff
	m_hasTargetTexture = false;
	m_active = true;
	m_moveLeft = true;

	m_speed = 0.4f;
	m_health = 50 * diff.ReadDiffSettings();
	m_maxHealth = m_health;

	m_enemyTex.loadFromFile("graphics/enemies/piggy.png");
	m_enemyTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_enemyTex);
	sprite.setOrigin(m_enemyTex.getSize().x / 2.0f, m_enemyTex.getSize().y / 2.0f);
	sprite.setPosition(400.0f, -300.0f);

	//initialize Healthbar
	initHealthBar();
}
void bossy1::Update(sf::RenderWindow &window, float elapsedTime){

	if (m_active){

		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		//fade in
		if (m_yPos <= 120.0f){
			m_yPos += (m_speed * elapsedTime) / 3.0f;
		}
			
		if (m_yPos <= 200.0f){
			m_yPos += m_speed * elapsedTime;
		}
		
		//move left
		if (m_moveLeft && m_xPos > 75.0f){
			m_xPos -= m_speed * elapsedTime;
		}
		else{
			m_moveLeft = false;
		}

		//move right
		if (!m_moveLeft && m_xPos < window.getSize().x - 75.0f){
			m_xPos += m_speed * elapsedTime;
		}
		else{
			m_moveLeft = true;
		}
			
	//Update Healthbar
	UpdateHealthBar();

	sprite.setPosition(m_xPos, m_yPos);
	}
}


void bossy1::Render(sf::RenderWindow &window){
	if (m_active){
		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void bossy1::SetPosition(float x, float y){
	sprite.setPosition(x, y);
}

void bossy1::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Healthbar init
void bossy1::initHealthBar(){

	//load Texture
	if (!m_healthTex.loadFromFile("graphics/enemies/health.png")){
		perror("could not load enemy healthbar");
	}

	//set texture
	m_healthbar.setTexture(&m_healthTex);

	//set size of shape to the size of the texture
	m_healthbar.setSize(sf::Vector2f((float)m_healthTex.getSize().x, (float)m_healthTex.getSize().y));

	//pseudo rect
	m_healthbar.setTextureRect(sf::IntRect(0, 0, 0, 0));
}

//Healthbar Update
void bossy1::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}

//sets the entity active or inactive
void bossy1::setActiveBool(bool active){
	m_active = active;
}