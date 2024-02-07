#include <iostream>
#include <vector>
#include "./headers/Point3D.h"
#include "./headers/Triangulation.h"
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"
int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/READ STL/inputfiles/cube.stl";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/READ STL/outputfiles/writeSTL.txt";
        geometry::Triangulation triangulation;
        geometry::STLReader stlReader;
        stlReader.readSTL(filepath, triangulation);

        geometry::STLWriter stlWriter;
        stlWriter.writeSTLToFile(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}