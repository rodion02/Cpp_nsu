#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_FACTORY_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_FACTORY_H
#include "parser.h"
#include "dump.h"
#include "grep.h"
#include "readfile.h"
#include "replace.h"
#include "readfile.h"
#include "sort.h"
#include "writefile.h"
#include "worker.h"


class factory {
public:
    vector<string> input;
    worker* check_subsequence(const vector<int>& subsequence, map <int, block> chain);
private:
};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_FACTORY_H
