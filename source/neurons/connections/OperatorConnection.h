//
// Created by c516792 on 16/10/2018.
//

#ifndef CPPANN_OPERATORCONNECTION_H
#define CPPANN_OPERATORCONNECTION_H

#include "BasicConnection.h"

namespace CPPANN {

    class OperatorConnection : public BasicConnection {
    public:
        double operator+(const double a) {
            return (this->weighting + a);
        }

        double operator-(const double a) {
            return (this->weighting - a);
        }

        double operator*(const double a) {
            return (this->weighting * a);
        }

        double operator/(const double a) {
            return (this->weighting / a);
        }

        double operator+=(const double a) {
            return (this->weighting += a);
        }

        double operator-=(const double a) {
            return (this->weighting -= a);
        }

        double operator*=(const double a) {
            return (this->weighting *= a);
        }

        double operator/=(const double a) {
            return (this->weighting /= a);
        }

        double operator=(const double a) {
            return (this->weighting = a);
        }

        void operator()(const double input) {
            this->pass(input);
        }
    };
}

#endif //CPPANN_OPERATORCONNECTION_H