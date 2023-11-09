#include "Map.h"
#include"TextureManager.h"
Map::~Map() { delete model_; }

void Map::Initialize(int a, int b, int c, int d) { 
	a_ = a;
	if (a != 0) {
		textureHandle_ =TextureManager::Load("white1x1.png");
		model_ = Model::Create();
	}
	worldtransform_.translation_.x = b * 80;
	worldtransform_.translation_.y = c * 80;
	worldtransform_.translation_.z = d;

}
void Map::Update() { 
	if (a_ != 0) {
		worldtransform_.UpdateMatrix();
	}
}
void Map::Draw(const ViewProjection& viewprojection) { 
	model_->Draw(worldtransform_, viewprojection, textureHandle_);
}