//
// Created by c516792 on 17/10/2018.
//

#ifndef CPPANN_CONNECTION_H
#define CPPANN_CONNECTION_H


#include "OperatorConnection.h"

namespace CPPANN {

    template<typename ConType>
    class Connection : public OperatorConnection<ConType> {
    public:
        void pass(ConType input) override {
            // Apparently header file shite is best here
            this->passSignal(this->weighting, input);
        }
    };
}

#endif //CPPANN_CONNECTION_H
