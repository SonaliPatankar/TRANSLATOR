#include <iostream>
#include <fstream>
#include <sstream>
#include "../headers/OBJReader.h"

void Geometry::OBJReader::readOBJ(std::string &filePath, Triangulation &triangulation)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filePath << std::endl;
        return;
    }

    std::string line;
    string token;
    // Read each line of the OBJ file
    while (std::getline(file, line))
    {
        // Check if the line contains vertex information (starting with "v")
        if (line.find("v") != string::npos)
        {
            double x, y, z;
            istringstream iss(line);
            iss >> token >> x >> y >> z;

            if (token == "v")
            {
                // Create a Point3D object and add it to the Triangulation's list of unique points
                Point3D point(x, y, z);
                triangulation.uniquePoints().push_back(point);
            }
        }

        if (line.find("vn") != string::npos)
        {
            double x;
            double y;
            double z;
            istringstream iss(line);
            iss >> token >> x >> y >> z;

            if (token == "vn")
            {
                // Create a Point3D object and add it to the Triangulation's list of unique points
                Point3D point(x, y, z);
                triangulation.uniqueNormals().push_back(point);
            }
        }
        // Check if the line contains face information (starting with "f")
        if (line.find("f") != string::npos)
        {
            string x, y, z;
            istringstream iss(line);
            iss >> token >> x >> y >> z;

            if (token == "f")
            {
                // Convert string vertex indices to integers and create a Triangle object
                int v1;
                int v2;
                int v3;
                cout<<x<<endl;
                int normalIndex;
                v1 = stoi(x) - 1;
                v2 = stoi(y) - 1;
                v3 = stoi(z) - 1;
                
                for (int i = x.size(); i > 0; i--)
                {
                    if (x[i] == '/')
                    {
                        normalIndex = stoi(x.substr(i + 1, x.size() - i - 1));
                        break;
                    }
                }
                Triangle triangle(v1, v2, v3);
                triangle.setNormalIndex(normalIndex);
                triangulation.triangles().push_back(triangle);
            }
        }
    }
    file.close();
}
