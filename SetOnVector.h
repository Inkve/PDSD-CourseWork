#ifndef PDSD_COURSEWORK_SetOnVector_H
#define PDSD_COURSEWORK_SetOnVector_H
#include "vector"
#include "string"

class SetOnVector {
private:    
    std::vector<int> SetVector;
public:
    SetOnVector();
    SetOnVector(const SetOnVector& anotherSetOnVector);
    ~SetOnVector();

    // проверка множества на пустоту
    bool empty_check();
    // проверка принадлежности элемента множеству
    bool check_element(int);
    // lобавление нового элемента в множество
    bool add_element(int);
    // создание множества
    bool create_set(int, int, int);
    // мощность множества
    int set_size();
    // вывод элментов множества
    std::string create_string_from_set (const char*);
    // является ли первое подмножеством второго
    bool check_subset(SetOnVector&);
    // равенство двух множеств
    bool equality_set(SetOnVector&);
    // пересечение двух множеств
    SetOnVector set_union(SetOnVector);
    // пересечение двух множеств
    SetOnVector set_intersection(SetOnVector);
    // разность множеств
    SetOnVector set_difference(SetOnVector);
    // симметричная разность
    SetOnVector set_symmetrical_difference(SetOnVector);
};


#endif //PDSD_COURSEWORK_SetOnVector_H
