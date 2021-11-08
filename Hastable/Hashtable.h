#ifndef HASH_TABLE_HASHTABLE_H
#define HASH_TABLE_HASHTABLE_H

// введем типы ключей и значений: ключом будет выступать строка (например, имя
// студента, значением - произвольная структура (например, численные
// характеристики студента.
#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Student {
    unsigned age;
    unsigned weight;
};

typedef string Key;     //ключом будет выступать строка(имя студента)
typedef Student Value;  //значением - произвольная структура(численные характеристики студента)

int hash_func(const Key& s, int table_size);

class HashTable {
private:
    static const int list_size = 5;
    static const int vector_size = 10;
    vector<list<pair<Key, Value>>*> table;
    int size_table;
    int records;

    Value default_student{1337, 1337};
public:
    HashTable();

    ~HashTable();

    HashTable(const HashTable& b);

    HashTable(HashTable&& b) noexcept ;

    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b) noexcept ;

    void resize();

    // Обменивает значения двух хэш-таблиц.
    void swap(HashTable& b);

    // Очищает контейнер.
    void clear();
    // Удаляет элемент по заданному ключу.
    bool erase(const Key& k);
    // Вставка в контейнер. Возвращаемое значение - успешность вставки.
    bool insert(const Key& k, const Value& v);

    // Проверка наличия значения по заданному ключу.
    bool contains(const Key& k) const;

    // Возвращает значение по ключу. Небезопасный метод.
    // В случае отсутствия ключа в контейнере, следует вставить в контейнер
    // значение, созданное конструктором по умолчанию и вернуть ссылку на него.
    Value& operator[](const Key& k);

    // Возвращает значение по ключу. Бросает исключение при неудаче.
    Value& at(const Key& k) const;

    size_t size() const;
    bool empty() const;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);
};

#endif //HASH_TABLE_HASHTABLE_H
