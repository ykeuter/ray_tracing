#pragma once
#include <iostream>
#include <stddef.h>

class Vec3
{
  float xyz[3];
public:
  Vec3() {}
  Vec3(float x, float y, float z) : xyz{x, y, z} {}
  float Normalize();
  float Length();
  static Vec3 cross(const Vec3&, const Vec3&);
  static float dot(const Vec3&, const Vec3&);
  float& operator[] (std::size_t i) { return xyz[i]; }
  const float operator[] (std::size_t i) const { return xyz[i]; }
  Vec3& operator+=(const Vec3&);
  Vec3& operator-=(const Vec3&);
  Vec3& operator*=(float);
  Vec3& operator*=(const Vec3&);
  friend Vec3 operator*(Vec3 a, float b) { a *= b; return a; }
  friend Vec3 operator*(Vec3 a, const Vec3& b) { a *= b; return a; }
  friend std::ostream& operator<<(std::ostream&, const Vec3&);
  friend Vec3 operator+(Vec3 a, const Vec3& b) { a += b; return a; }
  friend Vec3 operator-(Vec3 a, const Vec3& b) { a -= b; return a; }
};




