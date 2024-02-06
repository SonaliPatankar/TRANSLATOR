// Triangle.cpp
#include "../headers/Triangle.h"
using namespace geometry;

Triangle::Triangle(int v1, int v2, int v3) : mV1(v1), mV2(v2), mV3(v3) {}

Triangle::~Triangle()
{
}
const int Triangle::v1() const
{
    return mV1;
}

const int Triangle::v2() const
{
    return mV2;
}

const int Triangle::v3() const
{
    return mV3;
}
