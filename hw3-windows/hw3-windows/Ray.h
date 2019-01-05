#pragma once

#include "Vec3.h"
#include <iostream>

class Ray
{
public:
  Vec3 orig;
  Vec3 dir;
  Ray() {}
  Ray(const Vec3& o, const Vec3& d) : orig(o), dir(d) {}
  friend std::ostream& operator<<(std::ostream& os, const Ray& r) {
    os << "Origin: " << r.orig << std::endl << "Direction: " << r.dir << std::endl;
    return os;
  }
};
