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
	/// ������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw();
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
