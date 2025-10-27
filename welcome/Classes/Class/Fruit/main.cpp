#include <iostream>

class Fruit {
private:
    std::string m_name {};
    std::string m_color {};

public:
    Fruit(std::string_view name, std::string_view color) :
        m_name { name },
        m_color { color } {}

    const std::string& getName() const { return m_name; }
    const std::string& getColor() const { return m_color; }
};

// Apple inherits the class fruit
class Apple : public Fruit {
private:
    double m_fibre {};

public:
    Apple(std::string_view name, std::string_view color, double fibre) :
        Fruit { name, color },
        m_fibre { fibre } {}

    double getFibre() const { return m_fibre; }
};

// Banana inherits the class fruit
class Banana : public Fruit {
public:
    Banana(std::string_view name, std::string_view color) :
        Fruit { name, color } {}

    friend std::ostream& operator<<(std::ostream& out, const Banana& banana);
};

std::ostream& operator<<(std::ostream& out, const Apple& apple) {
    out << "Apple(" << apple.getName() << ", " << apple.getColor() << ", " << apple.getFibre() << ")\n";

    return out;
}

std::ostream& operator<<(std::ostream& out, const Banana& banana) {
    out << "Banana(" << banana.getName() << ", " << banana.getColor() <<  ")\n";

    return out;
}

int main() {
	const Apple a{ "Red delicious", "red", 4.2 };
	std::cout << a << '\n';

	const Banana b{ "Cavendish", "yellow" };
	std::cout << b << '\n';

	return 0;
}
