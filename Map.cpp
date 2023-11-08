#include "Map.h"
#include"TextureManager.h"
Map::~Map() { delete model_; }
void Map::Initialize(int a) { 
	a_ = a; 
	textureHandle_ = TextureManager::Load("white1x1.png");
	model_->Model::Create();
	worldtransform_.Initialize();
	viewprojection_.Initialize();
}
void Map::Update() { worldtransform_.UpdateMatrix();}
void Map::Draw(const ViewProjection& viewprojection) { 
	model_->Draw(worldtransform_,viewprojection,textureHandle_); 
}