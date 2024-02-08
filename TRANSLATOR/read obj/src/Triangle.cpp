#include "../headers/Triangle.h"

Geometry::Triangle::Triangle(int v1, int v2, int v3) : mV1(v1), mV2(v2), mV3(v3){}

Geometry::Triangle::~Triangle()
{
}
const int Geometry::Triangle::v1() const
{
    return mV1;
}

const int Geometry::Triangle::v2() const
{
    return mV2;
}

const int Geometry::Triangle::v3() const
{
    return mV3;
}
