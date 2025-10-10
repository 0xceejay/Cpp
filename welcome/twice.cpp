#include <iostream>

int main() {
    int x {};

    std::cout << "Enter an integer: ";
    std::cin >> x;

    std::cout << "Double that number is: " << 2 * x << '\n';
    std::cout << "Triple that number is: " << 3 * x << '\n';
    return 0;
}
