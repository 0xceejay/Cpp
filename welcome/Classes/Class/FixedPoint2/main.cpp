#include <cassert>
#include <iostream>
#include <cmath>

class FixedPoint2 {
private:
    int16_t m_base {};
    int8_t m_decimal {};
public:
    FixedPoint2(int16_t base, int8_t decimal) :
        m_base { base },
        m_decimal { decimal } {
            // If either (or both) of the non-fractional and fractional part of the number are negative
            if (m_base < 0 || m_decimal < 0)
            {
                // Make sure base is negative
                if (m_base > 0)
                    m_base = -m_base;
                // Make sure decimal is negative
                if (m_decimal > 0)
                    m_decimal = -m_decimal;
            }

            m_base += (m_decimal / 100);
            m_decimal %= 100;
        }

    FixedPoint2(double number) :
        FixedPoint2(
            static_cast<int16_t>(std::trunc(number)),
            static_cast<int8_t>(std::round(number * 100) - std::trunc(number) * 100)
        ) {}

    explicit operator double() const {
        return m_base + (static_cast<double>(m_decimal) /  100);
    }

    friend bool operator==(const FixedPoint2& num1, const FixedPoint2& num2) {
        return num1.m_base == num2.m_base && num1.m_decimal == num2.m_decimal;
    }

    FixedPoint2 operator-() const 	{
		// Cast to double, make the double negative, then convert back to FixedPoint2
		return FixedPoint2{ -static_cast<double>(*this) };
	}

};

std::ostream& operator<<(std::ostream& out, FixedPoint2& number) {
    out << static_cast<double>(number);

    return out;
}

std::istream& operator>>(std::istream& in, FixedPoint2& num) {
	double d{};
	in >> d;
	num = FixedPoint2{ d };

	return in;
}

FixedPoint2 operator+(const FixedPoint2& num1, const FixedPoint2& num2) {
	return FixedPoint2{ static_cast<double>(num1) + static_cast<double>(num2) };
}

int main() {
	assert(FixedPoint2{ 0.75 } == FixedPoint2{ 0.75 });    // Test equality true
	assert(!(FixedPoint2{ 0.75 } == FixedPoint2{ 0.76 })); // Test equality false

	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 1.98 });    // both positive, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 2.25 });    // both positive, with decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -1.98 }); // both negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -2.25 }); // both negative, with decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.23 } == FixedPoint2{ -0.48 });  // second negative, no decimal overflow
	assert(FixedPoint2{ 0.75 } + FixedPoint2{ -1.50 } == FixedPoint2{ -0.75 });  // second negative, possible decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.23 } == FixedPoint2{ 0.48 });   // first negative, no decimal overflow
	assert(FixedPoint2{ -0.75 } + FixedPoint2{ 1.50 } == FixedPoint2{ 0.75 });   // first negative, possible decimal overflow

	FixedPoint2 a{ -0.48 };
	assert(static_cast<double>(a) == -0.48);
	assert(static_cast<double>(-a) == 0.48);

	std::cout << "Enter a number: "; // enter 5.678
	std::cin >> a;
	std::cout << "You entered: " << a << '\n';
	assert(static_cast<double>(a) == 5.68);

	return 0;
}
