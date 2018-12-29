#include "Camera.h"
#include <math.h>



Camera::Camera(float lookfromx, float lookfromy, float lookfromz,
               float lookatx, float lookaty, float lookatz,
               float upx, float upy, float upz,
               float fovy, int width, int height) {
  lookfrom = Vec3(lookfromx, lookfromy, lookfromz);
  lookat = Vec3(lookatx, lookaty, lookatz);
  up = Vec3(upx, upy, upz);
  this->fovy = fovy;
  this->width = width;
  this->height = height;
  w = lookat - lookfrom;
  w.normalize();
  u = Vec3::cross(up, w);
  u.normalize();
  v = Vec3::cross(w, u);
  tan_ = tan(fovy / 2.0f);
}

Ray Camera::RayThruPixel(float x, float y)
{
  float alpha = tan_ / height * (2 * x - width);
  float beta = tan_ * (2 * y - height) / height;
  Vec3 d = (alpha * u) + (beta * v) + w;
  d.normalize();
  return Ray();
}
