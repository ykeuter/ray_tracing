#pragma once

#include "Vec3.h"

class Light
{
public:
  Vec3 xyz;
  Vec3 rgb;
  bool directional;
  Light(float x, float y, float z, float r, float g, float b, bool d)
    : xyz(x, y, z), rgb(r, g, b), directional(d)
  { if (directional) xyz.Normalize(); }
};

