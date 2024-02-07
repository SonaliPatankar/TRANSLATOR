#include <iostream>
#include <vector>
#include "./headers/Point3D.h"
#include "./headers/OBJReader.h"
#include "./headers/Triangulation.h"
#include "./headers/ObjToStl.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/objtostl/inputfiles/cube1.obj";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/objtostl/outputfiles/objtostl.stl";
        geometry::Triangulation triangulation;
        geometry::OBJReader objReader;
        objReader.readOBJ(filepath, triangulation);

        geometry::ObjToStl objToStl;
        objToStl.objToStlConversion(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}