#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int num_bags = 0;
set<string> uniqueBags;
void get_bags(string bagName, const vector<string>& lines)
{
    cout << "Searching for bag: " << bagName << endl;

    vector<string> bagTypes;
    for (const string& line : lines) {
        int pos = line.find(bagName);
        if (pos != string::npos && pos != 0) {
            cout << "found at pos " << pos << ": " << line << endl;

            string bag;
            int bagPos = line.find(" bags contain");
            bag = line.substr(0, bagPos);

            std::cout << "fond bag: " << bag << endl;

            bagTypes.push_back(bag);
            uniqueBags.insert(bag);
        }
    }

    num_bags += bagTypes.size();

    for (int i = 0; i < bagTypes.size(); i++) {
        get_bags(bagTypes[i], lines);
    }
}

int main()
{
    fstream inputFile;
    inputFile.open("input");

    if (!inputFile.is_open()) {
        cout << "Failed to open file" << endl;
        return 0;
    }

    string line;
    vector<string> lines;
    while(getline(inputFile, line)) {
        lines.push_back(line);
    }
    
    get_bags("shiny gold", lines);

    std::cout << "Number bags that can contain at least one shiny gold bag: " << uniqueBags.size() << endl;

    return 0;
}