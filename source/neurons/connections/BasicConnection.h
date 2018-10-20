//
// Created by c516792 on 12/10/2018.
//

#ifndef CPPANN_BASICCONNECTION_H
#define CPPANN_BASICCONNECTION_H

#include "Signals.h"
#include "BasicNeuron.h"

namespace CPPANN {

    class BasicConnection {
    public:
        void init(double startWeighting, BasicNeuron *newSource, BasicNeuron *newTarget) {
            weighting = startWeighting;
            targetNode = newTarget;
            sourceNode = newSource;
        }

        virtual void pass(double input) = 0;

    public:
        void setWeighting(double weighting) {
            this->weighting = weighting;
        }

        void setSourceNode(BasicNeuron *sourceNode) {
            this->sourceNode = sourceNode;
        }

        void setTargetNode(BasicNeuron *targetNode) {
            this->targetNode = targetNode;
        }

        double getWeighting() const {
            return weighting;
        }

        BasicNeuron *getSourceNode() const {
            return sourceNode;
        }

        BasicNeuron *getTargetNode() const {
            return targetNode;
        }

        Signal3<double, double, double>& getOnPassSignal() {
            return onPassSignal;
        }

    protected:
        double weighting = 0;
        BasicNeuron *sourceNode = nullptr;
        BasicNeuron *targetNode = nullptr;
        Signal3<double, double, double> onPassSignal;
    };
}
#endif //CPPANN_BASICCONNECTION_H