#include"GameScene.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

  
Matrix4x4 MakeRotateXMatrix(float radian);
    

Matrix4x4 MakeRotateYMatrix(float radian);
    

Matrix4x4 MakeRotateZMatrix(float radian);


Matrix4x4 MatrixMultiply(const Matrix4x4& m1, const Matrix4x4& m2);
   // Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2) ;
   