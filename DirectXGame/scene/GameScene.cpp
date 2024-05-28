#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>



GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete sprite_;
	delete player_;
	delete model_;
	delete modelBlock_;

	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {
		delete worldTransformBlock;

	}
	worldTransformBlocks_.clear();

}



void GameScene::Initialize() {

	dxCommon_ = DirectXCommon::GetInstance();
	input_ = Input::GetInstance();
	audio_ = Audio::GetInstance();

	//ファイル名を指定してテクスチャを読み込む
	textureHandle_ = TextureManager::Load("mario.png");

	model_=Model::Create();
	modelBlock_=Model::Create();


	worldTransform_.Initialize();


	viewProjection_.Initialize();

	//スプライトの生成
	sprite_ = Sprite::Create(textureHandle_, {100, 50});

	//ViewProjection_.Initialize;
	player_=new Player();

	player_->Initialize(model_,textureHandle_,&viewProjection_);

	//要素数
	const uint32_t kNumBlockHorizontal=20;

	//ブロック1個分の横幅
	const float kBlockWidth=2.0f;

	//要素数を変更する
	worldTransformBlocks_.resize(kNumBlockHorizontal);

	//キューブの生成
	for (uint32_t i = 0; i < kNumBlockHorizontal; ++i) {

		worldTransformBlocks_[i]=new WorldTransform();
		worldTransformBlocks_[i]->Initialize();
		worldTransformBlocks_[i]->translation_.x=kBlockWidth*i;
		worldTransformBlocks_[i]->translation_.y=0.0f;

	}







	


}

void GameScene::Update() {


	player_->Update();


	//スプライトの今の座標を取得
	Vector2 position=sprite_->GetPosition();
	//座標を{2,1}移動
	position.x+=2.0f;
	position.y+=1.0f;
	//移動した座標をスプライトに反映
	sprite_->SetPosition(position);

	//ブロックの更新
	for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {

		worldTransformBlock->matWorld_=//Matrix4x4();

		//定数バッファに転送する
		worldTransformBlock->TransferMatrix();
	}




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
	sprite_->Draw();


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
	player_->Draw();

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
