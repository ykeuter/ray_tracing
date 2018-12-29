#pragma once
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
};

Vec3 operator+(Vec3 a, const Vec3& b);
Vec3 operator*(float a, Vec3 b);
Vec3 operator-(Vec3 a, Vec3& b);

