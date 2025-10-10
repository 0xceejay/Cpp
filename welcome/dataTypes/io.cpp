#include <iostream>

double enterNumber() {
    double number{};
    std::cout << "Enter a double value: ";
    std::cin >> number;
    return number;
}

char getOperator() {
    char op{};
    std::cout << "Enter +, -, *, or /: ";
    std::cin >> op;
    return op;
}

double getResult(double x, double y, char op) {
    if (op == '+') {
        std::cout << x << " + " << y << "is " << (x + y) << '\n';
        return 0;
    } else if (op == '-') {
        std::cout << x << " - " << y << "is " << (x - y) << '\n';
        return 0;
    } else if (op == '*') {
        std::cout << x << " * " << y << "is " << (x * y) << '\n';
        return 0;
    } else if (op == '/') {
        if (y != 0) {
            std::cout << x << " / " << y << "is " << (x / y) << '\n';
        } else {
            std::cout << "Division by zero is not allowed.\n";
        }
        return 0;
    } else {
        std::cout << "Unknown operator.\n";
        return 0;
    }
}
