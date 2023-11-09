#pragma once
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "ViewProjection.h"
#include<memory>
enum class Scene {
	title,
	select,
	game,
};
class Title;
class StageSelect;
class Game;
class PlayScene {
private:
	Scene scene = Scene::title;
	static void (PlayScene::*pFuncTable[])();
	Game* game;
	Title* title;
	StageSelect* select;

public:
	~PlayScene();
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
	void Draw3d(const ViewProjection& viewProjection);

	/// <summary>
	/// タイトル
	/// </summary>
	void TitleF();
	/// <summary>
	/// ステージ選択
	/// </summary>
	void SelectF();
	/// <summary>
	/// ゲーム
	/// </summary>
	void GameF();
};
