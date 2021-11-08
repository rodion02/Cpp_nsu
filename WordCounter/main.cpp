#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <set>

using namespace std;

int main() {
    ofstream table;    //требуется для последующего вывода
    int percent = 0;
    map <string, int> spisok;
    list<string> keys;    //список ключей из map, а точнее слова
    list<int> nums;    //список значений, а точнее количества вхождений слова в файл
    string line;
    string input;  //входной файл
    string output; //итоговый файл
    cin >> input >> output;    //считываем все данные из входной строки
    table.open(output);
    table << "Word; number; percentage";    //делаем 3 столбца для каждого значения
    table << std::endl;
    ifstream in(input); // окрываем файл для чтения
    if (in.is_open())
    {
        while (getline(in, line))   //считываем строку в line
        {
            stringstream ss(line); //разбиваем строку на слова
            string x;
            while(ss >> x)
                if (x[x.length()-1] == ','){    //если есть запяиая после слова, то убираем её
                    x.erase (x.length()-1);
                    spisok[x] += 1; //увеличиваем счётчик вхождения слова в файл
                    percent++;  //ведём подсчёт количества слов в файле
                }
                else{
                    spisok[x] += 1;
                    percent++;
                }
        }
    }
    in.close();     // закрываем файл

    set<pair<int, string>> s;  //создаём массив пар

    for (auto const &kv : spisok)
        s.emplace(kv.second, kv.first);  //закидываем значения из map в массив пар, но сначала меняем их местами, чтобы остортировать по количеству вхождений

    for (auto const &vk : s) {
        nums.push_back(vk.first);   //закидываем каждые значения в подходящие им списки, но теперь они отсортированы по значению, а не по ключам
        keys.push_back(vk.second);
//        cout << vk.second << " - " << vk.first << std::endl;
    }

    cout << "\n" << std::endl;

    list<string>::reverse_iterator it2 = keys.rbegin();   //а теперь выводим данные списки в обратном порядке => получим таблицу слов по их убыванию
    for(list<int>::reverse_iterator it1 = nums.rbegin(); it1 != nums.rend(); it1++, it2++){
        float chastota = (*it1 / double(percent)) * 100;
        table << *it2 << ";" << *it1 << ";" << chastota;
        table << endl;
//        cout << *it2 << " vstretilos " << *it1 << " chastota " << chastota << "%" << std::endl;
    }
    table.close();  //закрываем csv файл

    return 0;
}