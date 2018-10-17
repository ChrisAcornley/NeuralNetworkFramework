#include <iostream>

#include "neurons/connections/Connection.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Connection<double> op;
    op.init(0.4, 0, 0);
    op+=5.3;
    op(4.0);

    std::cout << op.getWeighting() << std::endl;

    return 0;
}