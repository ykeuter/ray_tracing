#include "Triangle.h"
#include "Vec3.h"



Triangle::Triangle(const Vec3& a, const Vec3& b, const Vec3& c)
{
  abc[0] = a;
  abc[1] = b;
  abc[2] = c;
  a_ = a - c;
  b_ = b - c;
  aa = Vec3::dot(a_, a_);
  ab = Vec3::dot(a_, b_);
  bb = Vec3::dot(b_, b_);
  n = Vec3::cross(a_, b_);
  n.normalize();
  denom = aa * bb - ab * ab;
}

 
Triangle::~Triangle()
{
}

float Triangle::Intersect(Ray& r) {
  Vec3& p0 = r.orig;
  Vec3& p1 = r.dir;
  float div = Vec3::dot(p1, n);
  if (div == .0) return -1.0f;
  float t = Vec3::dot(abc[0] - p0, n);
  if (t < 0) return -1.f;
  Vec3 q_ = p0 + t * p1 - abc[2];
  float aq = Vec3::dot(a_, q_);
  float bq = Vec3::dot(b_, q_);
  float alpha = bb * aq - ab * bq;
  if (alpha < 0) return -1.f;
  float beta = aa * bq - ab * aq;
  if (beta < 0 || denom - alpha - beta < 0) return -1.f;
  return t;
}
