//
// Created by c516792 on 12/10/2018.
//

#ifndef CPPANN_BASICCONNECTION_H
#define CPPANN_BASICCONNECTION_H

class BasicConnection {
public:
    BasicConnection();
    //double getWeighting();
   // void setWeighting(const double newWeighting);
    double operator+(const double a)
    {
        return (weighting += a);
    }
    //double operator-(const double a);
private:
    double weighting;
};


#endif //CPPANN_BASICCONNECTION_H
