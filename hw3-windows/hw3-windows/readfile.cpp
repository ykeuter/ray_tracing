#include "readfile.h"
#include "Scene.h"
#include "Camera.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Transform.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;


// Function to read the input data values
// Use is optional, but should be very helpful in parsing.  
bool readvals(stringstream &s, const int numvals, float* values)
{
  for (int i = 0; i < numvals; i++) {
    s >> values[i];
    if (s.fail()) {
      cout << "Failed reading value " << i << " will skip\n";
      return false;
    }
  }
  return true;
}

Scene* readfile(const char* filename)
{
  Scene* sc = new Scene();
  float ambient[3] = {.2f, .2f, .2f};
  float diffuse[3];
  float specular[3];
  float emission[3];
  float shininess = .0f;
  int width, height;
  vector<Vec3> vertices;
  stack<Transform> transf;
  string str, cmd;
  ifstream in;
  in.open(filename);
  if (in.is_open()) {
    transf.push(Transform());
    getline(in, str);
    while (in) {
      if ((str.find_first_not_of(" \t\r\n") != string::npos) && (str[0] != '#')) {
        // Ruled out comment and blank lines 

        stringstream s(str);
        s >> cmd;
        int i;
        float values[10]; // Position and color for light, colors for others
                            // Up to 10 params for cameras.  
        bool validinput; // Validity of input 

        // Material Commands 
        // Ambient, diffuse, specular, shininess properties for each object.
        // Filling this in is pretty straightforward, so I've left it in 
        // the skeleton, also as a hint of how to do the more complex ones.
        // Note that no transforms/stacks are applied to the colors. 

        if (cmd == "ambient") {
          validinput = readvals(s, 3, values); // colors 
          if (validinput) {
            for (i = 0; i < 3; i++) {
              ambient[i] = values[i];
            }
          }
        }
        else if (cmd == "diffuse") {
          validinput = readvals(s, 3, values);
          if (validinput) {
            for (i = 0; i < 3; i++) {
              diffuse[i] = values[i];
            }
          }
        }
        else if (cmd == "specular") {
          validinput = readvals(s, 3, values);
          if (validinput) {
            for (i = 0; i < 3; i++) {
              specular[i] = values[i];
            }
          }
        }
        else if (cmd == "emission") {
          validinput = readvals(s, 3, values);
          if (validinput) {
            for (i = 0; i < 3; i++) {
              emission[i] = values[i];
            }
          }
        }
        else if (cmd == "shininess") {
          validinput = readvals(s, 1, values);
          if (validinput) {
            shininess = values[0];
          }
        }
        else if (cmd == "size") {
          validinput = readvals(s, 2, values);
          if (validinput) {
            width = (int)values[0];
            height = (int)values[1];
          }
        }
        else if (cmd == "camera") {
          validinput = readvals(s, 10, values); // 10 values eye cen up fov
          if (validinput) {
            Camera* c = new Camera(values[0], values[1], values[2],
              values[3], values[4], values[5],
              values[6], values[7], values[8],
              values[9], width, height);
            sc->Add(c);
          }
        }

        else if (cmd == "vertex") {
          validinput = readvals(s, 3, values); // 10 values eye cen up fov
          if (validinput) {
            vertices.push_back(Vec3(values[0], values[1], values[2]));
          }
        }

        else if (cmd == "tri") {
          validinput = readvals(s, 3, values); // 10 values eye cen up fov
          if (validinput) {
            Triangle* t = new Triangle(transf.top().Eval(vertices[(int)values[0]]),
                                       transf.top().Eval(vertices[(int)values[1]]),
                                       transf.top().Eval(vertices[(int)values[2]]));
            t->SetProperties(ambient, diffuse, specular, emission, shininess);
            sc->Add(t);
          }
        }

        else if (cmd == "sphere") {
          validinput = readvals(s, 4, values); // 10 values eye cen up fov
          if (validinput) {
            Sphere* sp = new Sphere(Vec3(values[0], values[1], values[2]), values[3], transf.top());
            sp->SetProperties(ambient, diffuse, specular, emission, shininess);
            sc->Add(sp);
          }
        }

        else if (cmd == "translate") {
          validinput = readvals(s, 3, values); // 10 values eye cen up fov
          if (validinput) {
            transf.top().Translate(values[0], values[1], values[2]);
          }
        }

        else if (cmd == "rotate") {
          validinput = readvals(s, 4, values); // 10 values eye cen up fov
          if (validinput) {
            transf.top().Rotate(values[0], values[1], values[2], values[3]);
          }
        }

        else if (cmd == "scale") {
          validinput = readvals(s, 3, values); // 10 values eye cen up fov
          if (validinput) {
            transf.top().Scale(values[0], values[1], values[2]);
          }
        }

        else if (cmd == "pushTransform") {
          transf.push(transf.top());
        }

        else if (cmd == "popTransform") {
          if (transf.size() <= 1) {
            cerr << "Stack has no elements.  Cannot Pop\n";
          }
          else {
            transf.pop();
          }
        }

        else if (cmd == "maxverts") {
          // Not needed.
        }

        else {
          cout << "Unknown Command: " << cmd << " Skipping \n";
        }
      }
      getline(in, str);
    }
  }
  else {
    cerr << "Unable to Open Input Data File " << filename << "\n";
    throw 2;
  }
  return sc;
}
