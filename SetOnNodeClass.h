#ifndef PDSD_COURSEWORK_SETONNODECLASS_H
#define PDSD_COURSEWORK_SETONNODECLASS_H

#include <ctime>
#include <stdlib.h>
#include <string>

class SetOnNodeClass
{
private:
    struct Node
    {
        Node* next;
        int value;
    };
    Node* head;

public:
    SetOnNodeClass();
    SetOnNodeClass(const SetOnNodeClass&);
    ~SetOnNodeClass();

    bool empty_check();
    // проверка принадлежности элемента множеству
    bool check_element(int);
    // добавление нового элемента в множество
    Node* add_element(int);
    // создание множества
    Node* create_set(int, int, int);
    // мощность множества
    int set_size();
    // вывод элементов множества
    std::string create_string_from_set (const char*);
    // удаление множества
    Node* delete_set();
    // является ли первое подмножеством второго
    bool check_subset(SetOnNodeClass&);
    // равенство двух множеств
    bool equality_set(SetOnNodeClass&);
    // объединение двух множеств
    SetOnNodeClass set_union(SetOnNodeClass);
    // пересечение двух множеств
    SetOnNodeClass set_intersection(SetOnNodeClass);
    // разность множеств
    SetOnNodeClass set_difference(SetOnNodeClass);
    // симметричная разность
    SetOnNodeClass set_symmetrical_difference(SetOnNodeClass);
};

#endif //PDSD_COURSEWORK_SETONNODECLASS_H
