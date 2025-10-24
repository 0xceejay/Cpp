#include <iostream>
#include <vector>

int factorial(int num) {
    if (num <= 0) {
        return 1;
    }

    return num * factorial(num - 1);
}

int main() {
    std::cout << factorial(7);
    return 0;
}
