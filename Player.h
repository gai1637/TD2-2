#pragma once
#include "Audio.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include"ImGuiManager.h"
#include<memory>
class Player {
private:
	WorldTransform worldtransform_;
	Vector3 prepos;
	uint32_t textureHandle_;
	Model* model_;
	Input* input_;
	Vector2 speed_;
	bool junp;
	bool geat;
	bool Geat;

public:
	~Player();
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
	void Draw(const ViewProjection& viewProjection);
	void PreMove();
	Vector3 retunPos() { return prepos; }
	void OnCollision();
	void LCollision();
	void RCollision();
	bool Returngeat() { return geat; }
	bool ReturnGeat() { return Geat; }

	/*void SetCollision(bool collision) { this->collision = collision; }*/

};
