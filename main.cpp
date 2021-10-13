#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <set>

int main() {
    std::ofstream table;
    int percent = 0;
    std::map <std::string, int> spisok;
    std::list<std::string> keys;
    std::list<int> nums;
    std::string line;
    std::string input;
    std::string output;
    std::cin >> input >> output;
    table.open(output);
    table << "Word; number; percentage";
    table << std::endl;
    std::ifstream in(input); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))
        {
            std::stringstream ss(line);
            std::string x;
            while(ss >> x)
                if (x[x.length()-1] == ','){
                    x.erase (x.length()-1);
                    spisok[x] += 1;
                    percent++;
                }
                else{
                    spisok[x] += 1;
                    percent++;
                }
        }
    }
    in.close();     // закрываем файл

    std::set<std::pair<int, std::string>> s;  // The new (temporary) container.

    for (auto const &kv : spisok)
        s.emplace(kv.second, kv.first);  // Flip the pairs.


    for (auto const &vk : s) {
        nums.push_back(vk.first);
        keys.push_back(vk.second);
//        std::cout << vk.second << " - " << vk.first << std::endl;
    }

    std::cout << "\n" << std::endl;

    std::list<std::string>::reverse_iterator it2 = keys.rbegin();
    for(std::list<int>::reverse_iterator it1 = nums.rbegin(); it1 != nums.rend(); it1++, it2++){
        float chastota = (*it1 / double(percent)) * 100;
        table << *it2 << ";" << *it1 << ";" << chastota;
        table << std::endl;
//        std::cout << *it2 << " vstretilos " << *it1 << " chastota " << chastota << "%" << std::endl;
    }
    table.close();

    return 0;
}
