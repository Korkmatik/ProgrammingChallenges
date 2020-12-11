#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main()
{
    vector<bool> run;
    vector<string> instructions;
    fstream input;
    input.open("input");
    if (!input.is_open()) {
        cout << "The input file could not be opened" << endl;
        return 1;
    }

    string line;
    while (getline(input, line)) {
        instructions.push_back(line);
        run.push_back(false);
    }
    input.close();

    int accumulator = 0;
    for (int i = 0; i < instructions.size();) {
        string line = instructions[i];

        regex instructionRegex("[a-zA-Z]+");
        smatch instructionMatch;
        regex_search(line, instructionMatch, instructionRegex);

        regex numberRegex("(\\-|\\+)[0-9]+");
        smatch numberMatch;
        regex_search(line, numberMatch, numberRegex);

        string instruction = instructionMatch.str(0);
        int num = stoi(numberMatch.str(0));

        if (instruction == "jmp")
                i += num;
        else
            i++;
        
        if (instruction == "acc")
                accumulator += num;

        // Checking if instruction has been run
        if (run[i] == true) {
            cout << "Accumulator: " << accumulator << endl;
            return 0;
        }

        run[i] = true;
    }

    return 0;
}