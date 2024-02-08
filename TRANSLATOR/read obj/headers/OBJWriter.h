#pragma once
#include<string>
#include"Triangulation.h"

namespace Geometry
{
    class OBJWriter
    {
    public:
        // Function to write Triangulation data to an OBJ file
        void writeOBJ(std::string &filePath,Triangulation &triangulation);
    };
}