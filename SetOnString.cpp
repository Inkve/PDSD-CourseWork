#include "SetOnString.h"
#include <algorithm>
#include <ctime>
#include "string.h"


SetOnString::SetOnString() {};

SetOnString::SetOnString(const SetOnString& anotherSetOnString) {
    SetString = anotherSetOnString.SetString;
};

SetOnString::~SetOnString() {
    SetString.clear();
};

// проверка множества на пустоту
bool SetOnString::empty_check() {
    return SetString.empty();
};

// проверка принадлежности элемента множеству
bool SetOnString::check_element(int value) {
    if (empty_check()) {
        return false;
    }
    return SetString.find(std::to_string(value)) != std::string::npos;
};

// добавление нового элемента в множество
bool SetOnString::add_element(int value) {
    if (check_element(value)) {
        return false;
    }
    SetString +=  std::to_string(value) + ";";
    return true;
};

// создание множества
bool SetOnString::create_set(int count, int min, int max) {
    if ((max - min + 1) <= count) {
        return false;
    }
    SetString.clear();

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
int SetOnString::set_size() {
    int counter = 0;
    std::string temp_string = SetString;
    auto pos = temp_string.find(";");
    while (pos != std::string::npos) {
        counter++;
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");
    }
    return counter;
};

// вывод элементов множества
std::string SetOnString::create_string_from_set (const char* divider) {
    if (empty_check()) {
        return "";
    }
    std::string result = SetString;
    size_t pos;
    while ((pos = result.find(";")) != std::string::npos) {
        result.replace(pos, 1, divider);
    }
    result.erase(result.size() - strlen(divider));
    return result;
};

// является ли первое подмножеством второго
bool SetOnString::check_subset(SetOnString& anotherSet) {
    if (empty_check()) {
        return true;
    };
    if (!empty_check() && anotherSet.empty_check()) {
        return false;
    }

    std::string temp_string = SetString;
    auto pos = temp_string.find(";");
    while (pos != std::string::npos) {
        int element = stoi(temp_string.substr(0, pos));
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");

        if (!anotherSet.check_element(element)) {
            return false;
        }
    }
    return true;
};

// равенство двух множеств
bool SetOnString::equality_set(SetOnString& anotherSet) {
    return check_subset(anotherSet) && anotherSet.check_subset(*this);
};

// объединение двух множеств
SetOnString SetOnString::set_union(SetOnString anotherSet) {
    SetOnString returnSet;
    std::string temp_string = SetString;
    auto pos = temp_string.find(";");
    while (pos != std::string::npos) {
        int element = stoi(temp_string.substr(0, pos));
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");
        returnSet.add_element(element);
    }
    temp_string = anotherSet.SetString;
    pos = temp_string.find(";");
    while (pos != std::string::npos) {
        int element = stoi(temp_string.substr(0, pos));
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");
        returnSet.add_element(element);
    }
    return returnSet;
};

// пересечение двух множеств
SetOnString SetOnString::set_intersection(SetOnString anotherSet) {
    SetOnString returnSet;

    if (empty_check() || anotherSet.empty_check()) {
        return returnSet;
    };

    std::string temp_string = SetString;
    auto pos = temp_string.find(";");
    while (pos != std::string::npos) {
        int element = stoi(temp_string.substr(0, pos));
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");
        if (anotherSet.check_element(element)) {
            returnSet.add_element(element);
        };
    }
    return returnSet;
};

// разность множеств
SetOnString SetOnString::set_difference(SetOnString anotherSet) {
    SetOnString returnSet;

    if (empty_check()){
        return returnSet;
    };

    std::string temp_string = SetString;
    auto pos = temp_string.find(";");
    while (pos != std::string::npos) {
        int element = stoi(temp_string.substr(0, pos));
        temp_string = temp_string.substr(pos + 1);
        pos = temp_string.find(";");
        if (!anotherSet.check_element(element)) {
            returnSet.add_element(element);
        };
    }
    return returnSet;
};

// симметричная разность
SetOnString SetOnString::set_symmetrical_difference(SetOnString anotherSet) {
    return set_union(anotherSet).set_difference(set_intersection(anotherSet));
};

