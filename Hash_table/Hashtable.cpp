#include "Hashtable.h"
#include <iostream>
#include <list>

using namespace std;


int hash_func(const Key& s, int table_size){
    int index = 0;
    for (char k : s) {
        index = index + int(k);
    }
    index %= table_size;
    return  index;
}


//constructor
HashTable::HashTable() {
    size_table = vector_size;      // Задаём размер нашей таблицы
    records = 0;                    // Количество элеметов равна 0
    list<pair<Key, Value>>* null_vec = nullptr;     // Задаём ссылку на список пар ключ/значение
    table.resize(size_table, null_vec);     // Задаём вектор списков
}

//destructor
HashTable::~HashTable() {
    clear();    // Очищаем таблицу от всех значений
    for (auto& it : table) {
        delete it;      // Сносим все значения
    }
}

//constructor (HashTable a(b);) copy
HashTable::HashTable(const HashTable& b){
    size_table = b.size_table;  // Задаём размер таблицы
    records = b.records;    // Количество элементов
    table = b.table;    // Переносим первую таблицу во вторую
}

//constructor move
HashTable::HashTable(HashTable&& b)  noexcept {
    size_table = b.size_table;  // Делаем сначала всю ту же процедуру
    records = b.records;        //
    table = b.table;            //
    for (auto& it : b.table) {
        it = nullptr;       // Избавляемся от всех элементов первой таблицы
    }
    b.size_table = 0;   //  Подчищаем все параметры первой таблицы
    b.records = 0;      //
}

//copying operator q = b
HashTable& HashTable::operator=(const HashTable& b) {
    if (this == &b) {
        return *this;   // Если приравниваем один и тот же элемент (с одинаковым адресом), то возвращае то, что и было
    }
    size_table = b.size_table;      // Задаём новые параметры для 2 таблицы
    records = b.records;            //
    table.clear();                  // Очищаем первую таблицу для записи
    table = b.table;                // Заполняем её
    return *this;                   // Возвращаем присвоенное значение
}


HashTable& HashTable::operator=(HashTable&& b)  noexcept {
    if (this == &b) {
        return *this;   // Также если приравниваем элементы с одним адресом => с одним и  тем же значением
    }
    size_table = b.size_table;      // Задаём параметры для 2 таблицы
    records = b.records;            //
    table = b.table;                // Заполняем её
    for (auto& it : b.table) {
        it = nullptr;
    }
    b.size_table = 0;       // Очищаем параметры 2 таблицы
    b.records = 0;          //
    return *this;
}

//поискать про l-value и r-value
void HashTable::resize(){
    vector<list<pair<Key, Value>>*> new_table;  // Создаём новую переменую типа нашего вектора
    size_table *= 2;    // Увеличиваем размер таблицы в 2 раза
    list<pair<Key, Value>>* null_vec = nullptr;     // Делаем всё то же самое, что и при создании таблицы
    new_table.resize(size_table, null_vec);         //

    for (int i = 0; i != size_table/2; i++){        // А теперь заново заполняем элементы измененной таблицы
        if (!new_table[i]->empty()){
            for (auto & it : *new_table[i]) {
                insert(it.first, it.second);    // По новой хэшируем элемент и вставляем его по новому адресу
            }
        }
    }

    table.clear();      // Первоночальную таблицу чистим
    table = new_table;  // Передаём параметры второй таблицы во вторую
}


void HashTable::swap(HashTable &b) {
    if (this == &b)
        return;     // Если элементы равны (имеют одинаковую ссылку), то ничего не делаем
    std::swap(records, b.records);  // Иначе сначала свопаем их числа элементов
    std::swap(size_table, b.size_table);    // Размер таблицы
    table.swap(b.table);    // А затем свопаем все элементы таблиц

}


void HashTable::clear(){
    records = 0;                                    // Алгоритм почти тот же самый, что и при создании таблицы
    size_table = 0;                                 //
    list<pair<Key, Value>>* null_list = nullptr;    //
    table.resize(size_table, null_list);            //
}


bool HashTable::erase(const Key& k) {
    if (!contains(k))
        return false;   // Если удаляемого элемента нет, то возвращаем ошибку

    int index = hash_func(k, size_table);   // Находим индекс удаляемого элемента
    for (auto it = table[index]->begin(); it != table[index]->end(); it++){
        if (it->first == k) {       // Пробегаемся по элементам списка, пока не находим нужный
            table[index]->erase(it);    // Удаляем его с помощью функции erase для списков
            records--;      // Обновляем данные о количестве элементов
            return true;
        }
    }
    return true;
}


bool HashTable::insert(const Key& k, const Value& v){
    if (contains(k))
        return false;   // Если данный элементу же есть в таблице, то возвращаем ошибку

    int hash = hash_func(k, size_table);    // Иначе ищем индекс элемента с помощью хеширования

    if (table[hash] == nullptr){
        table[hash] = new list<pair<Key, Value>>;   // Если список пустой (имеет нулевой указатель), то выделяем память
        // с помощью функции new
    }

    table[hash]->push_front(make_pair(k, v));   // Закидываем нашу связку ключ/значение в список

    if(table[hash]->size()>list_size){  // Проверяем, не превысило ли количество элементов списка, максимального
        resize();   // Если да, то увеличиваем таблицу
    }
    records++;  // Увеличиваем показатель элементов
    return true;
}


bool HashTable::contains(const Key& k) const{
    int hash = hash_func(k, size_table);    // Находим индекс интересующего нас элемента
    if(table[hash] == nullptr){     // Если спсиок под данным индексом имеет нулевой адрес, то он пуст => элемента нет
        return false;
    }

    for (auto & it : *table[hash]) {
        if (it.first == k)  // Пробегаемся по списку и ищем наш элемент
            return true;
    }
    return false;
}


Value& HashTable::operator[](const Key &k) {
    if (contains(k)){   // Проверяем сначала наличие такого элемента в таблице
        int hash = hash_func(k, size_table);    // Находим его индекс в таблице
        for (auto & it : *table[hash]){     // Ищем его по списку
            if (it.first == k){     // Если находим его, то возвращаем значение
                return it.second;
            }
        }
    }
    insert(k, default_student);     // Если элементат такого нет, то вставляем параметры обычного ученика по данному
    // адресу
    return default_student;     // Возвращаем наши параметры
}


Value& HashTable::at(const Key &k) const {
    if (contains(k)){       // То же самое, что и функция до этого
        int hash = hash_func(k, size_table);    // Также его ищем
        for (auto & it : *table[hash]){         //
            if (it.first == k){                 //
                return it.second;               //
            }
        }
    }
    throw out_of_range("Student doesnt exist");     // Но в случае, если не нашли элемент, то кидаем ошибку
}


size_t HashTable::size() const{
    return records;     // Ну тут даже объяснять нечего
}


bool HashTable::empty() const{
    if (!records)   // Сверяем число элементов, тут тоже всё просто
        return true;
    else
        return false;
}


bool operator==(const HashTable& a, const HashTable& b){
    bool size = (a.size_table == b.size_table);     // Проверяем равны ли параметры таблиц
    bool tables = (a.table == b.table);               // А затем и сами элементы
    return size && tables;      // Возвращаем Коньюкции выражений
}


bool operator!=(const HashTable& a, const HashTable& b){
    bool size = a.size_table == b.size_table;   // То же самое что и до этого, но наоборот
    bool tables = a.table == b.table;           //
    bool r = !(size && tables);                    //
    return r;                                  // Возвращаем противоположное
}