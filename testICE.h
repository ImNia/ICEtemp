#ifndef TESTICE_H
#define TESTICE_H

#include "init.h"

class testICE{
    public:
        int momentInert;
        std::vector<int> torque;
        std::vector<int> crankshaftSpeed;
        int overheatTemp;
        double HTorque;
        double HCrankshaft;
        double Colling;

        testICE(int momentInertTmp,
                std::vector<int> torqueTmp,
                std::vector<int> crankshaftSpeedTmp,
                int overheatTempTmp,
                double HTorqueTmp,
                double HCrankshaftTmp,
                double CollingTmp);
        ~testICE();
};

#endif
