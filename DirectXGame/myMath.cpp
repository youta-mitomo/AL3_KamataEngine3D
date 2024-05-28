#include"GameScene.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate) {

    Matrix4x4 result = Multiply(
      Multiply(MakeRotateXMatrix(scale.x),MakeRotateYMatrix(translate.y)),
               MakeRotateZMatrix(rotate.z));

    result.m[0][0] *= /*拡大縮小のX成分*/;
    result.m[0][1] *= /*拡大縮小のX成分*/;
    result.m[0][2] *= /*拡大縮小のX成分*/;

    result.m[1][0] *= /*拡大縮小のY成分*/;
    result.m[1][1] *= /*拡大縮小のY成分*/;
    result.m[1][2] *= /*拡大縮小のY成分*/;

    result.m[2][0] *= /*拡大縮小のZ成分*/;
    result.m[2][1] *= /*拡大縮小のZ成分*/;
    result.m[2][2] *= /*拡大縮小のZ成分*/;

    result.m[3][0] = /*平行移動のX成分*/;
    result.m[3][1] = /*平行移動のY成分*/;
    result.m[3][2] = /*平行移動のZ成分*/;

    return result;
}

Matrix4x4 MakeRotateXMatrix(float radian) {
    float cosTheta = std::cos(radian);
    float sinTheta = std::sin(radian);
    return {1.0f, 0.0f,      0.0f,     0.0f, 0.0f, cosTheta, sinTheta, 0.0f,
            0.0f, -sinTheta, cosTheta, 0.0f, 0.0f, 0.0f,     0.0f,     1.0f};
}

Matrix4x4 MakeRotateYMatrix(float radian) {
    float cosTheta = std::cos(radian);
    float sinTheta = std::sin(radian);
    return {cosTheta, 0.0f, -sinTheta, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
            sinTheta, 0.0f, cosTheta,  0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
}

Matrix4x4 MakeRotateZMatrix(float radian) {

    //X軸とY軸の回転行列を作る関数を参考に考えてみよう
}

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2) {
   
    Matrix4x4 result;
  
    result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0] +
    m1.m[0][3] * m2.m[3][0];
    result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1] +
    m1.m[0][3] * m2.m[3][1];
    result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2] +
    m1.m[0][3] * m2.m[3][2];
    result.m[0][3] = m1.m[0][0] * m2.m[0][3] + m1.m[0][1] * m2.m[1][3] + m1.m[0][2] * m2.m[2][3] +
    m1.m[0][3] * m2.m[3][3];
    result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0] +
    m1.m[1][3] * m2.m[3][0];
    result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1] +
    m1.m[1][3] * m2.m[3][1];
    result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2] +
    m1.m[1][3] * m2.m[3][2];
    result.m[1][3] = m1.m[1][0] * m2.m[0][3] + m1.m[1][1] * m2.m[1][3] + m1.m[1][2] * m2.m[2][3] +
    m1.m[1][3] * m2.m[3][3];
    result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0] +
    m1.m[2][3] * m2.m[3][0];
    result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1] +
    m1.m[2][3] * m2.m[3][1];
    result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2] +
    m1.m[2][3] * m2.m[3][2];
    result.m[2][3] = m1.m[2][0] * m2.m[0][3] + m1.m[2][1] * m2.m[1][3] + m1.m[2][2] * m2.m[2][3] +
    m1.m[2][3] * m2.m[3][3];
    result.m[3][0] = m1.m[3][0] * m2.m[0][0] + m1.m[3][1] * m2.m[1][0] + m1.m[3][2] * m2.m[2][0] +
    m1.m[3][3] * m2.m[3][0];
    result.m[3][1] = m1.m[3][0] * m2.m[0][1] + m1.m[3][1] * m2.m[1][1] + m1.m[3][2] * m2.m[2][1] +
    m1.m[3][3] * m2.m[3][1];
    result.m[3][2] = m1.m[3][0] * m2.m[0][2] + m1.m[3][1] * m2.m[1][2] + m1.m[3][2] * m2.m[2][2] +
    m1.m[3][3] * m2.m[3][2];
    result.m[3][3] = m1.m[3][0] * m2.m[0][3] + m1.m[3][1] * m2.m[1][3] + m1.m[3][2] * m2.m[2][3] +
    m1.m[3][3] * m2.m[3][3];

    return result; 
}