﻿#pragma once
#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include<memory>
class Map;
const int mapwide = 10;
const int maphigh = 5;
class Game {
private:
	std::list<Map*> maps; 
	int mapmain[maphigh][mapwide];

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
	void Draw(const ViewProjection& viewprojection);
};
