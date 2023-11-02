#include "PlayScene.h"
#include"Game.h"
#include"Title.h"
#include"StageSelect.h"
void (PlayScene::*PlayScene::pFuncTable[])() = {
	&PlayScene::Title,
	&PlayScene::Select,
	&PlayScene::Game
};
//�������A
void PlayScene::Initialize() {

	game->Initialize();
	title->Initialize();
	select->Initialize();
}
    //�A�b�v�f�[�g�A�����ɂ͂���ȊO�����Ȃ�����
void PlayScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 
}
//�^�C�g������
void PlayScene::Title() { title->Update(); }
//�X�e�[�W�Z���N�g�̏���
void PlayScene::Select() { select->Update(); }
//�Q�[���{�̂̏���
void PlayScene::Game() { game->Update(); }

// �QD�`��
void PlayScene::Draw2d() {

}

///�RD�`��

void PlayScene::Draw3d() {

}