#include "..\headers\Triangulation.h"

Geometry::Triangulation::Triangulation()
{
}
Geometry::Triangulation::~Triangulation()
{
}

vector<Geometry::Triangle> &Geometry::Triangulation::triangles()
{
    return mTriangles;
}

vector<Geometry::Point3D> &Geometry::Triangulation::uniquePoints()
{
    return mUniquePoints;
}

vector<Geometry::Point3D> &Geometry::Triangulation :: uniqueNormals()
{
    return mUniqeNormals;
}