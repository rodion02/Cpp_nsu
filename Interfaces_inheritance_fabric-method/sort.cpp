#include "sort.h"

vector<string> _sort::work(vector<string> commands, vector<string> input) {
    std::sort(input.begin(), input.end());
    return input;
}
