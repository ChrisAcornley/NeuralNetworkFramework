//
// Created by c516792 on 12/10/2018.
//

#ifndef CPPANN_BASICCONNECTION_H
#define CPPANN_BASICCONNECTION_H

#include "Signals/Signals.h"

namespace CPPANN {

    class BasicNeuron;

    class BasicConnection {
    public:
        void init(double startWeighting, BasicNeuron *newTarget) {
            weighting = startWeighting;
            targetNode = newTarget;
        }

        virtual void pass(double input) = 0;

    public:
        void setWeighting(double weighting) {
            this->weighting = weighting;
        }

        void setTargetNode(BasicNeuron *targetNode) {
            this->targetNode = targetNode;
        }

        double getWeighting() const {
            return weighting;
        }

        BasicNeuron *getTargetNode() const {
            return targetNode;
        }

        Signal3<double, double, double>& getOnPassSignal() {
            return onPassSignal;
        }

    protected:
        double weighting = 0;
        BasicNeuron *targetNode = nullptr;
        Signal3<double, double, double> onPassSignal;
    };
}
#endif //CPPANN_BASICCONNECTION_H