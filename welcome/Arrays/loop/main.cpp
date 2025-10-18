#include <iostream>
#include <vector>
#include <string_view>
#include <string>

template <typename T>
bool isValueInArray(const std::vector<T>& arr, const T& v) {

    for (const auto& nam : arr) {
        if (nam == v) {
            return true;
        }
    }

    return false;
}

int main() {
    std::vector<std::string_view> names{ "Alex","Betty", "Caroline", "Dave", "Fred", "Greg", "Holly" };

    std::string name{};
    std::cout << "Enter a name: ";
    std::cin >> name;

    bool found { isValueInArray<std::string_view>(names, name) };

    if (found) {
        std::cout << name << " was found.\n";
    } else {
        std::cout << name << " was not found.\n";
    }

    return 0;
}
