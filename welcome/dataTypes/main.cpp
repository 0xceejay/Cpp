#include "io.h"

int main() {
    double x {enterNumber()};
    double y {enterNumber()};
    char op {getOperator()};
    getResult(x, y, op);
    return 0;
}
