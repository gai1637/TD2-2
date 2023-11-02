#include "PlayScene.h"
void (PlayScene::*PlayScene::pFuncTable[])() = {
	&PlayScene::Title,
	&PlayScene::Select,
	&PlayScene::Game
};
//アップデート、ここにはこれ以外書かないこと
void PlayScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 
}
//タイトル処理
void PlayScene::Title() {}
//ステージセレクトの処理
void PlayScene::Select() {}
//ゲーム本体の処理
void PlayScene::Game() {}
