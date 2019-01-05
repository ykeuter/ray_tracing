#pragma once

#include "Geometry.h"
#include "Camera.h"
#include "Light.h"
#include <vector>
#include "Vec3.h"
#include <string>

class Scene
{
  std::vector<Geometry*> geos;
  std::vector<Light*> lights;
  Camera cam;
  int depth = 5;
  Vec3 attenuation = Vec3(1.f, .0f, .0f);
  std::string filename = "test.png";
  bool IsBlocked(const Ray & r, float dmax = -1.);
  Vec3 Trace(const Ray&, int depth = 0);
public:
  void Add(Geometry*);
  void Add(Light*);
  void SetDepth(int);
  void SetCamera(const Camera&);
  void SetAttenuation(float x, float y, float z);
  void SetFilename(const std::string&);
  ~Scene()
  {
    for (auto &v : lights) delete v;
    for (auto &v : geos) delete v;
  }
  void Render();
};

