#include "parser.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <cmath>

using namespace std;



void parser::parse(const string& s1){
    ifstream input(s1);
    string line;
    if(!input.is_open()){
        throw runtime_error("Couldn't find this file");
    }
    else{
        getline(input, line);
        int t = 0;
        if(line != "desc"){
            throw runtime_error("Wrong type of file");
        }
        else if (input.eof()){
            throw runtime_error("Wrong type of file");
        }
        else{
            while(getline(input, line)){
                if (line == "csed") {
                    t += 1;
                    break;
                }
                stringstream ss(line); //разбиваем строку на слова
                string x;
                int num = 0;
                string com;
                vector<string> arg;
                ss >> x;
                int n = x.length() - 1;
                for (char i : x) {
                    if (!isdigit(i)) {
                        throw runtime_error("Wrong type of data (id is missing)");
                    }
                    else{
                        num += pow(10, n) * i;
                        n--;
                    }
                }
                ss >> x;
                if (x[0] != '=' and x.length() > 1){
                    throw runtime_error("Wrong type of data (sign '=' is missing)");
                }
                ss >> x;
                if (x != "dump" or x != "grep" or x != "readfile" or x != "replace" or x != "sort" or x != "writefile"){
                    throw runtime_error("Wrong type of data (name of method is missing)");
                }
                else{
                    com = x;
                }
                int k = 0;
                while(ss >> x){
                    arg[k] = x;
                }
                block spisok;
                spisok.command = com;
                spisok.arguments = arg;
                chain[num] = spisok;
            }
            if (t==0){
                throw runtime_error("Wrong type of data (csed is missing)");
            }

        }

    }
    int flag = 0;
    if (!getline(input, line)){
        throw runtime_error("Subsequence is missing!");
    }
    else{
        stringstream ss(line); //разбиваем строку на слова
        string x;
        int i = 0;
        while(ss>>x){
            int num = 0;
            if (isdigit(x[0])){
                int n = x.length() - 1;
                for (char i : x) {
                    if (!isdigit(i)) {
                        throw runtime_error("Wrong type of data (incorrect format of number)");
                    }
                    else{
                        num += pow(10, n) * i;
                        n--;
                    }
                }
                subsequence[i] = num;
                if (flag != 0){
                    throw runtime_error("Wrong type of data");
                }
                flag += 1;
            }
            else{
                if (x != "->"){
                    throw runtime_error("Wrong type of data (sign '->' is missing)");
                }
                if (flag != 1){
                    throw runtime_error("Wrong type of data");
                }
                flag -= 1;
            }
        }
    }
}


//Parser
//
//  |
// \|/
//
// Main
//
// /|\
//  |
//
// Factory импортирует Worker (do work) <- . sort +
//                                         . grep +
//                                         . replace +
//                                         . dump +
//                                         . readfile +
//                                         . writefile +
//
//
// —----------------------------------------—
//
//
//1) создать объект парсера.
//2) передать argc и argv в парсер
//3) Запустить парсинг методом в парсере
// . проверить, что считаный файл считался и не пустой (!filename.is_open() && filename.peek() != EOF)
// . считать отдельно первую строку конфигурационного файла и найти там "desc"
// . используя stringstream разбиваем на слова и парсим в цикле до "csed"
// (
// пример парсинга:
// id method arguments
// 1 = replace w1 w2
// пытаемся перевести 1 аргумент в число, если успех, то это индекс операции i (try/catch/throw)
// считываем символ '=', если успех, то считываем операцию, если успех, то считываем аргументы
// аппендим в список пару <i, block>, где block == block.operation и block.arguments
//
// )
// . возвращаем True, если успех считывания
//4) геттером вытащить список пар.
//5) в цикле запустить считывание операций
// . с помощью stringstream разбиваем на слова и пытаемся выполнить операции
// ! в Factory передаётся block, который парсится switch/case оператором
// ! в Factory создаётся рабочий и вызывается метод "работа"
// . если успех, читаем дальше
// . считываем стрелку, если успех, продолжаем
//6) конец