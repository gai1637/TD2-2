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
	/// ������
	/// </summary>
	void Initialize(int a,int b,int c,int d);

	/// <summary>
	/// ���t���[������
	/// </summary>
	void Update();

	/// <summary>
	/// �`��
	/// </summary>
	void Draw(const ViewProjection& viewprojection);
};
