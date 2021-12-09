#include <stdexcept>
#include <iostream>
#include "parser.h"
#include "factory.h"
using namespace std;


int main() {
    string file = "config.txt";
    parser redactor;
    redactor.parse(file);
    factory dungeon_master;
    dungeon_master.check_subsequence(redactor.subsequence, redactor.chain);
    return 0;
}
