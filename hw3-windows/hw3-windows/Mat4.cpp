#include "Mat4.h"
#include <algorithm>


Vec3 Mat4::Multiply(const Vec3 & v, float w) const
{
  float t[3];
  for (int i = 0; i < 3; i++) {
    t[i] = m[i][3] * w;
    for (int j = 0; j < 3; j++) {
      t[i] += v[j] * m[i][j];
    }
  }
  return Vec3(t[0], t[1], t[2]);
}

void Mat4::Transpose()
{
  for (int i = 0; i < 3; i++) {
    for (int j = i + 1; j < 4; j++) {
      std::swap(m[i][j], m[j][i]);
    }
  }
}

Mat4 operator*(const Mat4 & a, const Mat4 & b)
{
  Mat4 c;
  float s;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      s = .0f;
      for (int k = 0; k < 4; k++) {
        s += a.m[i][k] * b.m[k][j];
      }
      c.m[i][j] = s;
    }
  }
  return c;
}