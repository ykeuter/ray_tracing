#include "Triangle.h"



Triangle::Triangle(Vec3& a, Vec3& b, Vec3& c)
{
  abc[0] = a;
  abc[1] = b;
  abc[2] = c;
}

 
Triangle::~Triangle()
{
}
