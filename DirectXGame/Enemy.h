#pragma once

#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"

class Player;

class Enemy {
public:

	void Initialize(Model* model, const Vector3& position, ViewProjection* viewProjection);
	void Initialize(const Vector3& position, ViewProjection* viewProjection);

	void Update();
	
	void Draw();
  
  private:

	  static inline const float kAcceleration = 0.01f;
	 
	WorldTransform worldTransform_;
	ViewProjection* viewProjection_ = nullptr;
	
	Model* model_ = nullptr;

	uint32_t textureHandle_ = 0u;

	static inline const float kWalkspeed = 0.02f;

	Vector3 velocity_ = {};

	static inline const float kWalkMotionAngleStart = 0.5;

	static inline const float kWalkMotionAngleEng = 1;

	static inline const float kWalkMotionTime = 2;

	float walkTimer_ = 0.0f;

};