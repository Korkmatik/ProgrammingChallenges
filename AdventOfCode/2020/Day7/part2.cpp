#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <fstream>
#include <regex>

using namespace std;

set<string> bags;
vector<string> lines;

int count_bags(const string& bagName) 
{
    int num_bags = 0;
    vector<string> bags;
    for (int i = 0; i < lines.size(); i++) {
        string line = lines[i];
        int pos = line.find(bagName);

        if (pos == 0) {
            regex regexp("[0-9] [a-zA-Z\\s]+ bag(s)?(,|\\.)?");
            smatch m;

            //cout << "Bags:" << endl;            
            while (regex_search(line, m, regexp)) {
                regex regnr("[0-9]");
                string bagInfo = m.str(0);
                smatch match_num;
                regex_search(bagInfo, match_num, regnr);
                string num_str = match_num.str(0);
                int num = atoi(num_str.c_str());

                regex regexp_name_start("[a-zA-Z]");
                smatch match_name_start;
                regex_search(bagInfo, match_name_start, regexp_name_start);
                string bag_name = bagInfo.substr(match_name_start.position(0), bagInfo.find(" bag") - 2);

                // cout << "Number: " << num << endl;
                // cout << "Bag Name:" << bag_name << endl;
                line = m.suffix().str();

                bags.push_back(bag_name);
                num_bags += num;
                num_bags += num * count_bags(bag_name);
            }
        }
    }

    cout << "Bag: " << bagName << ", has num bags: " << num_bags << endl;

    return num_bags;
}

int main()
{
    fstream input;
    input.open("input");
    if (!input.is_open()) {
        cout << "could not open file" << endl;
        return 1;
    }

    string line;
    while(getline(input, line)) {
        lines.push_back(line);
    }

    cout << "Bags needed: " << count_bags("shiny gold") << endl;

    return 0;
}