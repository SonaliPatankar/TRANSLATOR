#include "../headers/Triangle.h"

Shape3D::Triangle::Triangle(int v1, int v2, int v3,int normalIndex) : mV1(v1), mV2(v2), mV3(v3) ,mNormalIndex(normalIndex){}

Shape3D::Triangle::~Triangle()
{
}
const int Shape3D::Triangle::v1() const
{
    return mV1;
}

const int Shape3D::Triangle::v2() const
{
    return mV2;
}

const int Shape3D::Triangle::v3() const
{
    return mV3;
}

const int Shape3D::Triangle::normalIndex() const
{
    return mNormalIndex;
}