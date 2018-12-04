//
// Created by c516792 on 21/10/2018.
//

#include "Connection.h"
#include "Neurons/BasicNeuron.h"

namespace CPPANN {
    void Connection::pass(double input) {
        // Create and calculate output
        double output = this->weighting * input;

        // Fire the signal
        this->onPassSignal(this->weighting, input, output);

        // Pass the output to the target
        this->targetNode->receive(output);
    }
}
