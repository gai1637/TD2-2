#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"PlayScene.h"

GameScene::GameScene() {}

GameScene::~GameScene() {}

void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();
	play = std::make_unique<PlayScene>();
	play->Initialize();
	viewProjection_.translation_.x = 0;
	viewProjection_.translation_.y = -11;
	viewProjection_.translation_.z = -60;
	viewProjection_.Initialize();
	
}

void GameScene::Update() { 
	play->Update(); 
//if (input_->PushKey(DIK_W)) {
//		viewProjection_.translation_.y+=0.5f;
//	}
//if (input_->PushKey(DIK_A)) {
//		viewProjection_.translation_.x-=0.5f;
//	}
//if (input_->PushKey(DIK_S)) {
//		viewProjection_.translation_.y-=0.5f;
//	}
//if (input_->PushKey(DIK_D)) {
//		viewProjection_.translation_.x+=0.5f;
//	}
if (input_->PushKey(DIK_SPACE)) {
		viewProjection_.translation_.z -= 0.5;
	}
if (input_->PushKey(DIK_UP)) {
		viewProjection_.translation_.z ++;
	}
if (input_->PushKey(DIK_DOWN)) {
		viewProjection_.translation_.z --;

}
		viewProjection_.UpdateMatrix();
	ImGui::Begin("a");
	ImGui::Text(
	    "%f,%f,%f", viewProjection_.translation_.x, viewProjection_.translation_.y,
	    viewProjection_.translation_.z

	);
	ImGui::End();

}

void GameScene::Draw() {

	// コマンドリストの取得
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

#pragma region 背景スプライト描画
	// 背景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに背景スプライトの描画処理を追加できる
	/// </summary>
	play->Draw2d();

	// スプライト描画後処理
	Sprite::PostDraw();
	// 深度バッファクリア
	dxCommon_->ClearDepthBuffer();
#pragma endregion

#pragma region 3Dオブジェクト描画
	// 3Dオブジェクト描画前処理
	Model::PreDraw(commandList);

	/// <summary>
	/// ここに3Dオブジェクトの描画処理を追加できる
	/// </summary>
	play->Draw3d(viewProjection_);

	// 3Dオブジェクト描画後処理
	Model::PostDraw();
#pragma endregion

#pragma region 前景スプライト描画
	// 前景スプライト描画前処理
	Sprite::PreDraw(commandList);

	/// <summary>
	/// ここに前景スプライトの描画処理を追加できる
	/// </summary>
	


	// スプライト描画後処理
	Sprite::PostDraw();

#pragma endregion
}
