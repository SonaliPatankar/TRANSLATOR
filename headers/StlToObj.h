#pragma once
#include <vector>
#include<string>
#include "Triangle.h"
#include"Triangulation.h"

namespace geometry
{
    class StlToObj
    {
    public:
        void stlToObjConversion(std::string &filePath,Triangulation &triangulation);
    };
}