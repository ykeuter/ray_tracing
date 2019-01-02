#pragma once

#include "Vec3.h"

class Transform
{
  float matrix[4][4];
  float minverse[4][4];
  void multiply(float m[][4], bool inverse = false);
public:
  Transform();
  ~Transform();
  void Rotate(float x, float y, float z, float a);
  void Translate(float x, float y, float z);
  void Scale(float x, float y, float z);
  Vec3 Eval(const Vec3&, bool = false, float = 1.f);
};

