#include"WorldTransform.h"
#include"myMath.h"

void WorldTransform::UpdateMatrix(){

//�X�P�[���A��]�A���s�ړ����������čs����v�Z����
matWorld_=MakeAffineMatrix(scale_,rotation_,translation_);
//�萔�o�b�t�@�ɓ]������
TransferMatrix();


}