//
// Created by c516792 on 04/10/2018.
//

#ifndef CPPANN_BASICNEURON_H
#define CPPANN_BASICNEURON_H



#include "Signals/Signals.h"
#include "Core/Types/CPTypes.h"
#include <unordered_map>
#include <forward_list>

namespace CPPANN {

    template<typename _TYPE> class ConnectionT {

    };




    template<typename _TYPE> class BasicNeuronT {
    public:
        using INTERNAL_FUNCTION = std::function<_TYPE(const std::vector<_TYPE>& inputSignals)>;
        using CONNECTION_TYPE = std::pair<ConnectionT<_TYPE>*, BasicNeuronT<_TYPE>*>;
    protected:
        using PUSH_SIGNAL_MAP = std::unordered_map<unsigned, CONNECTION_TYPE>;
        using INPUT_SIGNAL_VECTOR = std::vector<_TYPE>;
    public:
        // Constructor
        BasicNeuronT() : id(0) { }

        // Initialiser function to manage setting up the ID for the neuron and for defining the internal operation
        void init(unsigned id, INTERNAL_FUNCTION& internalOperation) {
            this->id = id;
            this->internalOperation = internalOperation;
        }

        // Add connection, fail if ID already exists in the map
        void addConnection(CONNECTION_TYPE& newConnection, unsigned connectionID){
            auto it = forwardConnections.find(connectionID);
            if(it != forwardConnections.end()) {
                throw(MessageException(RTYPE::PRE_EXISTING_CONNECTION, "BasicNeuron::addConnection"));
            }
            forwardConnections.insert(std::make_pair(connectionID, newConnection));
        }

        // Remove connection, fail if ID does not exist in the map
        void removeConnection(unsigned connectionID) {
            auto it = forwardConnections.find(connectionID);
            if(it == forwardConnections.end()) {
                throw(MessageException(RTYPE::NO_EXISTING_CONNECTION, "BasicNeuron::removeConnection"));
            }
            forwardConnections.erase(connectionID);
        }

        // Apply input that has been recieved
        RTYPE recieve(_TYPE inputData) {
            try {
                inputContainer.push_back(inputData);
            } catch(const std::exception& exc) {
                return RTYPE::CANNOT_ADD_INPUT;
            }
        }

        // Update function that will pass data from the inputs through the internal operation and forward to the output
        // connections
        virtual RTYPE update() = 0;

    public:
        // Get ID
		unsigned getId() const {
            return id;
        }

        // Set ID
        void setId(unsigned id) {
            this->id = id;
        }

        // Get Internal Operation
        const INTERNAL_FUNCTION &getInternalOperation() const {
            return internalOperation;
        }

        // Set Internal Operation
        void setInternalOperation(const INTERNAL_FUNCTION &internalOperation) {
            this->internalOperation = internalOperation;
        }

    protected:
		unsigned id;
        INPUT_SIGNAL_VECTOR inputContainer;
        INTERNAL_FUNCTION internalOperation;
        PUSH_SIGNAL_MAP forwardConnections;
    };



    class Connection;

    typedef std::function<double(const std::vector<double>& allSignals)> InternalOp;

    class BasicNeuron {
    public:
        BasicNeuron();
        RTYPE receive(double inputSignal);
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