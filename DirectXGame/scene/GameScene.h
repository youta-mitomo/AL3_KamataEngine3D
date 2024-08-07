#pragma once

#include "Audio.h"
#include "DebugCamera.h"
#include "DirectXCommon.h"
#include "Input.h"
#include "Model.h"
#include "SafeDelete.h"
#include "Sprite.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "Skydome.h"
#include"Player.h"
#include<vector>

/// <summary>
/// ゲームシーン
/// </summary>
class GameScene {

	//ビュープロダクション
	

public: // メンバ関数
	/// <summary>
	/// コンストクラタ
	/// </summary>
	GameScene();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 毎フレーム処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

private: // メンバ変数
	DirectXCommon* dxCommon_ = nullptr;
	Input* input_ = nullptr;
	Audio* audio_ = nullptr;

	/// <summary>
	/// ゲームシーン用
	/// </summary>
	/// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	//3Dモデル
	Model* model_=nullptr;
	//Model*block_=nullptr;
	Model*modelBlock_=nullptr;
	Model*modelSkydome_=nullptr;

	WorldTransform worldTransform_;

	ViewProjection viewProjection_;


	//自キャラ
	Player*player_=nullptr;

	//スカイドーム
	Skydome* skydome_ = nullptr;

	//縦横ブロック配列
	std::vector<std::vector<WorldTransform*>> worldTransformBlocks_;



	//	スプライト
	Sprite* sprite_ = nullptr;

	bool isDebugCameraActive_ = false;

	DebugCamera* debugCamera_ = nullptr;
};
