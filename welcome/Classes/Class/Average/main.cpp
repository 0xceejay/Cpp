#include <iostream>
#include <vector>

class Average {
private:
    int32_t m_sum {};
    int m_count {};
public:
    Average& operator+=(const int i);
    friend std::ostream& operator<<(std::ostream& out, const Average& ave);
};

Average& Average::operator+=(const int i) {
    m_sum += i;
    m_count += 1;
    return *this;
}

std::ostream& operator<<(std::ostream& out, const Average& ave) {
    if (ave.m_count == 0) {
        out << 0;
        return out;
    }
    out << static_cast<double>(ave.m_sum) / static_cast<double>(ave.m_count);
    return out;
}

int main() {
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
