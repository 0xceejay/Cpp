#include <iostream>
#include <string>
#include <string_view>
#include "Random.h"

class Monster {
public:
    enum Type {
        dragon,
        goblin,
        orge,
        orc,
        skeleton,
        troll,
        vampire,
        zombie,
        maxMonsterTypes,
    };

private:
    Type m_type{};
    std::string m_name{ "None" };
    std::string m_roar{ "None" };
    int m_hitPoints{};

public:
    Monster(const Type& type, const std::string_view name, const std::string_view roar, const int hitPoints) :
        m_type { type },
        m_name { name },
        m_roar { roar },
        m_hitPoints { hitPoints } {}

    constexpr std::string_view getTypeString() const {
        switch (m_type)
        {
        case dragon:        return "dragon";
        case goblin:        return "goblin";
        case orge:          return "orge";
        case orc:           return "orc";
        case skeleton:      return "skeleton";
        case troll:         return "troll";
        case vampire:       return "vampire";
        case zombie:        return "zombie";
        default:            return "None";
        }
     }

    void print() const {
        if (m_hitPoints > 0) {
            std::cout << m_name << " the " << getTypeString() << " has " << m_hitPoints << " hit points and says " << m_roar << ".\n";
        } else {
            std::cout << m_name << " the " << getTypeString() << " is dead.\n";
        }
    }
};

namespace MonsterGenerator {
    std::string_view getName(int num) {
        switch (num)
        {
        case 0:     return "Bones";
        case 1:     return "Gnasher";
        case 2:     return "Fang";
        case 3:     return "Stumpy";
        case 4:     return "Spike";
        case 5:     return "Gloom";
        default:    return "None";
        }
    }

    std::string_view getRoar(int num) {
        switch (num)
        {
        case 0:     return "*rattle*";
        case 1:     return "*snarl*";
        case 2:     return "*growl*";
        case 3:     return "*hiss*";
        case 4:     return "*grunt*";
        case 5:     return "*screech*";
        default:    return "None";
        }
    }

    Monster generate() {
        return Monster{ static_cast<Monster::Type>(Random::get(0, Monster::maxMonsterTypes - 1)),
            getName(Random::get(0,5)),
            getRoar(Random::get(0,5)),
            Random::get(0,100) };
    }
}

int main()
{
	Monster m{ MonsterGenerator::generate() };
	m.print();

	return 0;
}
