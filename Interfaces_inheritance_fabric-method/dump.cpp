#include "dump.h"


vector<string>& dump::work(vector<string>& commands, vector<string>& input) {
    ofstream output(commands.at(0));
    for (const auto& line : input)
        output << line << std::endl;

    return input;
}
