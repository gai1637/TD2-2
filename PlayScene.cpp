#include "PlayScene.h"
#include"Game.h"
#include"Title.h"
#include"StageSelect.h"
void (PlayScene::*PlayScene::pFuncTable[])() = {
	&PlayScene::Title,
	&PlayScene::Select,
	&PlayScene::Game
};
//初期化、
void PlayScene::Initialize() {

	game->Initialize();
	title->Initialize();
	select->Initialize();
}
    //アップデート、ここにはこれ以外書かないこと
void PlayScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 
}
//タイトル処理
void PlayScene::Title() { title->Update(); }
//ステージセレクトの処理
void PlayScene::Select() { select->Update(); }
//ゲーム本体の処理
void PlayScene::Game() { game->Update(); }

// ２D描画
void PlayScene::Draw2d() {

}

///３D描画

void PlayScene::Draw3d() {

}