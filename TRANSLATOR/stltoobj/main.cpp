#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/STLReader.h"
#include "./headers/StlToObj.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/stltoobj/resources/cube.stl";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/stltoobj/output/stltoobj.obj";
        Geometry::Triangulation triangulation;
        Geometry::STLReader stlReader;
        stlReader.readSTL(filepath, triangulation);

        Geometry::StlToObj stlToObj;
        stlToObj.stlToObjConversion(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}