#pragma once
/// <summary>
/// 4x4行列
/// </summary>
struct Matrix4x4 final {
	float m[4][4];
};
Matrix4x4& operator*=(Matrix4x4& lhm, const Matrix4x4& rhm);

Matrix4x4 operator*(const Matrix4x4& m1, const Matrix4x4& m2);
