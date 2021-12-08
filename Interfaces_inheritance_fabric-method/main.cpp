#include <stdexcept>
#include <iostream>
#include "parser.h"
#include "factory.h"
using namespace std;


int main(int argc, char *argv[]) {
    string file = argv[1];
    parser redactor;
    redactor.parse(file);
    factory dungeon_master;
    dungeon_master.check_subsequence(parser::subsequence, parser::chain);
    return 0;
}
