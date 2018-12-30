#include "Ray.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Ray& r) {
  os << "Origin: " << r.orig << std::endl << "Direction: " << r.dir << std::endl;
  return os;
}