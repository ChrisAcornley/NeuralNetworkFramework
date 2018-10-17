//
// Created by c516792 on 16/10/2018.
//

#ifndef CPPANN_OPERATORCONNECTION_H
#define CPPANN_OPERATORCONNECTION_H

#include "BasicConnection.h"

template<typename W> class OperatorConnection : public BasicConnection<W>{
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
    void operator()(const W input)
    {
        this->pass(input);
    }
};

#endif //CPPANN_OPERATORCONNECTION_H