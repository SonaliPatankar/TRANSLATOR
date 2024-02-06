#pragma once
#include<vector>
#include<map>
#include"Triangle.h"
using namespace std;

namespace geometry
{
class Triangulation
{
    public:
        Triangulation();
        ~Triangulation();
        vector<Triangle>& triangles();
        vector<Point3D>& uniquePoints();
        
    private:
        vector<Triangle> mTriangles;
        vector<Point3D> mUniquePoints;

};
}