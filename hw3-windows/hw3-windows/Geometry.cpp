#include "Geometry.h"
#include "Vec3.h"
#include <algorithm>
#include <math.h>

void Geometry::SetProperties(const Vec3& ambient, const Vec3& diffuse, const Vec3& specular, const Vec3& emission, float shininess)
{
  this->ambient = ambient;
  this->diffuse = diffuse;
  this->specular = specular;
  this->emission = emission;
  this->shininess = shininess;
}

Vec3 Geometry::GetLighting(const Vec3 & normal, const Vec3 & light, const Vec3& cam)
{
  Vec3 h = light - cam;
  h.Normalize();
  return diffuse * std::max(Vec3::dot(normal, light), 0.f) + 
         specular * std::pow(std::max(Vec3::dot(normal, h), .0f), shininess);
}
