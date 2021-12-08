#include "factory.h"
#include "parser.h"

worker* factory::check_subsequence(const vector<int>& subsequence, map<int, block> chain) {
    for(int i : subsequence) {
        if(chain[i].command == "dump"){
            worker* worker = new dump();
            worker->work(input, chain[i].arguments);
            return worker;
        }
        else if(chain[i].command == "grep"){
            worker* worker = new grep();
            worker->work(input, chain[i].arguments);
            return worker;
        }
        else if(chain[i].command == "readfile"){
            worker* worker = new readfile();
            worker->work(input, chain[i].arguments);
            return worker
        }
        else if(chain[i].command == "replace"){
            worker* worker = new _replace();
            worker->work(input, chain[i].arguments);
            return worker;
        }
        else if(chain[i].command == "sort"){
            worker* worker = new _sort();
            worker->work(input, chain[i].arguments);
            return worker;
        }
        else if(chain[i].command == "writefile"){
            worker* worker = new writefile();
            worker->work(input, chain[i].arguments);
            return worker;
        }
        else{
            throw runtime_error("Wrong name of worker!");
        }
    }
}
