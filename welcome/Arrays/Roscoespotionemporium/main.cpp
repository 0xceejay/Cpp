#include <iostream>
#include <array>
#include <string_view>
#include <string>
#include <limits>
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
    }

}

class Player {
private:
    std::string m_name{ "none" };
    std::array<int, Potion::maxPotions> m_potionInventory{};
    int m_gold{};

public:
    explicit Player(const std::string_view name) :
        m_name { name },
        m_gold { Random::get(80, 120) } {}

    // Member getter functions
    const std::string& getName() const { return m_name; }
    int getGold() const { return m_gold; }
    const std::array<int, Potion::maxPotions>& getPotionInventory() const { return m_potionInventory; }

    // Member setter functions
    void deductGold(const int cost) {
        m_gold -= cost;
    }
    void setInventory(const std::size_t item) {
        m_potionInventory[item] += 1;
    }
};

int charNumToInt(char c) {
    return c - '0';
}

void ignoreLine() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::size_t buyPotion() {
    while (true) {
        char inputNumber{};
        std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
        std::cin >> inputNumber;

        if (!std::cin) {
            std::cin.clear(); // put us back in 'normal' operation mode
            ignoreLine(); // remove the bad input
            continue;
        }

        // If there is extraneous input, treat as failure case
        if (!std::cin.eof() && std::cin.peek() != '\n') {
            ignoreLine(); // remove the bad input
            std::cout << "That is an invalid input. Try again: \n";
            continue;
        }

        if (inputNumber == 'q') {
            return Potion::maxPotions;
        }

        int num {charNumToInt(inputNumber)};

        if (num >= 0 && num <= Potion::maxPotions) {
            return static_cast<std::size_t>(num);
        }

        std::cout << "That is an invalid input. Try again: \n";
    }
}

void printInventory(Player& player) {
    std::cout << "\nYour inventory contains:\n";
    for (std::size_t index=0; index < Potion::maxPotions; ++index) {
        if (player.getPotionInventory()[index] == 0) {
            // Do nothing
        } else {
            std::cout << player.getPotionInventory()[index] << "x potion of " << Potion::name[std::size_t(index)] << "\n";
        }
    }
    std::cout << "You escaped with " << player.getGold() << " gold remaining.\n\n";
}

void updateInventory(Player& player) {
    while (true) {
        Potion::shop();
        std::size_t chosenPotion{ buyPotion() };
        if (chosenPotion == Potion::maxPotions) {
            return;
        }

        if (player.getGold() >= Potion::cost[chosenPotion]){
            // Update Inventory
            player.deductGold(Potion::cost[chosenPotion]);
            player.setInventory(chosenPotion);
            std::cout << "You purchased a potion of " << Potion::name[chosenPotion] << ". "
                << "You have " << player.getGold() <<" gold left.\n\n";
        } else {
            std::cout << "You can not afford that.\n\n";
        }


    }
}

int main() {
    std::cout << "Welcome to Roscoe's emporium!\n";
    std::string inputName{};
    std::cout << "Enter your name: ";
    std::cin >> inputName;
    Player player{ inputName };
    std::cout << "Hello, " << player.getName() << ", you have " << player.getGold() << " gold.\n\n";


    updateInventory(player);
    printInventory(player);

    std::cout << "Thanks for shopping at Roscoe's potion emporium!";

    return 0;
}
