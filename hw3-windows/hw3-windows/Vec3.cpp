#include "Vec3.h"
#include <math.h>

Vec3 operator+(Vec3 a, const Vec3& b) {
  for (int i = 0; i < 3; i++) {
    a.xyz[i] += b.xyz[i];
  }
  return a;
}

Vec3 operator-(Vec3 a, const Vec3& b) {
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

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
  os << "[" << v.xyz[0] << "," << v.xyz[1] << "," << v.xyz[2] << "]";
  return os;
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
  int i1, i2;
  Vec3 c;
  for (int i = 0; i < 3; i++) {
    i1 = (i + 1) % 3;
    i2 = (i + 2) % 3;
    c.xyz[i] = a.xyz[i1] * b.xyz[i2] - a.xyz[i2] * b.xyz[i1];
  }
  return c;
}

float Vec3::dot(const Vec3& a, const Vec3& b)
{
  float c(0.0f);
  for (int i = 0; i < 3; i++) {
    c += a.xyz[i] * b.xyz[i];
  }
  return c;
}
