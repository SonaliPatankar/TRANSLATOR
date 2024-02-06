#include "../headers/STLReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
using namespace geometry;

void STLReader ::readSTL(std::string &filePath,Triangulation &triangulation)
{
    std::ifstream inputFile(filePath);
    if (!inputFile.is_open())
    {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }
    // Map to store unique points and their corresponding indices
    std::map<Point3D, int> mappedCoordinates;

    // Read each line of the STL file
    std::string line;
    int count = 1;
    int index1, index2, index3;

    while (std::getline(inputFile, line))
    {
        // Check if the line contains "vertex"
        if (line.find("vertex") != std::string::npos)
        {
            // Extract x, y, z coordinates from the line
            double x, y, z;
            istringstream iss(line);
            string keyword;
            iss >> keyword >> x >> y >> z;

            // Create a Point3D object
            Point3D p1(x, y, z);

            // Check if the point is already mapped
            auto iterator = mappedCoordinates.find(p1);

            // If not mapped, add to uniquePoints and update the mapping
            if (iterator == mappedCoordinates.end())
            {
                mappedCoordinates[p1] = triangulation.uniquePoints().size();
                triangulation.uniquePoints().push_back(p1);
            }

            // Assign indices based on the mapping
            if (count == 1)
            {
                index1 = mappedCoordinates[p1];
                count++;
            }
            else if (count == 2)
            {
                index2 = mappedCoordinates[p1];
                count++;
            }
            else if (count == 3)
            {
                index3 = mappedCoordinates[p1];
                count++;
            }
        }

        // When three vertices are processed, create a triangle and reset count
        if (count == 4)
        {
            triangulation.triangles().push_back(Triangle(index1, index2, index3));
            count = 1;
        }
    }
    // Close the STL file
    inputFile.close();
}