#include "../headers/ObjToStl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"
using namespace std;

void geometry :: ObjToStl::objToStlConversion(std::string &filePath, Triangulation &triangulation)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening text file." << endl;
        return;
    }

    // Extract points and triangles from the triangulation
    vector<Point3D> &points = triangulation.uniquePoints();
    vector<Triangle> &triangles = triangulation.triangles();

    outFile << "solid" << endl;

    // Write each triangle to the STL file
    for (const Triangle &triangle : triangles)
    {
        // Write facet information
        outFile << "facet normal" << endl;
        outFile << "outer loop" << endl;

        // Write vertex information for each point of the triangle
        outFile << "vertex"
                << " " << points[triangle.v1() - 1].x() << " " << points[triangle.v1() - 1].y() << " " << points[triangle.v1() - 1].z() << endl;
        outFile << "vertex"
                << " " << points[triangle.v2() - 1].x() << " " << points[triangle.v2() - 1].y() << " " << points[triangle.v2() - 1].z() << endl;
        outFile << "vertex"
                << " " << points[triangle.v3() - 1].x() << " " << points[triangle.v3() - 1].y() << " " << points[triangle.v3() - 1].z() << endl;

        outFile << "endloop" << endl;
        outFile << "endfacet" << endl;
    }

    outFile << "endsolid";
    outFile.close();

    cout << "Data writing from .obj to text file successful!" << endl;
}
