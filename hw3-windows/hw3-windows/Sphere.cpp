#include "Sphere.h"
#include "Vec3.h"
#include "Ray.h"
#include <math.h>
#include "Transform.h"



Sphere::Sphere(const Vec3&c, const float r, const Transform& t)
{
  center = c;
  radius = r;
  transf = t;
}


Sphere::~Sphere()
{
}

float Sphere::Intersect(const Ray& r)
{
  Vec3 p0 = transf.Eval(r.orig, true);
  Vec3 p1 = transf.Eval(r.dir, true, .0f);
  Vec3 p0c = p0 - center;
  float a = Vec3::dot(p1, p1);
  float b = 2 * Vec3::dot(p1, p0c);
  float c = Vec3::dot(p0c, p0c) - radius * radius;
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
