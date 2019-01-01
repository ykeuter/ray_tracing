#pragma once

#include "Geometry.h"
#include "Camera.h"
#include <vector>

class Scene
{
  std::vector<Geometry*> geos;
  Camera* cam;
public:
  void Add(Geometry*);
  void Add(Camera*);
  Scene();
  virtual ~Scene();
  void Render();
};

