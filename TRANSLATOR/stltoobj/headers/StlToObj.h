#pragma once
#include<string>
#include "Triangle.h"
#include"Triangulation.h"

namespace Geometry
{
    class StlToObj
    {
    public:
        // Function to convert STL file to OBJ format
        void stlToObjConversion(std::string &filePath, Triangulation &triangulation);
    };
}