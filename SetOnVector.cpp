#include "SetOnVector.h"
#include <algorithm>
#include <time.h>
#include "string.h"


SetOnVector::SetOnVector() {};

SetOnVector::SetOnVector(const SetOnVector& anotherSetOnVector) {
    SetVector = anotherSetOnVector.SetVector;
};

SetOnVector::~SetOnVector() {
    SetVector.clear();
};

// проверка множества на пустоту
bool SetOnVector::empty_check() {
    return SetVector.empty();
};

// проверка принадлежности элемента множеству
bool SetOnVector::check_element(int value) {
    if (empty_check()) {
        return false;
    }
    return std::find(SetVector.begin(), SetVector.end(), value) != SetVector.end();
};

// lобавление нового элемента в множество
bool SetOnVector::add_element(int value) {
    if (check_element(value)) {
        return false;
    }
    SetVector.push_back(value);
    return true;
};

// создание множества
bool SetOnVector::create_set(int count, int min, int max) {
    if ((max - min + 1) <= count) {
        return false;
    }
    SetVector.clear();

    while (count)
    {
        int value = min + (rand() % static_cast<int>(max - min + 1));
        if (add_element(value)){
            count--;
        };
    }
    return true;
};


// мощность множества
int SetOnVector::set_size() {
    return SetVector.size();
};

// вывод элементов множества
std::string SetOnVector::create_string_from_set (const char* divider) {
    if (empty_check()) {
        return "";
    }
    std::string result = "";
    for (const auto& element : SetVector) {
        result += std::to_string(element);
        result += divider;
    }
    result.erase(result.size() - strlen(divider));
    return result;
};

// является ли первое подмножеством второго
bool SetOnVector::check_subset(SetOnVector& anotherSet) {
    if (empty_check()) {
        return true;
    };
    if (!empty_check() && anotherSet.empty_check()) {
        return false;
    }

    for (const auto& element : SetVector) {
        if (!anotherSet.check_element(element)) {
            return false;
        }
    }
    return true;
};

// равенство двух множеств
bool SetOnVector::equality_set(SetOnVector& anotherSet) {
    return check_subset(anotherSet) && anotherSet.check_subset(*this);
};

// пересечение двух множеств
SetOnVector SetOnVector::set_union(SetOnVector anotherSet) {
    SetOnVector returnSet;
    for (const auto& element : SetVector) {
        returnSet.add_element(element);
    }
    for (const auto& element : anotherSet.SetVector) {
        returnSet.add_element(element);
    }
    return returnSet;
};

// пересечение двух множеств
SetOnVector SetOnVector::set_intersection(SetOnVector anotherSet) {
    SetOnVector returnSet;

    if (empty_check() || anotherSet.empty_check()) {
        return returnSet;
    };

    for (const auto& element : SetVector) {
        if (anotherSet.check_element(element)) {
            returnSet.add_element(element);
        };
    }
    return returnSet;
};

// разность множеств
SetOnVector SetOnVector::set_difference(SetOnVector anotherSet) {
    SetOnVector returnSet;

    if (empty_check()){
        return returnSet;
    };

    for (const auto& element : SetVector) {
        if (!anotherSet.check_element(element)) {
            returnSet.add_element(element);
        };
    }
    return returnSet;
};

// симметричная разность
SetOnVector SetOnVector::set_symmetrical_difference(SetOnVector anotherSet) {
    return set_union(anotherSet).set_difference(set_intersection(anotherSet));
};

