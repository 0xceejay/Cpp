#include <iostream>

double getTowerHeight() {
    double height{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> height;
    return height;
}

double calculateBallHeight(double towerHeight, int seconds) {
    double newHeight {towerHeight - (9.81 * seconds * seconds) / 2.0};
    if (newHeight > 0) {
        std::cout << "At " << seconds << " seconds, the ball is at height: " << newHeight << " meters\n";
    } else {
        std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
    }
    return 0;
}

int main() {
    double towerHeight {getTowerHeight()};

    calculateBallHeight(towerHeight, 0);
    calculateBallHeight(towerHeight, 1);
    calculateBallHeight(towerHeight, 2);
    calculateBallHeight(towerHeight, 3);
    calculateBallHeight(towerHeight, 4);
    calculateBallHeight(towerHeight, 5);

    return 0;
}
