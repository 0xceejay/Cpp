#include <iostream>

// Template for Struct Triad
template <typename T>
struct Triad {
    T member1 {};
    T member2 {};
    T member3 {};
};

// Function to print out Triad
template <typename T>
void print(const Triad<T>& triad) {
    std::cout << "[" << triad.member1 << ", " << triad.member2 <<
        ", " << triad.member3 << "]";
}


int main() {
    Triad t1{ 1, 2, 3 };
    print(t1);

    Triad t2{ 1.2, 3.4, 5.6 };
    print(t2);

    return 0;
}
