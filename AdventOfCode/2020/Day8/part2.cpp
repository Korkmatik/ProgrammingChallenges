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

    vector<string> originalInstr = {"jmp", "nop"};
    vector<string> newInstr = {"nop", "jmp"};

    for (int j = 0; j < 2; j++) {
        string origInstr = originalInstr[j];
        string patchInstr = newInstr[j];

        std::cout << "Original instruction: " << origInstr << endl;

        int patchPos = -1;
        while (patchPos != instructions.size()) {
            vector<string> copyInstr;
            for (int l = 0; l < instructions.size(); l++) {
                copyInstr.push_back(instructions[l]);
                run[l] = false;
            }

            for (int l = patchPos + 1; l < instructions.size(); l++) {
                

                regex instructionRegex("[a-zA-Z]+");
                smatch instructionMatch;
                regex_search(instructions[l], instructionMatch, instructionRegex);
                string instr = instructionMatch.str(0);

                if (instr == origInstr) {
                    regex numberRegex("(\\-|\\+)[0-9]+");
                    smatch numberMatch;
                    regex_search(instructions[l], numberMatch, numberRegex);

                    copyInstr[l] = patchInstr + " " + numberMatch.str(0);
                    cout << "Patches instruction: " << copyInstr[l] << "; Position: " << copyInstr[l] << endl;
                    patchPos = l;
                    break;
                }
            }

            int accumulator = 0;
            bool loop = false;
            for (int i = 0; i < copyInstr.size();) {
                string line = copyInstr[i];

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
                    //cout << "Accumulator: " << accumulator << endl;
                    loop = true;
                    break;
                }

                run[i] = true;
            }

            if (!loop) {
                cout << "No loop! Acc: " << accumulator << endl;
                return 0;
            }
        }
        
    }

    

    return 0;
}