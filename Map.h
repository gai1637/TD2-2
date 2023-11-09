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
	/// ‰Šú‰»
	/// </summary>
	void Initialize(int a,int b,int c,int d);

	/// <summary>
	/// –ˆƒtƒŒ[ƒ€ˆ—
	/// </summary>
	void Update();

	/// <summary>
	/// •`‰æ
	/// </summary>
	void Draw(const ViewProjection& viewprojection);
};
