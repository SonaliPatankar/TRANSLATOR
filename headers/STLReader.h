#pragma once

#include<map>
#include <string>
#include <vector>
#include "Triangulation.h"

namespace geometry
{
    class STLReader {
public:
    void readSTL(std::string &filePath,Triangulation & triangulation);
};

}

