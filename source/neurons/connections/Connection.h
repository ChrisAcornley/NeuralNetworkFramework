//
// Created by c516792 on 17/10/2018.
//

#ifndef CPPANN_CONNECTION_H
#define CPPANN_CONNECTION_H


#include "OperatorConnection.h"

namespace CPPANN {

    class Connection : public OperatorConnection {
    public:
        void pass(double input) override;
    };
}

#endif //CPPANN_CONNECTION_H
