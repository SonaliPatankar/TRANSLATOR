#include "..\headers\Triangulation.h"
#include <map>
#include <vector>
#include <iostream>
using namespace geometry;

Triangulation::Triangulation()
{
}
Triangulation::~Triangulation()
{
}

vector<Triangle> &Triangulation::triangles()
{
    return mTriangles;
}

vector<Point3D> &Triangulation::uniquePoints()
{
    return mUniquePoints;
}

vector<Point3D> &Triangulation :: uniqueNormals()
{
    return mUniqeNormals;
}