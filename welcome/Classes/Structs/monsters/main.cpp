#include <iostream>
#include <string>
#include <string_view>

// Monster struct
struct Monster {
    enum Type {
        orge,
        dragon,
        orc,
        giant,
        spider,
        slime,
    };
    Type type{}; // Type in string
    std::string name{};
    int health{};
};

// Get Monster name as string since enum returns integral values
constexpr std::string_view getMonsterType(Monster::Type type) {
    switch (type) {
    case Monster::orge:     return "Ogre";
    case Monster::dragon:   return "Dragon";
    case Monster::orc:      return "Orc";
    case Monster::giant:    return "Giant";
    case Monster::spider:   return "Spider";
    case Monster::slime:    return "Slime";
    }

    return "Unknown";
}

// Print Monster's statistics
void printMonster(const Monster& monster) {
    std::cout << "This " << getMonsterType(monster.type) << " is named " <<
        monster.name << " and has " << monster.health << " health.\n";
}

int main() {
    Monster ogre{ Monster::orge, "Torg", 145 };
    Monster slime{ Monster::slime, "Blurp", 23 };

    printMonster(ogre);
    printMonster(slime);

    return 0;
}
