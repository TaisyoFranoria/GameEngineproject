#include"AnimationEngine2D.h"

//�R���X�g���N�^�c�I�u�W�F�N�g���쐬�����ۂ̏����������i���ۂ̏�����init()�ōs���Ă���j
AnimationEngine2D::AnimationEngine2D() {
	init();
}

//�f�X�g���N�^�c�I�u�W�F�N�g�����ł���ۂ̏����i��ɂ��Ȃ������ۂ̏�����final()�ɂĒ�`�j
AnimationEngine2D::~AnimationEngine2D() {
	final();
}

//�R���X�g���N�^�ɂ����鏈���@��ɃV�[���N���X�𐶐�����
void AnimationEngine2D::init(){
	alive = true;
	sc = new scene();
}

//�f�X�g���N�^�ɂ�������ۂ̏����@�V�[���N���X�I�u�W�F�N�g�����ł�����i�K�{�̓���j
void AnimationEngine2D::final(){
	delete sc;
}

//update�֐��͎�Ɍv�Z������S���֐��ijava�ł������\�b�h�j
void AnimationEngine2D::update(){

	if (CheckHitKey(KEY_INPUT_ESCAPE))alive=false;

	sc->update();
}

//draw�֐��͕`��A����������S���֐�
void AnimationEngine2D::draw(){
	sc->draw();
}

//�㔻��update�֐��B�`�����ɂ���K�v������v�Z������S�����߂ɂ���B
void AnimationEngine2D::update_late() {
	sc->update_late();
}

