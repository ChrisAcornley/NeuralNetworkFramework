//
// Created by c516792 on 16/10/2018.
//

#ifndef CPPANN_OPERATORCONNECTION_H
#define CPPANN_OPERATORCONNECTION_H

#include "BasicConnection.h"

template<typename W, typename T> class OperatorConnection : public BasicConnection<W,T>{
public:
    W operator+(const W a)
    {
        return (this->weighting + a);
    }
    W operator-(const W a)
    {
        return (this->weighting - a);
    }
    W operator*(const W a)
    {
        return (this->weighting * a);
    }
    W operator/(const W a)
    {
        return (this->weighting / a);
    }
    W operator+=(const W a)
    {
        return (this->weighting += a);
    }
    W operator-=(const W a)
    {
        return (this->weighting -= a);
    }
    W operator*=(const W a)
    {
        return (this->weighting *= a);
    }
    W operator/=(const W a)
    {
        return (this->weighting /= a);
    }
    W operator=(const W a)
    {
        return (this->weighting = a);
    }
    void operator()(const T input)
    {
        pass(input);
    }
};

#endif //CPPANN_OPERATORCONNECTION_H