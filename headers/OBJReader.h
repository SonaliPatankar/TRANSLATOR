#pragma once
#include <vector>
#include<string>
#include "Triangulation.h"

namespace geometry
{
    class OBJReader
    {
    public:
        void readOBJ(std::string &filePath,Triangulation &triangulation);
    };
}