#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Player;
class Enemy;
class Bullet;
class Actor;

class Game
{
public:
	Game();
	bool Initialize();
	void RunLoop();

	void Shutdown();

	Player* GetPlayer() { return player; }
	std::vector<Actor*> GetActors() { return actors; }

	sf::Texture& GetShipTexture() { return shipsTexture; }
	sf::Texture& GetProjectileTexture() { return projectilTexture; }
	sf::Texture& GetBackGroundTexture() { return BackGroundsTexture; }

private:
	void InitializeGame();

	void ProcessInput();

	void UpdateGame();
	void SpawnBullet(float dt);
	void CheckCollision();

	void DrawGame();

private:
	int screenWidth = 1600;
	int screenHeight = 900;
	sf::RenderWindow window{ sf::VideoMode(screenWidth, screenHeight), "CPP Game" };

	std::vector<Actor*> actors;

	Player* player;

	sf::Texture shipsTexture;
	sf::Texture projectilTexture;
	sf::Texture BackGroundsTexture;

	float bulletFirePeriod;
	float bulletFireTimer;

	sf::Clock deltaClock;
};