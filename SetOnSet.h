#ifndef PDSD_5_SETLAB5_LEVIN_H
#define PDSD_5_SETLAB5_LEVIN_H
#include <set>
#include <string>

class SetOnSet {
private:
    std::set<int> SetSet;
public:
    SetOnSet();
    SetOnSet(const SetOnSet& anotherSetOnList);
    ~SetOnSet();

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
    bool check_subset(SetOnSet&);
    // равенство двух множеств
    bool equality_set(SetOnSet&);
    // пересечение двух множеств
    SetOnSet set_union(SetOnSet);
    // пересечение двух множеств
    SetOnSet set_intersection(SetOnSet);
    // разность множеств
    SetOnSet set_difference(SetOnSet);
    // симметричная разность
    SetOnSet set_symmetrical_difference(SetOnSet);
};

#endif //PDSD_5_SETLAB5_LEVIN_H
