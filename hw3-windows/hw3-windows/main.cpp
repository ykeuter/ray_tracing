// hw3-windows.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Scene.h"
#include "readfile.h"

using namespace std;

int main()
{
    Scene* s = readfile("scene3.test");
    s->Render();
    delete s;
    //Camera c(0, 0, -1, 0, 0, 0, 0, 1, 0, 45, 10, 10);
    //Ray r = c.RayThruPixel(0, 0);
    //cout << r;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
