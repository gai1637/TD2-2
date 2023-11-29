#include "Map.h"
#include"TextureManager.h"
Map::~Map() { delete model_; }

void Map::Initialize(int a, int b, int c, int d) { 
	a_ = a;
	if (a ==0) {
		textureHandle_ =TextureManager::Load("stone.png");
		model_ = Model::Create();
	}
	if (a ==1) {
		textureHandle_ =TextureManager::Load("stone.png");
		model_ = Model::Create();
	}
	if (a == 2) {
	textureHandle_ =TextureManager::Load("goal.png");
		model_ = Model::Create();
	}
	
	
	worldtransform_.scale_ = {2,2,2};
	worldtransform_.translation_.x = (float)c * 4;
	worldtransform_.translation_.y = -(float)b * 4;
	worldtransform_.translation_.z = (float)d;
	worldtransform_.Initialize();
	

}
void Map::Update() { 
	if (a_ != 0) {

		worldtransform_.UpdateMatrix();
	}
}
void Map::Draw(const ViewProjection& viewprojection) { 
	if (a_ != 0) {
		model_->Draw(worldtransform_, viewprojection, textureHandle_);
	}
}