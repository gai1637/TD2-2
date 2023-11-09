#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include<memory>
class Map {
public:
	int a_;
	WorldTransform worldtransform_;
	ViewProjection viewprojection_;
	uint32_t textureHandle_;
	Model* model_;

private:
	~Map();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(int a,int b,int c,int d);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(const ViewProjection& viewprojection);
};
