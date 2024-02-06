#include "../headers/OBJReader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "../headers/Point3D.h"

using namespace std;

void geometry::OBJReader::readOBJ(std::string &filePath, Triangulation &triangulation)
{  
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return; 
    }

    std::string line;
    string keyword;

    // Read each line of the OBJ file
    while (std::getline(file, line))
    {
        // Check if the line contains vertex information (starting with "v")
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream iss(line);
            iss >> keyword >> x >> y >> z;

            if (keyword == "v")
            {
                // Create a Point3D object and add it to the Triangulation's list of unique points
                Point3D P1(x, y, z);
                triangulation.uniquePoints().push_back(P1);
            }
        }

        // Check if the line contains face information (starting with "f")
        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream iss(line);
            iss >> keyword >> x >> y >> z;

            if (keyword == "f")
            {
                // Convert string vertex indices to integers and create a Triangle object
                int v1, v2, v3;
                v1 = stoi(x) - 1;
                v2 = stoi(y) - 1;
                v3 = stoi(z) - 1;

                Triangle T(v1, v2, v3);
                triangulation.triangles().push_back(T);
            }
        }
    }
    cout << "Number of triangles: " << triangulation.triangles().size() << endl;
    file.close();
}
