#include "Scene.h"
#include "Triangle.h"
#include "Ray.h"
#include "Camera.h"
#include <FreeImage.h>


Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::render()
{
  Camera c = Camera(0, 0, -5, 0, 0, 0, 0, 1, 0, 45, 200, 100);
  Triangle t = Triangle(Vec3(-1, 0, 0), Vec3(1, 0, 0), Vec3(0, 1, 0));
  Ray r;

  FreeImage_Initialise();
  BYTE *pixels = new BYTE[3 * c.width * c.height];
  int counter = 0;
  int color = 0;
  for (int y = 0; y < c.height; y++) {
    for (int x = 0; x < c.width; x++) {
      r = c.RayThruPixel(x + .5f, y + .5f);
      if (t.Intersect(r) > 0) {
        color = 255;
      }
      else {
        color = 0;
      }
      pixels[counter++] = 0;
      pixels[counter++] = 0;
      pixels[counter++] = color;
    }
  }

  FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, c.width, c.height, c.width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);

  FreeImage_Save(FIF_PNG, img, "test.png", 0);
  delete pixels;

  FreeImage_DeInitialise();
}
