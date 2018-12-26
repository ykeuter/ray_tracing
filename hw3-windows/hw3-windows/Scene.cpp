#include "Scene.h"
#include <FreeImage.h>


Scene::Scene()
{
}


Scene::~Scene()
{
}

void Scene::render()
{
  FreeImage_Initialise();
  int w(200);
  int h(100);
  int pix = w * h;
  BYTE *pixels = new BYTE[3 * pix];
  for (int i = 0; i < pix * 3; i++) {
    pixels[i] = 0;
  }

  FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, w, h, w * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);

  FreeImage_Save(FIF_PNG, img, "test.png", 0);
  delete pixels;

  FreeImage_DeInitialise();
}
