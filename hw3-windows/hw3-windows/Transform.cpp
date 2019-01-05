#include "Transform.h"
#include "Vec3.h"
#include <math.h>
#include "Mat4.h"

const float pi = 3.14159265f;


Transform::Transform() :
  matrix(1, 0, 0, 0,
         0, 1, 0, 0,
         0, 0, 1, 0,
         0, 0, 0, 1),
  minverse(matrix)
{ }

void Transform::Rotate(float x, float y, float z, float a)
{
  float theta = a / 180.0f * pi;
  float c = cos(theta);
  float cr = 1 - c;
  float s = sin(theta);

  Mat4 m(c + cr * x * x, cr * x * y - s * z, cr * x * z + s * y, .0,
         cr * x * y + s * z, c + cr * y * y, cr * y * z - s * x, .0,
         cr * x * z - s * y, cr * y * z + s * x, c + cr * z * z, .0,
         .0, .0, .0, 1.);

  matrix = matrix * m;
  m.Transpose();
  minverse = m * minverse;
}

void Transform::Translate(float x, float y, float z)
{
  Mat4 m(1, 0, 0, x,
         0, 1, 0, y,
         0, 0, 1, z,
         0, 0, 0, 1);
  Mat4 m2(1, 0, 0, -x,
          0, 1, 0, -y,
          0, 0, 1, -z,
          0, 0, 0, 1);

  matrix = matrix * m;
  minverse = m2 * minverse;
}

void Transform::Scale(float x, float y, float z)
{
  Mat4 m(x, 0, 0, 0,
         0, y, 0, 0,
         0, 0, z, 0,
         0, 0, 0, 1);
  Mat4 m2(1 / x, 0, 0, 0,
          0, 1 / y, 0, 0,
          0, 0, 1 / z, 0,
          0, 0, 0, 1);

  matrix = matrix * m;
  minverse = m2 * minverse;
}
