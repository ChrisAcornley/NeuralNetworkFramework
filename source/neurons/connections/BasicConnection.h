//
// Created by c516792 on 12/10/2018.
//

#ifndef CPPANN_BASICCONNECTION_H
#define CPPANN_BASICCONNECTION_H

class BasicNeuron;

template <typename W, typename T> class BasicConnection {
public:
    void init(W startWeighting, BasicNeuron* newSource, BasicNeuron* newTarget);
    virtual void pass(T input){};
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

    BasicNeuron *getSourceNode() const{
        return sourceNode;
    }

    BasicNeuron *getTargetNode() const {
        return targetNode;
    }
protected:
    W weighting = 0;
    BasicNeuron* sourceNode = nullptr;
    BasicNeuron* targetNode = nullptr;
};

#endif //CPPANN_BASICCONNECTION_H