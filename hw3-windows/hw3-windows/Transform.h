#pragma once

#include "Vec3.h"
#include "Mat4.h"

class Transform
{
public:
  Mat4 matrix;
  Mat4 minverse;
  Transform();
  void Rotate(float x, float y, float z, float a);
  void Translate(float x, float y, float z);
  void Scale(float x, float y, float z);
};

