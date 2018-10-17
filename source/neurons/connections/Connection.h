//
// Created by c516792 on 17/10/2018.
//

#ifndef CPPANN_CONNECTION_H
#define CPPANN_CONNECTION_H


#include "OperatorConnection.h"

template<typename W>
class Connection : public OperatorConnection<W>{
public:
    void pass(W input) override
    {
        // Apparently header file shite is best here
    }
};


#endif //CPPANN_CONNECTION_H
