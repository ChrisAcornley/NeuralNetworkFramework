//
// Created by c516792 on 12/10/2018.
//

#include "BasicConnection.h"

template<typename W, typename T>
void BasicConnection<W, T>::init(W startWeighting, BasicNeuron *newSource, BasicNeuron *newTarget) {
    weighting = startWeighting;
    targetNode = newTarget;
    sourceNode = newSource;
}