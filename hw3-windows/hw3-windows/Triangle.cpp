#include "Triangle.h"
#include "Vec3.h"
#include "Transform.h"



Triangle::Triangle(const Vec3& a, const Vec3& b, const Vec3& c, const Transform& t) :
abc{t.matrix.Multiply(a), t.matrix.Multiply(b), t.matrix.Multiply(c)}
{
  a_ = abc[0] - abc[2];
  b_ = abc[1] - abc[2];
  aa = Vec3::dot(a_, a_);
  ab = Vec3::dot(a_, b_);
  bb = Vec3::dot(b_, b_);
  n = Vec3::cross(a_, b_);
  n.Normalize();
  denom = aa * bb - ab * ab;
}

 
Vec3 Triangle::GetNormal(const Vec3& p) {
  return n;
}

float Triangle::Intersect(const Ray& r) {
  const Vec3& p0 = r.orig;
  const Vec3& p1 = r.dir;
  float div = Vec3::dot(p1, n);
  if (div == .0) return -1.0f;
  float t = Vec3::dot(abc[0] - p0, n) / div;
  if (t < 0) return -1.f;
  Vec3 q_ = p0 + p1 * t - abc[2];
  float aq = Vec3::dot(a_, q_);
  float bq = Vec3::dot(b_, q_);
  float alpha = bb * aq - ab * bq;
  if (alpha < 0) return -1.f;
  float beta = aa * bq - ab * aq;
  if (beta < 0 || denom - alpha - beta < 0) return -1.f;
  return t;
}
