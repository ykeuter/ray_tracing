#include "Camera.h"
#include <math.h>
#include <iostream>

const float pi = 3.14159265f;

Camera::Camera(float lookfromx, float lookfromy, float lookfromz,
               float lookatx, float lookaty, float lookatz,
               float upx, float upy, float upz,
               float fovy, int width, int height) 
                  : lookfrom( lookfromx, lookfromy, lookfromz )
                  , lookat( lookatx, lookaty, lookatz )
                  , up( upx, upy, upz )
                  , fovy(fovy)
                  , width(width)
                  , height(height)
{
  w = lookat - lookfrom;
  w.Normalize();
  u = Vec3::cross(w, up);
  u.Normalize();
  v = Vec3::cross(u, w);
  tan_ = tan(fovy / 360.0f * pi);
  //std::cout << tan_ << std::endl;
  //std::cout << u << std::endl;
  //std::cout << v << std::endl;
  //std::cout << w << std::endl;
}

Ray Camera::RayThruPixel(float x, float y)
{
  float alpha = tan_ / height * (2 * x - width);
  float beta = tan_ * (2 * y - height) / height;
  /*std::cout << alpha << std::endl;
  std::cout << beta << std::endl;*/
  Vec3 d = u * alpha + v  * beta+ w;
  //std::cout << (alpha * u) << std::endl;
  d.Normalize();
  return Ray(lookfrom, d);
}
