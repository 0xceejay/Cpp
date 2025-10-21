#include <iostream>
#include <vector>
#include <cassert>

namespace Animals {
    enum Type {
        chicken,
        dog,
        cat,
        elephant,
        duck,
        snake,
        maxNumberOfAnimals,
    };

    const std::vector numberOfLegs{2, 4, 4, 4, 2, 0};
}



int main() {

    assert(std::size(Animals::numberOfLegs) == Animals::maxNumberOfAnimals);

    std::cout << "An Elephant has " << Animals::numberOfLegs[Animals::elephant] << " legs.";

    return 0;
}
