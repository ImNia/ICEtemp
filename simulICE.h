#ifndef SIMULICE_H
#define SIMULICE_H

#include "init.h"
#include "testICE.h"

#include <cmath>

class simulICE : public testICE{
    public:
        std::vector<double> acc;
        void calcAcc();
        double heatICE(int torqueTmp, double HTorqueTmp, int crankshaftSpeedTmp, double HCranckshaftTmp);
        double coolingICE(double coolingICETmp, double tempEnvirTmp, double tempICETmp);
        double getTempICE(std::vector<double> torqueTmp, double HTorqueTmp, std::vector<double> crankshaftSpeedTmp, double HCranckshaftTmp, double coolingICETmp, double tempEnvirTmp, double tempICETmp);
};

#endif
