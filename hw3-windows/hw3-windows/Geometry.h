#pragma once

#include "Ray.h"

class Geometry
{
  float ambient[3];
  float diffuse[3];
  float specular[3];
  float emission[3];
  float shininess;
public:
  Geometry() {};
  virtual ~Geometry() {};
  virtual float Intersect(Ray&) =0;
  void SetProperties(float[], float[], float[], float[], float);
};

