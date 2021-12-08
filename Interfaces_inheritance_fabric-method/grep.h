#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_GREP_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_GREP_H
#include "worker.h"
#include <iostream>
#include <fstream>

class grep: public worker{
public:
    vector<string> work(vector<string> commands, vector<string> input) override;
private:

};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_GREP_H
