#pragma once
#include <vector>
#include<string>
#include "Triangle.h"
#include"Triangulation.h"

namespace geometry
{
    class ObjToStl
    {
    public:
        // Function to convert OBJ file to STL format
        void objToStlConversion(std::string &filePath,Triangulation &triangulation);
    };
}