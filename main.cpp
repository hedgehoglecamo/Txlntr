#include <iostream>
#include <cmath>

void printUsage() {
    std::cout << "Использование: калькулятор -o <операция> <операнды>" << std::endl;
    std::cout << "Поддерживаемые операции:" << std::endl;
    std::cout << "  -o ln x            : Вычислить натуральный логарифм x" << std::endl;
    std::cout << "  -o logyx y x      : Вычислить логарифм x по основанию y" << std::endl;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    std::string operation = argv[2];

    if (operation == "ln") {
        if (argc != 4) {
            std::cerr << "Ошибка: операция ln требует ровно 1 операнда." << std::endl;
            return 1;
        }

        double x = std::stod(argv[3]);
        double result = std::log(x);

        std::cout << "ln " << x << " = " << result << std::endl;
    } else if (operation == "logyx") {
        if (argc != 5) {
            std::cerr << "Ошибка: операция logyx требует ровно 2 операнда." << std::endl;
            return 1;
        }

        double y = std::stod(argv[3]);
        double x = std::stod(argv[4]);
        double result = std::log(x) / std::log(y);

        std::cout << "log_" << y << " " << x << " = " << result << std::endl;
    } else {
        std::cerr << "Ошибка: Неподдерживаемая операция." << std::endl;
        printUsage();
        return 1;
    }

    return 0;
}
