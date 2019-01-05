#include "Sphere.h"
#include "Vec3.h"
#include "Ray.h"
#include <math.h>
#include "Transform.h"



Sphere::Sphere(float x, float y, float z, float r, const Transform& t) : radius(r)
{
  Transform t2;
  t2.Translate(x, y, z);
  minv =  t2.minverse * t.minverse;
  minvtminv = minv;
  minvtminv.Transpose();
  minvtminv = minvtminv * minv;
}

float Sphere::Intersect(const Ray& r)
{
  Vec3 p0 = minv.Multiply(r.orig);
  Vec3 p1 = minv.Multiply(r.dir, .0f);
  float a = Vec3::dot(p1, p1);
  float b = 2 * Vec3::dot(p1, p0);
  float c = Vec3::dot(p0, p0) - radius * radius;
  float D = b * b - 4 * a * c;
  if (D < 0) return -1.f;
  float sqr = sqrt(D);
  float d1 = (-b - sqr) / 2 / a;
  float d2 = (-b + sqr) / 2 / a;
  if (d1 < 0) {
    if (d2 < 0) {
      return -1.f;
    }
    else {
      return d2;
    }
  }
  else if (d2 < 0 || d1 < d2) {
    return d1;
  }
  else {
    return d2;
  }
}

Vec3 Sphere::GetNormal(const Vec3 & p)
{
  Vec3 n = minvtminv.Multiply(p);
  n.Normalize();
  return n;
}
