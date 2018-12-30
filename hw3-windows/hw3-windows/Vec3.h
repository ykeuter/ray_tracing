#pragma once
#include <iostream>

class Vec3
{
public:
  float xyz[3];
  Vec3() {}
  Vec3(float x, float y, float z)
  {
    xyz[0] = x;
    xyz[1] = y;
    xyz[2] = z;
  }
  ~Vec3() {}
  void normalize();
  static Vec3 cross(Vec3&, Vec3&);
  static float dot(const Vec3&, const Vec3&);
};

Vec3 operator+(Vec3 a, const Vec3& b);
Vec3 operator*(float a, Vec3 b);
Vec3 operator-(Vec3 a, const Vec3& b);
std::ostream& operator<<(std::ostream&, const Vec3&);

