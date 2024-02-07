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
        // Function to write Triangulation data to an OBJ file
        void writeOBJ(std::string &filePath,Triangulation &triangulation);
    };
}