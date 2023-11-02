#pragma once
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
enum class Scene {
	Title,
	Select,
	Game,
};
class Title;
class StageSelect;
class Game;
class PlayScene {
private:
	Scene scene = Scene::Title;
	static void (PlayScene::*pFuncTable[])();
	std::unique_ptr<Game> game;
	std::unique_ptr<Title> title;
	std::unique_ptr<StageSelect> select;

public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// ２D描画
	/// </summary>
	void Draw2d();
	/// <summary>
	/// ３D描画
	/// </summary>
	void Draw3d();

	/// <summary>
	/// タイトル
	/// </summary>
	void Title();
	/// <summary>
	/// ステージ選択
	/// </summary>
	void Select();
	/// <summary>
	/// ゲーム
	/// </summary>
	void Game();
};
