#include <iostream>

int main() {
    int vertical{ 1 };
    while (vertical <= 5) {
        int horizontal{ 5 };
        while (horizontal >= vertical) {
            std::cout << horizontal << " ";
            --horizontal;
        }
        std::cout << "\n";
        ++vertical;
    }
}
