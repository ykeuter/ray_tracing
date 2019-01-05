#pragma once
#include "Vec3.h"

class Mat4
{
  float m[4][4];
public:
  Mat4() {}
  Mat4(float a, float b, float c, float d,
       float e, float f, float g, float h,
       float i, float j, float k, float l,
       float m, float n, float o, float p)
       : m{{a, b, c, d},
           {e, f, g, h},
           {i, j, k, l},
           {m, n, o, p}}
       {}
  Vec3 Multiply (const Vec3&, float w = 1.f) const;
  friend Mat4 operator*(const Mat4& a, const Mat4& b);
  void Transpose();
};

