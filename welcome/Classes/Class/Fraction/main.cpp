#include <iostream>
#include <stdexcept>
#include <exception>

class Fraction {
private:
    int m_numerator {};
    int m_denominator {};

public:
    Fraction(int num, int den) :
        m_numerator { num },
        m_denominator { den }
        {
            if (den == 0)
                throw std::runtime_error("Invalid denominator");
        }

    friend std::ostream& operator<<(std::ostream& out, Fraction& frac);
};

std::ostream& operator<<(std::ostream& out, Fraction& frac) {
    out << frac.m_numerator << '/' << frac.m_denominator;

    return out;
}

int main() {
    std::cout << "Enter the numerator: ";
    int num {};
    std::cin >> num;

    std::cout << "Enter the denominator: ";
    int den {};
    std::cin >> den;

    try {
        Fraction fraction { num, den };
        std::cout << "Your fraction is: " << fraction << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
