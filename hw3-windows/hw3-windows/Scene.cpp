#include "Scene.h"
#include "Geometry.h"
#include "Light.h"
#include "Ray.h"
#include "Vec3.h"
#include "Camera.h"
#include <FreeImage.h>
#include <iostream>
#include <string>

using namespace std;

const float bias = .01f;

void Scene::SetDepth(int d) {
  depth = d;
}

void Scene::SetFilename(const string& f) {
  filename = f;
}

void Scene::SetCamera(const Camera& c) {
  cam = c;
}

void Scene::SetAttenuation(float x, float y, float z) {
  attenuation = Vec3(x, y, z);
}

void Scene::Add(Geometry* g) {
  geos.push_back(g);
}

void Scene::Add(Light* li) {
  lights.push_back(li);
}

bool Scene::IsBlocked(const Ray& r, float dmax) {
  float d;
  for (auto &v : geos) {
    d = v->Intersect(r);
    if (d > .0 && (d < dmax || dmax < 0)) return true;
  }
  return false;
}

Vec3 Scene::Trace(const Ray& r, int depth) {
  Vec3 color(.0f, .0f, .0f);
  Geometry* g = nullptr;
  Vec3 p, n, dir;
  float dmin, d, a;
  if (depth > this->depth) return color;
  dmin = -1;
  for (auto &v : geos) {
    d = v->Intersect(r);
    if (d > 0 && (d < dmin || dmin < 0)) {
      dmin = d;
      g = v;
    }
  }
  if (dmin < 0) return color;
  p = r.orig + r.dir * dmin;
  color = g->GetColor();
  n = g->GetNormal(p);
  for (auto &v : lights) {
    if (v->directional) {
      dir = v->xyz;
      d = -1;
    }
    else {
      dir = v->xyz - p;
      d = dir.Normalize();
    }
    if (!IsBlocked(Ray(p + dir * bias, dir), d - bias)) {
      a = 1.;
      if (!v->directional) a = 1.f / (attenuation[0] + d * attenuation[1] + d * d * attenuation[2]);
      color += v->rgb * a * g->GetLighting(n, dir, r.dir);
    }
  }
  dir = r.dir - n * (2 * Vec3::dot(r.dir, n));
  color += (Trace(Ray(p + dir * bias, dir), depth + 1) * g->specular);
  return color;
}

void Scene::Render()
{
  Vec3 c;
  FreeImage_Initialise();
  int total = cam.width * cam.height * 3;
  BYTE *pixels = new BYTE[total];
  int counter = 0;
  int lastPrint = 0;
  cout << "%.0";
  for (int y = 0; y < cam.height; y++) {
    for (int x = 0; x < cam.width; x++) {
      if (counter * 100 / total > lastPrint) {
        lastPrint = counter * 100 / total;
        cout << "." << lastPrint;
      }
      c = Trace(cam.RayThruPixel(x + .5f, y + .5f));
      pixels[counter++] = int(c[2] * 255);
      pixels[counter++] = int(c[1] * 255);
      pixels[counter++] = int(c[0] * 255);
    }
  }
  cout << ".100" << endl;

  FIBITMAP *img = FreeImage_ConvertFromRawBits(pixels, cam.width, cam.height, cam.width * 3, 24, 0xFF0000, 0x00FF00, 0x0000FF, false);

  FreeImage_Save(FIF_PNG, img, filename.c_str(), 0);
  delete [] pixels;

  FreeImage_DeInitialise();
}
