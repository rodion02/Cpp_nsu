#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_PARSER_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_PARSER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <vector>

using namespace std;


typedef struct{
    string command;
    vector<string> arguments;
}block;


class parser {
public:
    parser();
    void parse(const string& s1);
    map <int, block> chain;
    vector <int> subsequence;
};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_PARSER_H
