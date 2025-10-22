#include <iostream>
#include <array>
#include <string_view>
#include <string>
#include "Random.h"

namespace Potion {
    enum Type {
        healing,
        mana,
        speed,
        invinsibility,
        maxPotions
    };

    // Int array containing potion costs
    constexpr std::array cost{ 20, 30, 12, 50 };

    // String_view array containing potion names
    constexpr std::array<std::string_view, maxPotions> name{ "healing", "mana", "speed", "invisibility" };

    // Make sure they contain the same number of enumerators
    static_assert(std::size(cost) == maxPotions);
    static_assert(std::size(name) == maxPotions);

    void shop() {
        std::cout << "Here is our selection for today:\n";
        for (std::size_t index=0; index < maxPotions; ++index) {
            std::cout << index << ")" << name[index] << " costs " << cost[index] << "\n";
        }
        std::cout << "\n";
    }

}

class Player {
private:
    std::string m_name{ "none" };
    int m_potionInventory{};
    int m_gold{};

public:
    Player(const std::string_view name) :
    m_name { name },
    m_gold { Random::get(80, 100) } {}

    // Member getter functions
    const std::string& getName() const { return m_name; }
    int getGold() const { return m_gold; }
};


int main() {
    std::cout << "Welcome to Roscoe's emporium!\n";
    std::string inputName{};
    std::cout << "Enter your name: ";
    std::cin >> inputName;
    Player player{ inputName };
    std::cout << "Hello, " << player.getName() << ", you have " << player.getGold() << " gold.\n\n";

    Potion::shop();

    std::cout << "Thanks for shopping at Roscoe's potion emporium!";

    return 0;
}
