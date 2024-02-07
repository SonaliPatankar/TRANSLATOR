#pragma once

#include <vector>
#include <string>
#include "Triangulation.h"

namespace geometry
{
    // Class responsible for reading OBJ files
    class OBJReader
    {
    public:
        // Reads an OBJ file
        void readOBJ(std::string &filePath, Triangulation &triangulation);
    };
}
