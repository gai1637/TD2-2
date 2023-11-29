#include "Player.h"
#include"TextureManager.h"
Player::~Player() {
	delete model_;
	
}
void Player::Initialize() { 
	textureHandle_ = TextureManager::Load("car.png");
	model_ = Model::Create();
	worldtransform_.scale_ = {2.f, 2.f, 0.001f};
	worldtransform_.translation_ = {0, 5, 0};
	worldtransform_.Initialize();
	input_ = Input::GetInstance();
	speed_ = {0, 0};
	prepos = worldtransform_.translation_;
	junp = false;
	geat = false;
}
void Player::PreMove() {

	if (!geat&&!Geat) {
		if (input_->TriggerKey(DIK_W)&&!junp) {
			geat = true;
		}
		if (input_->TriggerKey(DIK_S)&&!junp) {
			Geat = true;
		}

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
		if (input_->TriggerKey(DIK_SPACE) && !junp) {
			prepos.y += 0.1f;
			speed_.y = 2;
			junp = true;
		}

		speed_.y -= 0.1f;

		prepos.x += speed_.x;
		prepos.y += speed_.y;
	}
	if (geat){
		if (prepos.z < 60) {
			prepos.z++;
			worldtransform_.translation_.z++;
		}
		if (prepos.z == 60) {
			geat = false;
		}
	}if (Geat){
		if (prepos.z > 0) {
			prepos.z--;
			worldtransform_.translation_.z--;
		}
		if (prepos.z == 00) {
			Geat = false;
		}
	}
}
void Player::Update() {
	
	worldtransform_.translation_.x = prepos.x;
	worldtransform_.translation_.y = prepos.y;
	if (worldtransform_.translation_.y <= -60) {
		PosReset();
	}
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
void Player::PosReset() {
	worldtransform_.translation_ = {0, 5, 0};
	prepos = worldtransform_.translation_;
}
void Player::Draw(const ViewProjection& viewProjection) {
	model_->Draw(worldtransform_, viewProjection, textureHandle_);
}