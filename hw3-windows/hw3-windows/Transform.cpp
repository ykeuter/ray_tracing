#include "Transform.h"
#include "Vec3.h"
#include <math.h>

const float pi = 3.14159265f;

void Transform::multiply(float m[][4], bool inverse) {
  float c[4][4];
  float (*a)[4] = matrix;
  if (inverse) a = m;
  float (*b)[4] = m;
  if (inverse) b = minverse;
  float s;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      s = .0f;
      for (int k = 0; k < 4; k++) {
        s += a[i][k] * b[k][j];
      }
      c[i][j] = s;
    }
  }
  float (*t)[4] = matrix;
  if (inverse) t = minverse;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      t[i][j] = c[i][j];
    }
  }
}


Transform::Transform()
{
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      matrix[i][j] = .0f;
      minverse[i][j] = .0f;
    }
    matrix[i][i] = 1.f;
    minverse[i][i] = 1.f;
  }
}

Vec3 Transform::Eval(const Vec3& v, bool inverse, float w) {
  float (*m)[4] = matrix;
  if (inverse) m = minverse;
  float t[3];
  for (int i = 0; i < 3; i++) {
    t[i] = m[i][3] * w;
    for (int j = 0; j < 3; j++) {
      t[i] += v.xyz[j] * m[i][j];
    }
  }
  return Vec3(t[0], t[1], t[2]);
}


Transform::~Transform()
{
}

void Transform::Rotate(float x, float y, float z, float a)
{
  float theta = a / 180.0f * pi;
  float c = cos(theta);
  float cr = 1 - c;
  float s = sin(theta);

  float m[4][4] = {{c + cr * x * x, cr * x * y - s * z, cr * x * z + s * y, .0},
                   {cr * x * y + s * z, c + cr * y * y, cr * y * z - s * x, .0},
                   {cr * x * z - s * y, cr * y * z + s * x, c + cr * z * z, .0},
                   {.0, .0, .0, 1.}};

  float minv[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      minv[i][j] = m[j][i];
    }
  }
  multiply(m);
  multiply(minv, true);
}

void Transform::Translate(float x, float y, float z)
{
  float t[] = {x, y, z, 1.f};
  float m[4][4];
  float minv[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = .0f;
      minv[i][j] = .0f;
    }
    m[i][i] = 1.f;
    minv[i][i] = 1.f;
    m[i][3] = t[i];
    minv[i][3] = -t[i];
  }
  minv[3][3] = 1.f;
  multiply(m);
  multiply(minv, true);
}

void Transform::Scale(float x, float y, float z)
{
  float t[] = { x, y, z, 1.f };
  float m[4][4];
  float minv[4][4];
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      m[i][j] = .0f;
      minv[i][j] = .0f;
    }
    m[i][i] = t[i];
    minv[i][i] = 1 / t[i];
  }
  multiply(m);
  multiply(minv, true);
}
