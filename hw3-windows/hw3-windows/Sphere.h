#pragma once
#include "Geometry.h"
#include "Vec3.h"
#include "Ray.h"
#include "Transform.h"

class Sphere :
  public Geometry
{
  float radius;
  Mat4 minv;
  Mat4 minvtminv;
public:
  Sphere(float x, float y, float z, float r, const Transform& t);
  float Intersect(const Ray & r);
  Vec3 GetNormal(const Vec3&);
};

