#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_READFILE_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_READFILE_H
#include "worker.h"
#include <iostream>
#include <fstream>

class readfile: public worker{
public:
    vector<string> work(vector<string> commands, vector<string> input);
private:

};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_READFILE_H
