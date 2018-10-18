//
// Created by c516792 on 12/10/2018.
//

#ifndef CPPANN_BASICCONNECTION_H
#define CPPANN_BASICCONNECTION_H

namespace CPPANN {
    class BasicNeuron;

    template<typename W>
    class BasicConnection {
    public:
        void init(W startWeighting, BasicNeuron *newSource, BasicNeuron *newTarget) {
            weighting = startWeighting;
            targetNode = newTarget;
            sourceNode = newSource;
        }

        virtual void pass(W input) = 0;

    public:
        void setWeighting(W weighting) {
            this->weighting = weighting;
        }

        void setSourceNode(BasicNeuron *sourceNode) {
            this->sourceNode = sourceNode;
        }

        void setTargetNode(BasicNeuron *targetNode) {
            this->targetNode = targetNode;
        }

        W getWeighting() const {
            return weighting;
        }

        BasicNeuron *getSourceNode() const {
            return sourceNode;
        }

        BasicNeuron *getTargetNode() const {
            return targetNode;
        }

    protected:
        W weighting = 0;
        BasicNeuron *sourceNode = nullptr;
        BasicNeuron *targetNode = nullptr;
    };
}
#endif //CPPANN_BASICCONNECTION_H