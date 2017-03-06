

#ifndef _COLLISION_H
#define _COLLISION_H

#include <vector>
#include "EntityIncludes.h"
#include "IngameSfx.h"
#include "HighscoreManager.h"

namespace coll{
	
	template <class Object, class ObjectList>
	void ProjectileToList(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore)	{
		//collision detection for normal enemies
		for (unsigned int i = 0; i < objList.size(); i++)		{
			if (objList[i].getActiveBool())			{
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds()))				{
					if (!obj->getIsPew())
						obj->setActiveBool(false);

					highscore.setShotsGot(1);
					points += 5;
					sound.PlaySound("enemyCollision");
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						objList[i].setDie(true);
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}
	template <class Object, class ObjectList>
	void ProjectileTodoggo(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore){
		//collision detection for doggo (got a seperate to count doggo kills)
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					if (!obj->getIsPew())
						obj->setActiveBool(false);
					
					sound.PlaySound("enemyCollision");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
						objList[i].setDie(true);
						points += 20;
						highscore.setdoggoKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void ProjectileToListNoHealth(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager &highscore){
		//Collision detection for things with no health
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					if (!obj->getIsPew())
						obj->setActiveBool(false);
					
					objList[i].setActiveBool(false);
					points += 5;
					sound.PlaySound("enemyCollision");
					highscore.setEnemyKilled(1);
					highscore.setShotsGot(1);
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void BossCollision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore, bool &bossy1Dead){
		//Boss 1 Collision detection
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					obj->setActiveBool(false);
					sound.PlaySound("bossy1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
						objList[i].setActiveBool(false);
						points += 20;
						highscore.setEnemyKilled(1);
						bossy1Dead = true;
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void bossy2Collision(Object &obj, std::vector<ObjectList> &objList, int &points, IngameSound &sound, HighscoreManager&highscore){
		//Boss 2 Collision detection
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (obj->sprite.getGlobalBounds().intersects(objList[i].sprite.getGlobalBounds())){
					obj->setActiveBool(false);
					sound.PlaySound("bossy1Hit");
					highscore.setShotsGot(1);
					objList[i].reduceHealth(obj->getDamage());
					if (objList[i].getHealth() <= 0){
						sound.PlaySound("bossDeath");
						objList[i].setActiveBool(false);
						points += 20;
						highscore.setEnemyKilled(1);
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyInactive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound)	{
		//player collision with Enemies <- Enemies are set inactive if collision appeares
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (unsigned int i = 0; i < objList.size(); i++)		{
			if (objList[i].getActiveBool())
			{
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objList[i].setActiveBool(false);
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0){
						pPlayer.setActiveBool(false);
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerEnemyActive(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound){
		//player collision with Enemies which shall not be set inactive after collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (objList[i].sprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					pPlayer.reduceHealth(objList[i].getDamage());
					sound.PlaySound("playerCollision");
					if (pPlayer.getHealth() <= 0){
						pPlayer.setActiveBool(false);
						sound.PlaySound("playerDeath");
					}
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerHealthGet(std::vector<ObjectList> &objList, Object &pPlayer, IngameSound &sound){
		//HealthDrop Collision
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (unsigned int i = 0; i < objList.size(); i++){
			if (objList[i].getActiveBool()){
				if (objList[i].healthDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objList[i].setActiveBool(false);
					sound.PlaySound("healthDrop");
					pPlayer.increaseHealth(20);
				}
			}
		}
	}

	template <class Object, class ObjectList>
	void PlayerUnlockBoomy(std::vector<ObjectList> &objectList, Object &pPlayer, IngameSound &sound, bool &gotPew, bool &pewOnCooldown){
		//Player Collision to unlock the third weapon
		sf::Sprite pSprite = pPlayer.playerSprite;
		for (unsigned int i = 0; i < objectList.size(); i++)	{
			if (objectList[i].getActiveBool()){
				if (objectList[i].pewDropSprite.getGlobalBounds().intersects(pSprite.getGlobalBounds())){
					objectList[i].setActiveBool(false);
					sound.PlaySound("healthDrop");
					gotPew = true;
					pewOnCooldown = true;

					if (pPlayer.getHealth() <= 100)
						pPlayer.increaseHealth(100);
				}
			}
		}
	}
	template <class Object>
	void bossy3Collision(std::vector<bossy3> &bossy3v, Object &obj, IngameSound &sound, HighscoreManager &highscore, int &points, bool &bossy3dead){
		//bossy3 collision weapon to bossy3
		for (unsigned int i = 0; i < bossy3v.size(); i++){
			//collision for first state
			if (bossy3v[i].getCurrentState() == 1.5){
				//collision for left Spawner
				if (bossy3v[i].getHead1Active()){
					if (obj->sprite.getGlobalBounds().intersects(bossy3v[i].headSprite1.getGlobalBounds())){
						obj->setActiveBool(false);
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						bossy3v[i].setHead1Position(bossy3v[i].getHead1XPosition(), bossy3v[i].getHead1YPosition() - 2);
					}
				}

				//collision for right spawner
				if (bossy3v[i].getHead2Active()){
					if (obj->sprite.getGlobalBounds().intersects(bossy3v[i].headSprite2.getGlobalBounds()))
					{
						obj->setActiveBool(false);
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						bossy3v[i].setHead2Position(bossy3v[i].getHead2XPosition(), bossy3v[i].getHead2YPosition() -2);
					}
				}
			}
//_____________________________________________________________________________________________________________________________________
			if (bossy3v[i].getCurrentState() == 2.5){
				//collision for camel spawner
				if (bossy3v[i].getcamelMActive()){
					if (obj->sprite.getGlobalBounds().intersects(bossy3v[i].camelSprite.getGlobalBounds())){
						obj->setActiveBool(false);
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						bossy3v[i].setcamelMPosition(bossy3v[i].getcamelMXPosition(), bossy3v[i].getcamelMYPosition() -2);
					}
				}
			}
//_____________________________________________________________________________________________________________________________________
			if (bossy3v[i].getCurrentState() >= 3 && bossy3v[i].getCurrentState() <= 4){
				if (bossy3v[i].getActiveBool()){
					if (obj->sprite.getGlobalBounds().intersects(bossy3v[i].sprite.getGlobalBounds())){
						obj->setActiveBool(false);
						sound.PlaySound("enemyCollision");
						highscore.setShotsGot(1);
						bossy3v[i].reduceHealth(obj->getDamage());
						if (bossy3v[i].getGoneDead()){
							sound.PlaySound("bossy3death");
							bossy3dead = false;
							points += 150;
						}
					}
				}
			}
		}
	}
}

#endif