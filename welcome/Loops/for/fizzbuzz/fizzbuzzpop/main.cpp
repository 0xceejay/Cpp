#include <iostream>

void fizzbuzzpop (int x) {
    for (int i{1}; i <= x; ++i) {
        if ((i % 3 == 0) & (i % 5 == 0) & (i % 7 == 0)) {
            std::cout << "fizzbuzzpop\n";
        } else if ((i % 3 == 0) & (i % 5 == 0)) {
            std::cout << "fizzbuzz\n";
        } else if (i % 3 == 0) {
            std::cout << "fizz\n";
        } else if (i % 5 == 0) {
            std::cout << "buzz\n";
        } else {
            std::cout << i << "\n";
        }
    }
}

int main () {
    fizzbuzzpop(150);
    return 0;
}
