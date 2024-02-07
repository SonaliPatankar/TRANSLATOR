#include "../headers/StlToObj.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

void geometry :: StlToObj ::stlToObjConversion(std::string &filePath, Triangulation &triangulation)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }
    // Write vertices to the OBJ file
    vector<Point3D> &points = triangulation.uniquePoints();
    for (size_t i = 0; i < points.size(); i++)
    {
        outFile << "v"
                << " " << points[i].x() << " " << points[i].y() << " " << points[i].z() << endl;
    }

    outFile << endl; // Separate vertices and faces in the OBJ file

    // Write faces to the OBJ file
    vector<Triangle> &triangles = triangulation.triangles();
    for (const Triangle &triangle : triangles)
    {
        // In OBJ format, vertex indices are 1-based, so add 1 to each index
        outFile << "f"
                << " " << triangle.v1() + 1 << "//"
                << " " << triangle.v2() + 1 << "//"
                << " " << triangle.v3() + 1 << "//" << endl;
    }

    // Close the OBJ file
    outFile.close();

    cout << "Data writing from .stl to text file successful!" << endl;
}