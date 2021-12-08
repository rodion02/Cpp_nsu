#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_REPLACE_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_REPLACE_H
#include "worker.h"
#include <iostream>
#include <fstream>

class _replace: public worker{
public:
    vector<string> work(vector<string> commands, vector<string> input) override;
private:

};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_REPLACE_H
