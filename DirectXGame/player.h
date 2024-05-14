///<summary>
///	自キャラ
///</summary>

#include"WorldTransform.h"
#include"Model.h"
#include"ViewProjection.h"


class Player{

public:



void Initialize(Model*model,uint32_t textureHandle,ViewProjection*viewProjection);
		
///<summary>


void Update();



void Draw();


private:

WorldTransform worldTransform_;

Model*model_=nullptr;

uint32_t textureHandle_=0u;

ViewProjection*viewProjection_=nullptr;

};


 



