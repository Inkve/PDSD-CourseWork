#include "additional.h"

int inputInt(const char * prompt, int m = INT_MIN, int M = INT_MAX)
{
    int N;
    for (;;) {
        std::cout << prompt << " (целое от " << m << " до " << M << "): " << std::flush;
        if ((std::cin >> N).good() && (m <= N) && (N <= M)) return N;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cout << "Неверный ввод, повторите.\n";
        } else {
            std::cout << "Число вне допустимого диапазона значений. Повторите ввод.\n";
        }
        std::cin.ignore(LONG_MAX,'\n');
    }
}

