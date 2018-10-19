#include <iostream>

#include "Connection.h"

using namespace CPPANN;

struct test
{
    void Connect(Signal2<double, double>& signal)
    {
        signal.Connect(MAKE_DELEGATE(&test::testFunc, this));
    }

    void testFunc(double w, double in)
    {
        std::cout << "Weighting is: " << w << "\tand the input is: " << in << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Connection<double> op;
    op.init(0.4, 0, 0);
    op+=5.3;

    test opSignal;
    opSignal.Connect(op.getSignal());

    op(4.0);

    return 0;
}