#include "Geometry.h"

void Geometry::SetProperties(float[], float[], float[], float[], float)
{
  for (int i = 0; i < 3; i++) {
    (this->ambient)[i] = ambient[i];
    (this->diffuse)[i] = diffuse[i];
    (this->specular)[i] = specular[i];
    (this->emission)[i] = emission[i];
  }
  this->shininess = shininess;
}
