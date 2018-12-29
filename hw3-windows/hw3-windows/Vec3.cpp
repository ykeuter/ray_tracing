#include "Vec3.h"
#include <math.h>

Vec3 operator+(Vec3 a, const Vec3& b) {
  for (int i = 0; i < 3; i++) {
    a.xyz[i] += b.xyz[i];
  }
  return a;
}

Vec3 operator-(Vec3 a, Vec3& b) {
  for (int i = 0; i < 3; i++) {
    a.xyz[i] -= b.xyz[i];
  }
  return a;
}

Vec3 operator*(float a, Vec3 b) {
  for (int i = 0; i < 3; i++) {
    b.xyz[i] *= a;
  }
  return b;
}



void Vec3::normalize()
{
  float s = 0;
  for (int i = 0; i < 3; i++) {
    s += this->xyz[i] * this->xyz[i];
  }
  s = sqrt(s);
  for (int i = 0; i < 3; i++) {
    this->xyz[i] /= s;
  }
}

Vec3 Vec3::cross(Vec3& a, Vec3& b)
{
  int i2;
  Vec3 c;
  for (int i = 0; i < 3; i++) {
    i2 = (i + 1) % 3;
    c.xyz[i] = a.xyz[i] * b.xyz[i2] - a.xyz[i2] * b.xyz[i];
  }
  return c;
}
