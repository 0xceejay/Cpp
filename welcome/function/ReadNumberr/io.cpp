#include <iostream>

int readNumber() {
    int x {};
    std::cout << "Enter a number: ";
    std::cin >> x;
    return x;
}

void writeAnswer(int answer) {
    std::cout << "The answer is: " << answer << '\n';
}
