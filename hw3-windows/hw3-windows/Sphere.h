#pragma once
#include "Geometry.h"
#include "Vec3.h"
#include "Ray.h"
#include "Transform.h"

class Sphere :
  public Geometry
{
  Vec3 center;
  float radius;
  Transform transf;
public:
  Sphere(const Vec3& c, const float r, const Transform& t);
  ~Sphere();
  float Intersect(const Ray & r);
};

