#pragma once

#include "Ray.h"

class Geometry
{
  float diffuse[3];
  float specular[3];
  float emission[3];
  float shininess;
public:
  float ambient[3];
  Geometry() {};
  virtual ~Geometry() {};
  virtual float Intersect(const Ray&) =0;
  void SetProperties(float[], float[], float[], float[], float);
};

