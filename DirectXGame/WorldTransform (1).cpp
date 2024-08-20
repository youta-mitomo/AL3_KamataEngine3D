#include "WorldTransform.h"
#include "myMath.h"

void WorldTransform::UpdateMatrix(){

	// スケール、回転、平行移動を合成して行列を計算
	matWorld_ = MakeAffineMatrix(scale_, rotation_, translation_);

	// 定数バッファに転送
	TransferMatrix();
}
