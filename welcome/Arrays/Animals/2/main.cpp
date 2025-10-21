#include <iostream>
#include <array>
#include <string_view>

namespace Animal {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxTypes
    };

    struct Data {
        std::string_view name{};
        int numberOfLegs{};
        std::string_view sound{};
    };

    constexpr std::array animalTypes { chicken, dog, cat, elephant, duck, snake };
    static_assert(std::size(animalTypes) == maxTypes);

    constexpr std::array<Data, maxTypes> animalData {{
        { "chicken", 2, "cluck" },
        { "dog", 4, "woof" },
        { "cat", 4, "meow" },
        { "elephant", 4, "pawoo" },
        { "duck", 2, "quack" },
        { "snake", 0, "hisses" }
    }};
    static_assert(std::size(animalData) == maxTypes);

}

// Teach operator>> how to input an animal by name
// Passed animal by non-const reference so we can have the function modify its value
std::istream& operator>> (std::istream& in, Animal::Type& animal) {
    std::string input {};
    std::getline(in >> std::ws, input);

    for (std::size_t index=0; index < Animal::maxTypes; ++index) {
        if (input == Animal::animalData[index].name) {
            // If matching name found, we can get the enumerator value based on its index
            animal = static_cast<Animal::Type>(index);
            return in;
        }
    }

    // We didn't find a match, so we will set input stream to fail state
    in.setstate(std::ios_base::failbit);
    return in;
}



int main() {
    std::cout << "Enter an animal: ";
    Animal::Type type{};
    std::cin >> type;

    if (!std::cin) {
        std::cout << "That animal couldn't be found.\n";
        // set to max, instead of 0
        type = Animal::maxTypes;
    } else {
        std::cout << "A " << Animal::animalData[type].name << " has " << Animal::animalData[type].numberOfLegs
            << " legs and says " << Animal::animalData[type].sound << ".\n";
    }

    std::cout << "Here is the data for the rest of the animals:\n";
    for (auto animal : Animal::animalTypes) {
        if (animal == type)
            continue;
        std::cout << "A " << Animal::animalData[animal].name << " has " << Animal::animalData[animal].numberOfLegs
            << " legs and says " << Animal::animalData[animal].sound << ".\n";
    }

    return 0;
}
