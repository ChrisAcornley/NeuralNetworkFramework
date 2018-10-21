#include <iostream>

#include "Connection.h"

using namespace CPPANN;

struct test
{
    void Connect(Signal3<double, double, double>& signal)
    {
        signal.Connect(MAKE_DELEGATE(&test::testFunc, this));
    }

    void testFunc(double w, double in, double out)
    {
        std::cout << "Weighting is: " << w << "\tand the input is: " << in << ".\tThe output of the connection is: " << out << std::endl;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Connection op;
    op.init(0.4, 0);
    op+=5.3;

    test opSignal;
    opSignal.Connect(op.getOnPassSignal());

    op(4.0);

    return 0;
}