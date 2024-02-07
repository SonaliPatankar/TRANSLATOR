#include <iostream>
#include <vector>
#include "./headers/Point3D.h"
#include "./headers/OBJReader.h"
#include "./headers/OBJWriter.h"
#include "./headers/Triangulation.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/read obj/inputfiles/cube1.obj";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/read obj/outputfiles/writeObj.txt";
        geometry::Triangulation triangulation;
        geometry::OBJReader objReader;
        objReader.readOBJ(filepath, triangulation);

        geometry::OBJWriter objWriter;
        objWriter.writeOBJ(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}