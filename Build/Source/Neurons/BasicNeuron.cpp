//
// Created by c516792 on 04/10/2018.
//

#include "BasicNeuron.h"

namespace CPPANN {

    BasicNeuron::BasicNeuron() {
        // Do nothing for now
    }

    RTYPE BasicNeuron::receive(double inputSignal) {
        // Receive input from connection, weighting is now added
        return RTYPE::OK;
    }

    void BasicNeuron::update() {

    }

    void BasicNeuron::addConnection(Connection *newConnection, const std::string &connectionName) {

    }

    void BasicNeuron::removeConnection(const std::string &connectionName) {

    }
}