#ifndef PDSD_COURSEWORK_SETONSTRING_H
#define PDSD_COURSEWORK_SETONSTRING_H
#include "string"


class SetOnString {
private:
    std::string SetString;
public:
    SetOnString();
    SetOnString(const SetOnString& anotherSetOnString);
    ~SetOnString();

    // проверка множества на пустоту
    bool empty_check();
    // проверка принадлежности элемента множеству
    bool check_element(int);
    // добавление нового элемента в множество
    bool add_element(int);
    // создание множества
    bool create_set(int, int, int);
    // мощность множества
    int set_size();
    // вывод элементов множества
    std::string create_string_from_set (const char*);
    // является ли первое подмножеством второго
    bool check_subset(SetOnString&);
    // равенство двух множеств
    bool equality_set(SetOnString&);
    // объединение двух множеств
    SetOnString set_union(SetOnString);
    // пересечение двух множеств
    SetOnString set_intersection(SetOnString);
    // разность множеств
    SetOnString set_difference(SetOnString);
    // симметричная разность
    SetOnString set_symmetrical_difference(SetOnString);
};


#endif //PDSD_COURSEWORK_SETONSTRING_H
