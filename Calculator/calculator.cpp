#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

void printUsage() {
    std::cout << "Использование: calculator -o <operation> <value1> <value2> ... <valueN>n";
    std::cout << "Операция:n";
    std::cout << "  arccos - вычислить арккосинусn";
    std::cout << "  arcsin - вычислить арксинусn";
}

bool isValidOperation(const std::string& operation) {
    return operation == "arccos" || operation == "arcsin";
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printUsage();
        return 1;
    }

    std::string operation;
    std::vector<double> values;

    // Обработка параметров командной строки
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--operation") == 0) {
            if (i + 1 < argc) {
                operation = argv[i + 1];
                i++; // Пропускаем следующий аргумент
            } else {
                printUsage();
                return 1;
            }
        } else {
            // Позиционные параметры (значения)
            try {
                double value = std::stod(argv[i]);
                values.push_back(value);
            } catch (const std::invalid_argument&) {
                std::cerr << "Ошибка: недопустимое значение '" << argv[i] << "'n";
                return 1;
            }
        }
    }

    // Проверка на допустимость операции
    if (!isValidOperation(operation)) {
        printUsage();
        return 1;
    }

    // Выполнение вычислений
    for (const double& value : values) {
        if (operation == "arccos") {
            if (value >= -1 && value <= 1) {
                std::cout << "arccos(" << value << ") = " << acos(value) << "n";
            } else {
                std::cout << "Ошибка: значение " << value << " вне диапазона [-1, 1] для arccos.n";
            }
        } else if (operation == "arcsin") {
            if (value >= -1 && value <= 1) {
                std::cout << "arcsin(" << value << ") = " << asin(value) << "n";
            } else {
                std::cout << "Ошибка: значение " << value << " вне диапазона [-1, 1] для arcsin.n";
            }
        }
    }

    return 0;
}

