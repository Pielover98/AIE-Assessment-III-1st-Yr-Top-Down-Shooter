

#include "Boss3SecWeapon.h"


sf::Texture Boss3SecWeapon::m_weaponTex;
sf::Texture Boss3SecWeapon::m_healthTex;

Boss3SecWeapon::Boss3SecWeapon(){
	
	//Read settings
	IOdiff diff;
	m_diff = diff.ReadDiffSettings();
	IOsmooth smooth;

	//init stuff
	m_speed = 0.5f;
	m_active = true;
	m_die = false;
	m_health = 3;
	m_maxHealth = m_health;
	m_hasTargetTexture = false;

	m_weaponTex.loadFromFile("graphics/enemies/smallcamel.png");
	m_weaponTex.setSmooth(smooth.ReadSmoothSettings());
	sprite.setTexture(m_weaponTex);
	sprite.setOrigin(23.5, 12);

	//initialize Healthbar
	initHealthBar();
}

void Boss3SecWeapon::Update(sf::RenderWindow &window, float &elapsedTime){
	if (m_active){
		m_xPos = sprite.getPosition().x;
		m_yPos = sprite.getPosition().y;

		if (m_yPos <= window.getSize().y)
			m_yPos += m_speed*elapsedTime;
		
		else
			m_active = false;
		
		//Update Healthbar
		UpdateHealthBar();

		//do the rest
		sprite.setPosition(m_xPos, m_yPos);

		//see if death should be initialized
		m_scale = sprite.getScale();
		initDeath();
	}
}

void Boss3SecWeapon::Render(sf::RenderWindow &window){
	if (m_active){

		//check for mouseOver
		if (sprite.getGlobalBounds().intersects(sf::Rect<float>((float)sf::Mouse::getPosition(window).x, (float)sf::Mouse::getPosition(window).y + 1.0f, 1.0f, 1.0f))){
			if (!m_hasTargetTexture){
				m_weaponTex.loadFromFile("raphics/enemies/smallcamel_target.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = true;
			}
		}
		else{
			if (m_hasTargetTexture){
				m_weaponTex.loadFromFile("raphics/enemies/smallcamel.png");
				sprite.setTexture(m_weaponTex);
				m_hasTargetTexture = false;
			}
		}

		window.draw(sprite);
		window.draw(m_healthbar);
	}
}

void Boss3SecWeapon::setPosition(float x, float y){
	sprite.setPosition(x, y);
}

void Boss3SecWeapon::reduceHealth(int pDamage){
	m_health -= pDamage;
}

//Healthbar init
void Boss3SecWeapon::initHealthBar(){

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
void Boss3SecWeapon::UpdateHealthBar(){

	//first set the Position of the Shape
	m_healthbar.setPosition(m_xPos, (m_yPos - 10.0f - sprite.getLocalBounds().height / 2)); ///< see how it behaves with origin

	//get the percentage of health to find out how much should be shown in shape
	float percentage = m_health * 100.0f / m_maxHealth;

	//get the length of pixels to be shown
	float showAmount = m_healthTex.getSize().x - (m_healthTex.getSize().x * percentage / 100.0f);

	//set the Texture Rect that has to be shown
	m_healthbar.setTextureRect(sf::IntRect((int)showAmount, 0, m_healthTex.getSize().x, m_healthTex.getSize().y));
}

void Boss3SecWeapon::initDeath(){
	if (m_die){
		sprite.rotate(5);
		m_scale.x -= 0.01f;
		m_scale.y -= 0.01f;
		sprite.setScale(sf::Vector2f(m_scale.x, m_scale.y));

		if (m_scale.x <= 0.05f || m_scale.y <= 0.05f){
			m_active = false;
		}
	}
}

//sets the entity active or inactive
void Boss3SecWeapon::setActiveBool(bool active){
	m_active = active;
}