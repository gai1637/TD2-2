#include "Map.h"
#include"TextureManager.h"
Map::~Map() { delete model_; }

void Map::Initialize(int a, int b, int c, int d) { 
	a_ = a;
	if (a != 0) {
		textureHandle_ =TextureManager::Load("uvChecker.png");
		model_ = Model::Create();
	}
	
	
	worldtransform_.scale_ = {1,1,1};
	worldtransform_.translation_.x = (float)c * 2;
	worldtransform_.translation_.y = (float)b * 2;
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