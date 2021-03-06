#pragma once

#include "Vec3.h"
#include "Ray.h"
#include "Geometry.h"
#include "Transform.h"

class Triangle : public Geometry
{
Vec3 abc[3];
Vec3 a_;
Vec3 b_;
Vec3 n;
float aa, ab, bb, denom;
public:
  Triangle(const Vec3&, const Vec3&, const Vec3&, const Transform&);
  float Intersect(const Ray & r);
  Vec3 GetNormal(const Vec3& p);
};

