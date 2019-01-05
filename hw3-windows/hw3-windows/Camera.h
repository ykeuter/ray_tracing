#pragma once

#include "Vec3.h"
#include "Ray.h"


class Camera
{
  Vec3 lookfrom;
  Vec3 lookat;
  Vec3 up;
  float fovy;
  Vec3 u;
  Vec3 v;
  Vec3 w;
  float tan_;
public:
  int width;
  int height;
  Camera(float lookfromx, float lookfromy, float lookfromz, 
         float lookatx, float lookaty, float lookatz, 
         float upx, float upy, float upz, 
         float fovy, int width, int height);
  Camera() {}
  Ray RayThruPixel(float, float);
};

