#include "Game.h"
#include"Map.h"
void Game::Initialize() { 
	for (int a = 0; a < maphigh; a++) {
		for (int b = 0; b < mapwide; b++) {
			if (mapmain1[a][b]!=0) {
				Map* newmap = new Map();
				newmap->Initialize(mapmain1[a][b], a, b, 0);
				maps.push_back(newmap);
			}
			
		}
	}


}
void Game::Update() { 
	
	for (Map* map : maps) {
		map->Update();
	} 




}
void Game::Draw(const ViewProjection& viewProjection) { 
	for (Map* map : maps) {
		map->Draw(viewProjection);
	}
}