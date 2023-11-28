#include "Game.h"
#include"Map.h"
#include"Player.h"
#include"Map1.h"
Game::~Game() { delete player; 
for (Map* map : maps) {
		delete map;
	}
delete map1;
}
void Game::Initialize() { 
	stage = 0;
map1 = new Map1;
	for (int a = 0; a < maphigh; a++) {
		for (int b = 0; b < mapwide; b++) {
			mapmain1[a][b] = map1->map1[a][b];
			if (mapmain1[a][b]!=0) {
				Map* newmap = new Map();
				newmap->Initialize(mapmain1[a][b], a, b, 0);
				maps.push_back(newmap);
			}
			
		}
	}
	for (int a = 0; a < maphigh; a++) {
		for (int b = 0; b < mapwide; b++) {
			mapmain2[a][b] = map1->map2[a][b];
			if (mapmain2[a][b]!=0) {
				Map* newmap = new Map();
				newmap->Initialize(mapmain2[a][b], a, b, 60);
				maps.push_back(newmap);
			}
			
		}
	}
	player = new Player;
	player->Initialize();
	viewProjection_.translation_.x = 0;
	viewProjection_.translation_.y = -11;
	viewProjection_.translation_.z = -60;
	viewProjection_.Initialize();
}
void Game::Update() { 
	
	for (Map* map : maps) {
		map->Update();
	} 
	player->PreMove();
	Collision();
	player->Update();
	viewProjection_.translation_.x = player->retunPos().x;
	viewProjection_.translation_.z = player->retunPos().z - 60;
	viewProjection_.UpdateMatrix();

}
void Game::Collision() {
	for (Map* map : maps) {
		if (map->retunA() == 1) {

			float dx = abs(player->retunPos().x - map->retunPos().x);
			float dy = abs(player->retunPos().y - map->retunPos().y);
			float dz = abs(player->retunPos().z - map->retunPos().z);
			if (dz < 4) {
			if (dx < 3 && dy < 4) {
				while (dy < 4) {

					player->OnCollision();
					dy = abs(player->retunPos().y - map->retunPos().y);
				}
			}
			if (dx < 4 && dy < 3) {
				if (player->retunPos().x > map->retunPos().x) {

					while (dx < 4) {
						player->LCollision();
						dx = abs(player->retunPos().x - map->retunPos().x);
					}
				} else {
					while (dx < 4) {
						player->RCollision();
						dx = abs(player->retunPos().x - map->retunPos().x);
					}
				}

			}
			
			}
		}
	}
}
void Game::Draw() { 
	for (Map* map : maps) {
		map->Draw(viewProjection_);
	}
	player->Draw(viewProjection_);
}