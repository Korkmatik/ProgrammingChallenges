#include <iostream>
#include <map>

int main()
{
    int n;
    std::cin >> n;

    std::map<std::string, int> polyhedrons;
    polyhedrons.insert(std::make_pair<std::string, int>("Tetrahedron", 4));
    polyhedrons.insert(std::make_pair<std::string, int>("Cube", 6));
    polyhedrons.insert(std::make_pair<std::string, int>("Octahedron", 8));
    polyhedrons.insert(std::make_pair<std::string, int>("Dodecahedron", 12));
    polyhedrons.insert(std::make_pair<std::string, int>("Icosahedron", 20));

    std::string input;
    int faces = 0;
    for (int i = 0; i < n; i++)
    {
        std::cin >> input;
        faces += polyhedrons.at(input);
    }

    std::cout << faces << std::endl;

    return 0;
}