#pragma once

#include "Ray.h"
#include "Vec3.h"

class Geometry
{
  Vec3 diffuse;
  Vec3 emission;
  Vec3 ambient;
  float shininess;
public:
  Vec3 specular;
  virtual float Intersect(const Ray&) = 0;
  virtual Vec3 GetNormal(const Vec3&) = 0;
  void SetProperties(const Vec3&, const Vec3&, const Vec3&, const Vec3&, float);
  Vec3 GetColor() { return ambient + emission; }
  Vec3 GetLighting(const Vec3& normal, const Vec3& ligth, const Vec3& cam);
};

