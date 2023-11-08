#include "Game.h"
#include"Map.h" 
void Game::Initialize() {

}

void Game::Update() {



	for (Map* map : maps) {
		map->Update();
	}
}

void Game::Draw(const ViewProjection& viewprojection) {

	for (Map* map : maps) {
		map->Draw(viewprojection);
	} 

}