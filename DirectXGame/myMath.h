#pragma once

#include "Vector3.h"
#include "Matrix4x4.h"

Matrix4x4 MakeAffineMatrix(const Vector3& scale, const Vector3& rotate, const Vector3& translate);

Matrix4x4 MakeRotateXMatrix(float radian);

Matrix4x4 MakeRotateYMatrix(float radian);

Matrix4x4 MakeRotateZMatrix(float radian);

Matrix4x4 Multiply(const Matrix4x4& m1, const Matrix4x4& m2);

Vector3& operator+=(Vector3& lhv, const Vector3& rhv);

float EaseInOut(float x1, float x2, float t);

float Lerp(float x1, float x2, float t);

Vector3 Lerp(const Vector3& v1, const Vector3& v2, float t);
   // Matrix4x4 MatrixMultiply(Matrix4x4& m1, Matrix4x4& m2) ;
   