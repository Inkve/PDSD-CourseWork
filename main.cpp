#include <iostream>
#include "SetOnString.h"
#include "string"
#include <iomanip>

int main() {
    // Set column width and delimiter
    const int col_width = 25;
    const char delimiter = '-';
    const char row_delimiter = '|';


    std::cout << "Введите мощность множества: " << std::endl;
    std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3) << "" << std::endl;
    // Set table headers
     std::string headers[] = { "", "Односвязный список       ", "Класс список             ", "List", "Set", "String", "Vector" };

    // Set table rows
    std::string rows[] = { "Создание множества       ", "Мощность                 ", "Подмножество A-A         ", "Подмножество B-A         "
                           , "Равенство A-A            ", "Равенство B-A            ", "Объединение              ", "Пересечение              ",
                           "Разница A-B              ", "Симметричная разница     "};

    // Print headers
    std::cout << std::left << std::setw(col_width) << std::setfill(' ') << headers[0] << "|";
    for (int i = 1; i < 7; i++) {
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << headers[i] << "|";
    }
    std::cout << std::endl;

    // Print delimiter between headers and rows
    std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3) << "" << std::endl;

    // Print rows
    for (int i = 0; i < 10; i++) {
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << rows[i] << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::left << std::setw(col_width) << std::setfill(' ') << "" << row_delimiter;
        std::cout << std::endl;
        // Print delimiter after each row
        std::cout << std::setfill(delimiter) << std::setw((col_width + 36) * 3) << "" << std::endl;
    }
}
