#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
class Map {
private:
	int size;
	int a_;
	uint32_t textureHandle_ = 0;
	Model* model_ = nullptr;
	WorldTransform worldtransform_;
	ViewProjection viewprojection_;

public:
	~Map();
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize(int a);

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw(const ViewProjection& viewprojection);

};
