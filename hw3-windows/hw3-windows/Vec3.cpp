#include "Vec3.h"
#include <math.h>
#include <iostream>


std::ostream& operator<<(std::ostream& os, const Vec3& v) {
  os << "[" << v[0] << "," << v[1] << "," << v[2] << "]";
  return os;
}

float Vec3::Length() {
  float s = Vec3::dot(*this, *this);
  return sqrt(s);
}



float Vec3::Normalize()
{  
  float s = this->Length();
  for (int i = 0; i < 3; i++) {
    this->xyz[i] /= s;
  }
  return s;
}

Vec3 Vec3::cross(const Vec3& a, const Vec3& b)
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

Vec3 & Vec3::operator-=(const Vec3 & b)
{
  for (int i = 0; i < 3; i++) {
    xyz[i] -= b[i];
  }
  return *this;
}

Vec3 & Vec3::operator+=(const Vec3 & b)
{
  for (int i = 0; i < 3; i++) {
    xyz[i] += b[i];
  }
  return *this;
}

Vec3 & Vec3::operator*=(float b)
{
  for (int i = 0; i < 3; i++) {
    xyz[i] *= b;
  }
  return *this;
}

Vec3 & Vec3::operator*=(const Vec3& b)
{
  for (int i = 0; i < 3; i++) {
    xyz[i] *= b[i];
  }
  return *this;
}

