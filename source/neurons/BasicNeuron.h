//
// Created by c516792 on 04/10/2018.
//

#ifndef CPPANN_BASICNEURON_H
#define CPPANN_BASICNEURON_H

#include "Signals.h"
#include <unordered_map>

namespace CPPANN {

    class Connection;

    typedef std::function<double(const std::vector<double>& allSignals)> InternalOp;

    class BasicNeuron {
    public:
        BasicNeuron();
        void receive(double inputSignal);
        void update();
        void addConnection(Connection* newConnection, const std::string& connectionName);
        void removeConnection(const std::string& connectionName);
    public:
        const InternalOp &getInternalOpertaion() const {
            return this->internalOpertaion;
        }

        void setInternalOpertaion(const InternalOp &internalOpertaion) {
            this->internalOpertaion = internalOpertaion;
        }
    private:
        std::vector<double> inputSignals;
        InternalOp internalOpertaion;
        std::unordered_map<std::string, Connection*> forwardConnections;
    };
}

#endif //CPPANN_BASICNEURON_H