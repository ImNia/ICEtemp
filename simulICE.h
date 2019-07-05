#ifndef SIMULICE_H
#define SIMULICE_H

#include "init.h"
#include "testICE.h"

#include <cmath>

class simulICE{
    private:
        int speed;
    public:
        simulICE();
        ~simulICE();
        double accCalc(int torque, int momentTnert);
        double heat(int torque, double HTorque, int crankshaftSpeed, double HCrankshaft);
        double cooling(double cooling, double tempEnvir, double tempICE);
        double getTempICE(double heat, double acc, double cooling);
};

//double getTempICE(auto &obj, double torqueTmp, double crankshaftSpeedTmp);

#endif
