#pragma once

#include "Vec3.h"
#include "Ray.h"

class Triangle
{
Vec3 abc[3];
Vec3 a_;
Vec3 b_;
Vec3 n;
float aa, ab, bb, denom;
public:
  Triangle(const Vec3&, const Vec3&, const Vec3&);
  ~Triangle();
  float Intersect(Ray&);
};

