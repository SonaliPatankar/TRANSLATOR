#include <iostream>
#include "./headers/OBJReader.h"
#include "./headers/Triangulation.h"
#include "./headers/ObjToStl.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/objtostl/resources/cube1.obj";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/objtostl/output/objtostl.stl";
        Geometry::Triangulation triangulation;
        Geometry::OBJReader objReader;
        objReader.readOBJ(filepath, triangulation);

        Geometry::ObjToStl objToStl;
        objToStl.objToStlConversion(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}