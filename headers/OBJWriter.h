#pragma once
#include <vector>
#include<string>
#include "Triangle.h"
#include"Triangulation.h"

namespace geometry
{
    class OBJWriter
    {
    public:
        void writeOBJ(std::string &filePath,Triangulation &triangulation);
    };
}