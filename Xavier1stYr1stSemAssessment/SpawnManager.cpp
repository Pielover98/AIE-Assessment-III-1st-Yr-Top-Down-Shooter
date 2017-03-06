//SpawnManager.cpp

#include "SpawnManager.h"

//spawns enemy
void SpawnManager::EnemySpawn(int &counter, std::vector<Enemy> &vector, std::vector<EnemyFormation> &enemyFormationv, int &randomX){
	if (counter >= 600 && enemyFormationv.size() == 0)	{
		randomX = (rand() % 800) + 1;
		Enemy enemyx;
		enemyx.SetPosition((float)randomX, -85.0f);
		vector.push_back(enemyx);
		counter = 0;
	}
}

//spawns enemy formation
void SpawnManager::EnemyFormationSpawn(int &counter, std::vector<EnemyFormation> &vector, std::vector<Boss2> &boss2v){
	if (counter >= 15000 && boss2v.size() == 0)	{
		EnemyFormation enemy0;
		EnemyFormation enemy1;
		EnemyFormation enemy2;
		EnemyFormation enemy3;
		EnemyFormation enemy4;
		EnemyFormation enemy5;
		EnemyFormation enemy6;
		EnemyFormation enemy7;
		EnemyFormation enemy8;
		EnemyFormation enemy9;

		enemy0.setPosition(0.0f, -280.0f);
		enemy9.setPosition(355.55556f, -245.0f);
		enemy8.setPosition(711.11112f, -280.0f);
		enemy1.setPosition(88.88889f, -245.0f);
		enemy7.setPosition(622.22223f, -245.0f);
		enemy2.setPosition(177.77778f, -210.0f);
		enemy6.setPosition(533.33334f, -210.0f);
		enemy3.setPosition(266.66667f, -175.0f);
		enemy5.setPosition(444.44445f, -175.0f);
		enemy4.setPosition(355.55556f, -140.0f);

		vector.push_back(enemy0);
		vector.push_back(enemy1);
		vector.push_back(enemy2);
		vector.push_back(enemy3);
		vector.push_back(enemy4);
		vector.push_back(enemy5);
		vector.push_back(enemy6);
		vector.push_back(enemy7);
		vector.push_back(enemy8);
		vector.push_back(enemy9);

		counter = 0;
	}
}

//spawns health drop
void SpawnManager::HealthDropSpawn(int &counter, std::vector<HealthDrop> &vector, int &randomX){
	if (counter >= 20000){
		randomX = (rand() % 800) + 1;
		HealthDrop healthx;
		healthx.SetPosition((float)randomX, -35.0f);
		vector.push_back(healthx);
		counter = 0;
	}
}

//spawns doggo
void SpawnManager::doggoSpawn(int &points, std::vector<doggo> &vector, std::vector<Boss2> &bossV){
	if (points > 1 && points % 300 == 0 && bossV.size() == 0)	{
		points += 10;
		doggo monkey;
		monkey.SetPosition(364, 25);
		vector.push_back(monkey);
	}
}

//spawns Shit (belongs to monkey)
void SpawnManager::ShitSpawn(int &counter, std::vector<doggo> &smVector, std::vector<bullets> &sVector, IngameSound &sound){
	for (unsigned int i = 0; i < smVector.size(); i++)	{
		if (smVector[i].getActiveBool() && counter >= 1500)		{
			bullets shitx;
			shitx.SetPosition(smVector[i].getPosition().x, smVector[i].getPosition().y);
			sound.PlaySound("fart");
			sVector.push_back(shitx);
			counter = 0;
		}
	}
}

//spawns first boss
void SpawnManager::Boss1Spawn(int &points, std::vector<Boss1> &vector){
	if (points > 1 && points > 2000 && points < 2025)	{
		points += 30;
		Boss1 Boss1x;
		vector.push_back(Boss1x);
	}
}

//spawns pew unlock perk
void SpawnManager::UnlockPewSpawn(bool &boss1Dead, std::vector<UnlockPew> &vector){
	if (boss1Dead){
		UnlockPew unlockPewx;
		unlockPewx.SetPosition(400, 100);
		vector.push_back(unlockPewx);
		boss1Dead = false;
	}
}

//spawns boss1 weapon
void SpawnManager::Boss1WeaponSpawn(int &counter, std::vector<Boss1Weapon> &bwVector, std::vector<Boss1> &bVector, IngameSound &sound){
	for (unsigned int i = 0; i < bVector.size(); i++)	{
		if (bVector[i].getActiveBool() && counter >= 1000)		{
			Boss1Weapon b1Weaponx;
			b1Weaponx.setPosition(bVector[i].getPosition().x, bVector[i].getPosition().y);
			sound.PlaySound("pew");
			bwVector.push_back(b1Weaponx);
			counter = 0;
		}
	}
}

//spawns camel
void SpawnManager::camelSpawn(int &counter, std::vector<camel> &vector, int &randomX, IngameSound &sound){
	if (counter >= 18000){
		randomX = (rand() % 300) + 1;
		camel camelx;
		camelx.setPosition((float)randomX, -305.0f);
		sound.PlaySound("camel");
		vector.push_back(camelx);
		counter = 0;
	}
}


//spawns bullet
void SpawnManager::BulletSpawn(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window){
	if (counter >= 175 && weapon.bulletA)	{
		Bullet bulletx(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(1);
		bulletx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(bulletx);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

//spawns bullet for player 2
void SpawnManager::BulletSpawn2(int &counter, std::vector<Bullet> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window){
	if (counter >= 175 && weapon.bulletA)	{
		Bullet bulletx(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(1);
		bulletx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(bulletx);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

// spawns doubleshot
void SpawnManager::DoubleShotSpawn(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, sf::RenderWindow& window){
	if (counter >= 300 && weapon.doubleA)	{
		DoubleShot doublex(player.getPosition().x, player.getPosition().y, window);
		DoubleShot doubley(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(2);
		doublex.SetPosition(player.getPosition().x - 12, player.getPosition().y);
		doubley.SetPosition(player.getPosition().x + 10, player.getPosition().y);
		vector.push_back(doublex);
		vector.push_back(doubley);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

//spawns doubleshot for player 2
void SpawnManager::DoubleShotSpawn2(int &counter, std::vector<DoubleShot> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, sf::RenderWindow& window){
	if (counter >= 300 && weapon.doubleA)	{
		DoubleShot doublex(player.getPosition().x, player.getPosition().y, window);
		DoubleShot doubley(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(2);
		doublex.SetPosition(player.getPosition().x - 12, player.getPosition().y);
		doubley.SetPosition(player.getPosition().x + 10, player.getPosition().y);
		vector.push_back(doublex);
		vector.push_back(doubley);
		sound.PlaySound("bulletShot");
		counter = 0;
	}
}

//spawns pew
void SpawnManager::PewSpawn(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window){
	if (weapon.pewA && !pewOnCooldown)	{
		Pew pewx(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(1);
		pewx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(pewx);
		sound.PlaySound("pew");
		pewOnCooldown = true;
	}
}

//spawns pew for player 2
void SpawnManager::PewSpawn2(std::vector<Pew> &vector, HighscoreManager &highscore, WeaponManager &weapon, Player2 &player, IngameSound &sound, bool &pewOnCooldown, sf::RenderWindow& window){
	if (weapon.pewA && !pewOnCooldown)	{
		Pew pewx(player.getPosition().x, player.getPosition().y, window);
		highscore.setShotsFired(1);
		pewx.SetPosition(player.getPosition().x - 4, player.getPosition().y);
		vector.push_back(pewx);
		sound.PlaySound("pew");
		pewOnCooldown = true;
	}
}

//spawns boss2
void SpawnManager::Boss2Spawn(std::vector<Boss2> &vector, int &points){
	if (points >= 2800 && points < 2899)	{
		Boss2 boss2x;
		boss2x.setPosition(400, -300);
		vector.push_back(boss2x);
		points += 100;
	}
}

void SpawnManager::Boss2WeaponSpawn(int &counter, std::vector<Boss2Weapon> &bwvector, std::vector<Boss2> &bvector){
	for (unsigned int i = 0; i < bvector.size(); i++)	{
		if (bvector[i].getActiveBool() && bvector[i].getfadeIn() && counter >= 2000){
			Boss2Weapon b2Wx;
			b2Wx.setPosition(bvector[i].getPosition().x, bvector[i].getPosition().y);
			bwvector.push_back(b2Wx);
			counter = 0;
		}
	}
}

void SpawnManager::Boss3Spawn(std::vector<Boss3> &vector, int &points, IngameSound &sound){
	if (points >= 4100 && points < 4109)	{
		Boss3 boss3x;
		sound.PlaySound("boss3spawn");
		vector.push_back(boss3x);
		points += 10;
	}
}

void SpawnManager::Boss3FirstWeaponSpawn(int &counter1, int &counter2, std::vector<Boss3firstWeapon> &vector, std::vector<Boss3> &bVector, IngameSound &sound){
	for (unsigned int i = 0; i < bVector.size(); i++)	{
		if (bVector[i].getActiveBool() && bVector[i].getCurrentState() == 1.5 && bVector[i].getHead1Active() && counter1 >= 1500){ //left Spawner
			Boss3firstWeapon b3Wx1;
			b3Wx1.setPosition(bVector[i].getHead1XPosition() + 50, bVector[i].getHead1YPosition() + 50);
			vector.push_back(b3Wx1);
			counter1 = 0;
		}

		if (bVector[i].getActiveBool() && bVector[i].getCurrentState() == 1.5 && bVector[i].getHead2Active() && counter2 >= 1500){ //right Spawner
			Boss3firstWeapon b3Wx2;
			b3Wx2.setPosition(bVector[i].getHead2XPosition() + 50, bVector[i].getHead2YPosition() + 50);
			vector.push_back(b3Wx2);
			counter2 = 0;
		}
	}
}

void SpawnManager::Boss3SecWeaponSpawn(int &counter, std::vector<Boss3SecWeapon> &vector, std::vector<Boss3> &bVector, IngameSound &sound){
	for (unsigned int i = 0; i < bVector.size(); i++)	{
		if (bVector[i].getActiveBool() && bVector[i].getCurrentState() == 2.5 && bVector[i].getcamelMActive() && counter >= 1500){
			Boss3SecWeapon b3Wx;
			b3Wx.setPosition(bVector[i].getcamelMXPosition() + 50, bVector[i].getcamelMYPosition() + 50);
			vector.push_back(b3Wx);
			counter = 0;
		}
	}
}