#pragma once

#include "Vec3.h"
#include "Ray.h"

class Triangle
{
Vec3 abc[3];
public:
  Triangle(Vec3&, Vec3&, Vec3&);
  ~Triangle();
  float intersect(Ray);
};

