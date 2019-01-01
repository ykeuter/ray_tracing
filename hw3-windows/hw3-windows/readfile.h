#pragma once

#include <sstream>
#include "Scene.h"

bool readvals(std::stringstream &s, const int numvals, float * values);
Scene readfile(const char * filename);
