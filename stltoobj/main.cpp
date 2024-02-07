#include <iostream>
#include <vector>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/STLReader.h"
#include "./headers/StlToObj.h"

int main()
{
    try
    {

        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/stltoobj/inputfiles/cube.stl";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/stltoobj/outputfiles/stltoobj.obj";
        geometry::Triangulation triangulation;
        geometry::STLReader stlReader;
        stlReader.readSTL(filepath, triangulation);

        geometry::StlToObj stlToObj;
        stlToObj.stlToObjConversion(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}