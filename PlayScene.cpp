#include "PlayScene.h"
#include"Game.h"
#include"Title.h"
#include"StageSelect.h"
PlayScene::~PlayScene() { 
	/*delete select;*/
	delete game;
	/*delete title;*/
}
void (PlayScene::*PlayScene::pFuncTable[])() = {
	&PlayScene::TitleF,
	&PlayScene::SelectF,
	&PlayScene::GameF
};
//初期化、
void PlayScene::Initialize() {
	game = new Game;
	game->Initialize();
	
	/*title = new Title;
	title->Initialize();

	select= new StageSelect;
	select->Initialize();*/
}
    //アップデート、ここにはこれ以外書かないこと
void PlayScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 
}
//タイトル処理
void PlayScene::TitleF() { /*title->Update();*/ }
//ステージセレクトの処理
void PlayScene::SelectF() {/* select->Update();*/ }
//ゲーム本体の処理
void PlayScene::GameF() { game->Update(); }

// ２D描画
void PlayScene::Draw2d() {

}

///３D描画

void PlayScene::Draw3d(const ViewProjection& viewProjection) { 
	game->Draw(viewProjection); }