#include "PlayScene.h"
void (PlayScene::*PlayScene::pFuncTable[])() = {
	&PlayScene::Title,
	&PlayScene::Select,
	&PlayScene::Game
};
//�A�b�v�f�[�g�A�����ɂ͂���ȊO�����Ȃ�����
void PlayScene::Update() { 
	(this->*pFuncTable[static_cast<size_t>(scene)])(); 
}
//�^�C�g������
void PlayScene::Title() {}
//�X�e�[�W�Z���N�g�̏���
void PlayScene::Select() {}
//�Q�[���{�̂̏���
void PlayScene::Game() {}
