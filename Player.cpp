﻿#include "Player.h"
#include"TextureManager.h"
Player::~Player() {
	delete model_;
	
}
void Player::Initialize() { 
	textureHandle_ = TextureManager::Load("white1x1.png");
	model_ = Model::Create();
	worldtransform_.scale_ = {2.f, 2.f, 0};
	worldtransform_.translation_ = {0, 5, 0};
	worldtransform_.Initialize();
	input_ = Input::GetInstance();
	speed_ = {0, 0};
	prepos = worldtransform_.translation_;
	junp = false;
}
void Player::PreMove() {
	if (input_->PushKey(DIK_D)) {
		if (speed_.x <= 1) {
			speed_.x += 0.1f;
		}

	} else if (input_->PushKey(DIK_A)) {
		if (speed_.x >= -1) {
			speed_.x -= 0.1f;
		}
	} else {
		speed_.x = 0;
	}
	if (input_->TriggerKey(DIK_SPACE)&&!junp) {
		prepos.y += 0.1f;
		speed_.y = 2;
		junp = true;
	}
	
	speed_.y -= 0.1f;
	
	prepos.x += speed_.x;
	prepos.y += speed_.y;
}
void Player::Update() {
	
	worldtransform_.translation_.x = prepos.x;
	worldtransform_.translation_.y = prepos.y;

	worldtransform_.UpdateMatrix();


}
void Player::OnCollision() { 
	
	prepos.y +=0.1f;
	speed_.y = 0;
	junp = false;
	

}
void Player::LCollision() { 

	prepos.x +=0.1f;
	speed_.x = 0;

}
void Player::RCollision() { 

	prepos.x -=0.1f;
	speed_.x = 0;

}

void Player::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldtransform_, viewProjection, textureHandle_);
}