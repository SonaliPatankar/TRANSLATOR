#pragma once

#include <string>
#include "Triangulation.h"

namespace Geometry
{
    class OBJReader
    {
    public:
        // Reads an OBJ file
        void readOBJ(std::string &filePath, Triangulation &triangulation);
    };
}
