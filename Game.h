#pragma once
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include"ViewProjection.h"
#include "WinApp.h"
class Map;
class Player;
class Map1;
class Map2;
class Map3;
class Game {
private:
	std::list<Map*> maps;
	static const int mapwide=160;
	static const int maphigh=9;
	int mapmain1[maphigh][mapwide];
	int mapmain2[maphigh][mapwide];
	Player*player;
	ViewProjection viewProjection_;
	uint32_t stage;
	Map1* map1;
	Map2* map2;
	Map3* map3;
	uint32_t haikei=0;
	Sprite* sprite_=nullptr;
	uint32_t setumei=0;
	Sprite* setumeisprite_=nullptr;
	Audio* audio_ = nullptr;
	bool resetFalg;
	uint32_t soundDataHandle_ = 0;
	uint32_t crearpng;
	Sprite* crearsprite_=nullptr;
	bool crearflag;

public:
	~Game();
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
	void HaikeiDraw();
	void Collision();
	void MapReset();
};
