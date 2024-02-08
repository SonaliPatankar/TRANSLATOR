// STLWriter.h
#pragma once
#include <string>
#include "Triangulation.h"

namespace Shape3D
{
    class STLWriter
    {
    public:
        // Function to write geometry data to an STL file
        void writeSTLToFile(std::string &filePath, Triangulation &triangulationObj);
    };
}