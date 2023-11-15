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
private:
	int a_;
	WorldTransform worldtransform_;
	ViewProjection viewprojection_;
	uint32_t textureHandle_;
	Model* model_;

public:
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
	Vector3 retunPos() { return worldtransform_.translation_; }
	int retunA() { return a_; }
};
