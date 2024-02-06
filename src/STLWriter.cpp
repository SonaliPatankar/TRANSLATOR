// STLWriter.cpp
#include "../headers/STLWriter.h"
#include "../headers/Triangulation.h"
#include <fstream>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace geometry;

void geometry ::STLWriter ::writeSTLToFile(std::string &filePath, Triangulation &triangulationObj)
{
    std::ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    // Write triangles to the STL file
    vector<Point3D> &points = triangulationObj.uniquePoints();
    vector<Triangle> &triangles = triangulationObj.triangles();

    for (const Triangle &triangle : triangles)
    {
        // Write each vertex of the triangle to the STL file
        outFile << "vertex " << points[triangle.v1()].x() << " " << points[triangle.v1()].y() << " " << points[triangle.v1()].z() << endl;
        outFile << "vertex " << points[triangle.v2()].x() << " " << points[triangle.v2()].y() << " " << points[triangle.v2()].z() << endl;
        outFile << "vertex " << points[triangle.v3()].x() << " " << points[triangle.v3()].y() << " " << points[triangle.v3()].z() << endl;
    }

    // Close the STL file
    outFile.close();
}
