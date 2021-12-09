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
    static void parse(const string& s1);
    static map <int, block> chain;
    static vector <int> subsequence;
};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_PARSER_H
