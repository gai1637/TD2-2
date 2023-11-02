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
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �QD�`��
	/// </summary>
	void Draw2d();
	/// <summary>
	/// �RD�`��
	/// </summary>
	void Draw3d();

	/// <summary>
	/// �^�C�g��
	/// </summary>
	void Title();
	/// <summary>
	/// �X�e�[�W�I��
	/// </summary>
	void Select();
	/// <summary>
	/// �Q�[��
	/// </summary>
	void Game();
};
