#include <iostream>

#include "neurons/connections/OperatorConnection.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    OperatorConnection<double, double> op;

    op+=5;

    std::cout << op.getWeighting() << std::endl;

    return 0;
}