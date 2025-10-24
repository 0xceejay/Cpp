#include <iostream>
#include <vector>

int factorial(std::size_t num) {
    // static cache that persists across function calls (memoization)
    static std::vector<int> results{1}; // factorial(0) = 1

    // If already computed, return cached value
    if (num < results.size())
        return results[num];

    // Otherwise, compute recursively and store
    int value = static_cast<int>(num) * factorial(num - 1);
    results.push_back(value);
    return value;
}

int main() {
    std::cout << factorial(7);
    return 0;
}
