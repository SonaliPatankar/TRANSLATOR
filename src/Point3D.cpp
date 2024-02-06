#include "../headers/Point3D.h"

geometry :: Point3D::Point3D() : mX(0), mY(0), mZ(0) {}

geometry :: Point3D::Point3D(double x, double y, double z) : mX(x), mY(y), mZ(z) {}

geometry :: Point3D::~Point3D() {}

double geometry :: Point3D::x() const {
    return mX;
}

double geometry :: Point3D::y() const {
    return mY;
}

double geometry :: Point3D::z() const {
    return mZ;
}

bool geometry :: Point3D::operator<(const Point3D &other) const
{
    if (mX < other.mX)
        return true;
    if (mX > other.mX)
        return false;
 
    if (mY < other.mY)
        return true;
    if (mY > other.mY)
        return false;
 
    return mZ < other.mZ;
}
