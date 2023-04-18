#ifndef PDSD_COURSEWORK_SETONLIST_H
#define PDSD_COURSEWORK_SETONLIST_H
#include <list>
#include <string>


class SetOnList {
private:
    std::list<int> SetList;
public:
    SetOnList();
    SetOnList(const SetOnList& anotherSetOnList);
    ~SetOnList();

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
    bool check_subset(SetOnList&);
    // равенство двух множеств
    bool equality_set(SetOnList&);
    // объединение двух множеств
    SetOnList set_union(SetOnList);
    // пересечение двух множеств
    SetOnList set_intersection(SetOnList);
    // разность множеств
    SetOnList set_difference(SetOnList);
    // симметричная разность
    SetOnList set_symmetrical_difference(SetOnList);
};


#endif //PDSD_COURSEWORK_SETONLIST_H