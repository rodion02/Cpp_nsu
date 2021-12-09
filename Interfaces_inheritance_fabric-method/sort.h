#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_SORT_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_SORT_H
#include "worker.h"
#include <iostream>
#include <fstream>
#include <algorithm>

class _sort: public worker{
public:
    vector<string> work(vector<string> commands, vector<string> input);
private:

};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_SORT_H
