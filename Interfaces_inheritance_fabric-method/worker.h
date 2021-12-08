#ifndef INTERFACES_INHERITANCE_FABRIC_METHOD_WORKER_H
#define INTERFACES_INHERITANCE_FABRIC_METHOD_WORKER_H
#include <string>
#include <vector>

using namespace std;


class worker {
public:
    virtual vector<string> work(vector<string> commands, vector<string> input){}
};


#endif //INTERFACES_INHERITANCE_FABRIC_METHOD_WORKER_H
