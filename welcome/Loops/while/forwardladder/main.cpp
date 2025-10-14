#include <iostream>

int main() {
    int vertical { 1 };
    while (vertical <= 5) {
        int horizontal { 5 };
        while (horizontal >= 1) {
            if (horizontal <= vertical) {
                std::cout << horizontal << " ";
            }  else {
                std::cout << "  ";
            }
            --horizontal;
        }
        std::cout << "\n";
        ++vertical;
    }
}
