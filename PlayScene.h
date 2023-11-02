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
class PlayScene {
private:
	Scene scene = Scene::Title;
	static void (PlayScene::*pFuncTable[])();

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
	/// 描画
	/// </summary>
	void Draw();
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
