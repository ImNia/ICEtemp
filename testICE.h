#ifndef TESTICE_H
#define TESTICE_H

#include "init.h"
#include "simulICE.h"

class testICE {
    private:
        int momentInert;
        std::vector<int> torque;
        std::vector<int> crankshaftSpeed;
        int overheatTemp;
        double HTorque;
        double HCrankshaft;
        double Cooling;
        double tempICE;

    public:
        int time;

        double tempEnvir;
        testICE(int momentInertTmp,
                std::vector<int> torqueTmp,
                std::vector<int> crankshaftSpeedTmp,
                int overheatTempTmp,
                double HTorqueTmp,
                double HCrankshaftTmp,
                double CoolingTmp, double tempEnvirTmp);
        ~testICE();

        double getTempICE();
        void setTempICE(double temp);
        double getOverheadTemp();
        int torqueSize();
        friend double getTemp(testICE &, int i);

};

double testStend(int momentInertTmp,
        std::vector<int> torqueTmp,
        std::vector<int> crankshaftSpeedTmp,
        int overheatTempTmp,
        double HTorqueTmp,
        double HCrankshaftTmp,
        double CoolingTmp, 
        double tempEnvirTmp);


#endif
