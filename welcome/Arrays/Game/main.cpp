#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>

namespace Items {
    enum Types {
        healthPotions,
        torches,
        arrows,
        maxItems,
    };
}

int sumOfItems(const std::vector<int>& vec) {
    int sum { 0 };
    for ( auto i : vec) {
        sum += i;
    }
    return sum;
}

std::string_view getItemName(Items::Types type) {
    switch (type)
    {
    case Items::healthPotions:      return "health potion";
    case Items::torches:            return "torch";
    case Items::arrows:             return "arrow";
    default:                        return "none";
    }
}

void print(const std::vector<int>& items) {
    for (int i = 0; i < Items::maxItems; ++i) {
        auto item { static_cast<Items::Types>(i) };
        if (items[static_cast<std::size_t>(i)] > 1) {
            if (getItemName(item) == "torch") {
                std::cout << "You have " << items[static_cast<std::size_t>(i)] << " " << getItemName(item) << "es\n";
            } else {
                std::cout << "You have " << items[static_cast<std::size_t>(i)] << " " << getItemName(item) << "s\n";
            }
        } else {
            std::cout << "You have " << items[static_cast<std::size_t>(i)] << " " << getItemName(item) << "\n";
        }
    }
}

int main() {
    std::vector<int> numberOfItems { 1, 5, 10 };

    assert(Items::maxItems == std::size(numberOfItems));
    print(numberOfItems);

    std::cout << "You have " << sumOfItems(numberOfItems) << " total items.\n";

    return 0;
}
