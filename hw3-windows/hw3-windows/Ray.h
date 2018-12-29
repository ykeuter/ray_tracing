#pragma once

#include "Vec3.h"

class Ray
{
public:
  Vec3 orig;
  Vec3 dir;
  Ray() {};
  Ray(Vec3& o, Vec3& d) {
    orig = o;
    dir = d;
  }
  ~Ray() {};
};

