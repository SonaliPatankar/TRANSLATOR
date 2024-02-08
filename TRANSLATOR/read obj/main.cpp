#include <iostream>
#include "./headers/OBJReader.h"
#include "./headers/OBJWriter.h"
#include "./headers/Triangulation.h"

int main()
{
    try
    {
        string filepath = "D:/sonali_workspace/C++/TRANSLATOR/read obj/resources/cube1.obj";
        string filepath1 = "D:/sonali_workspace/C++/TRANSLATOR/read obj/output/writeObj.txt";
        Geometry::Triangulation triangulation;
        Geometry::OBJReader objReader;
        objReader.readOBJ(filepath, triangulation);

        Geometry::OBJWriter objWriter;
        objWriter.writeOBJ(filepath1, triangulation);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}