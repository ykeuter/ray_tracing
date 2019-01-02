#include "Scene.h"
#include "Geometry.h"
#include "Ray.h"
#include "Camera.h"
#include <FreeImage.h>
#include <iostream>

using namespace std;

Scene::Scene()
{
}


Scene::~Scene()
{
  delete cam;
  for (auto &v : geos) delete v;
}

void Scene::Add(Camera* c) {
  cam = c;
}

void Scene::Add(Geometry* g) {
  geos.push_back(g);
}

void Scene::Render()
{
  Ray r;
  Geometry* g = nullptr;
  float dmin, d;
  FreeImage_Initialise();
  BYTE *pixels = new BYTE[3 * cam->width * cam->height];
  int counter = 0;
  for (int y = 0; y < cam->height; y++) {
    for (int x = 0; x < cam->width; x++) {
      r = cam->RayThruPixel(x + .5f, y + .5f);
      dmin = -1;
      for (auto &v : geos) {
        d = v->Intersect(r);
        if (d > 0 && (d < dmin || dmin < 0)) {
          dmin = d;
          g = v;
        }
      }
      
      if (dmin > 0) {
        pixels[counter++] = int(g->ambient[2] * 255);
        pixels[counter++] = int(g->ambient[1] * 255);
        pixels[counter++] = int(g->ambient[0] * 255);
      }
      else {
        pixels[counter++] = 0;
        pixels[counter++] = 0;
        pixels[counter++] = 0;
      }
    }
  }

  FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, cam->width, cam->height, cam->width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);

  FreeImage_Save(FIF_PNG, img, "test.png", 0);
  delete [] pixels;

  FreeImage_DeInitialise();
}
