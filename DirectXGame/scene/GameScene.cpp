#include "GameScene.h"
#include "TextureManager.h"
#include <cassert>
#include"myMath.h"



GameScene::GameScene() {}

GameScene::~GameScene() { 
	delete sprite_;
	delete player_;
	delete model_;
	//delete modelBlock_;

	for (std::vector<WorldTransform*>& worldTransformBlockLine : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlock : worldTransformBlockLine) {
			delete worldTransformBlock;
		}
	}
	worldTransformBlocks_.clear();

	delete player_;

	delete modelSkydome_;

	delete skydome_;

	delete debugCamera_;



	//delete debugCamera_;
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
	const uint32_t kNumBlockVirtical = 10;
	const uint32_t kNumBlockHorizontal=20;

	//ブロック1個分の横幅
	const float kBlockWidth=2.0f;
	const float kBlockHeight = 2.0f;

	//要素数を変更する
	worldTransformBlocks_.resize(kNumBlockVirtical);

	//キューブの生成
	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {

		worldTransformBlocks_[i].resize(kNumBlockHorizontal);
		//worldTransformBlocks_[i]->Initialize();
		//worldTransformBlocks_[i]->translation_.x=kBlockWidth*i;
		//worldTransformBlocks_[i]->translation_.y=0.0f;

	}

	for (uint32_t i = 0; i < kNumBlockVirtical; ++i) {
		for (uint32_t j = 0; j < kNumBlockHorizontal; ++j) {
			if (j % 2 == (i % 2)) {
				worldTransformBlocks_[i][j] = new WorldTransform();
				worldTransformBlocks_[i][j]->Initialize();
				worldTransformBlocks_[i][j]->translation_.x = kBlockWidth * j;
				worldTransformBlocks_[i][j]->translation_.y = kBlockHeight * i;
			} else {
				worldTransformBlocks_[i][j] = nullptr;
			}
		}
	}


	// デバッグカメラの生成
	debugCamera_ = new DebugCamera(1280, 720);


	


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
	//for (WorldTransform* worldTransformBlock : worldTransformBlocks_) {

	//	worldTransformBlock->matWorld_=Matrix4x4();

	//	//定数バッファに転送する
	//	worldTransformBlock->TransferMatrix();
	//}

	//for (std::vector<WorldTransform*> worldTransformBlockTate : worldTransformBlocks_) {
	//	for (WorldTransform* worldTransformBlockYoko : worldTransformBlockTate) {
	//		if (!worldTransformBlockYoko)
	//			continue;

	//		// アフィン変換行列の作成
	//		worldTransformBlockYoko->UpdateMatrix();
	//	}
	//}

	//縦横ブロック更新
	for (std::vector<WorldTransform*> worldTransformBlockTate : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlockYoko : worldTransformBlockTate) {
			if (!worldTransformBlockYoko)

				continue;

			
		}
	}



	#ifdef _DEBUG
	if (input_->TriggerKey(DIK_SPACE)) {
		if (isDebugCameraActive_ == true)
			isDebugCameraActive_ = false;
		else
			isDebugCameraActive_ = true;
	}
#endif









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


	for (std::vector<WorldTransform*> worldTransformBlockTate : worldTransformBlocks_) {
		for (WorldTransform* worldTransformBlockYoko : worldTransformBlockTate) {
			if (!worldTransformBlockYoko)

				continue;

			modelBlock_->Draw(*worldTransformBlockYoko, viewProjection_);
		}
	}

	modelSkydome_->Draw(worldTransform_, viewProjection_);

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
