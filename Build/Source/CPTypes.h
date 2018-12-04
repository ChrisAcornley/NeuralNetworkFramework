//
// Created by c516792 on 29/10/2018.
//

#ifndef CPPANN_ERRORTYPES_H
#define CPPANN_ERRORTYPES_H

#include <exception>
#include <string>

namespace CPPANN {
    enum class RTYPE : unsigned short {
        OK = 0,
        UNKNOWN,
        NO_EXISTING_CONNECTION,
        PRE_EXISTING_CONNECTION,
        CANNOT_ADD_INPUT
    };

    std::string[5] errorMessages {"Ok - No Problem Encountered",
                                  "Unknown Error",
                                  "No corresponding connection exists",
                                  "Pre existing connection of the same type exists",
                                  "Cannot add new input to neuron"};

    typedef unsigned NID_TYPE;
    typedef unsigned CID_TYPE;

    struct MessageException : public std::exception {
        RTYPE errorType;
        std::string extra;
        const std::string& getMsg() const {
            return errorMessages[(int)errorType] + " " + extra;
        }

        MessageException(RTYPE errorType, std::string extraMsg = "") {
            this->errorType = errorType;
            extra = extraMsg;
        }
    };
}

#endif //CPPANN_ERRORTYPES_H
