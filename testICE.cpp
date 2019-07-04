#include "testICE.h"

testICE::testICE(int momentInertTmp,
                std::vector<int> torqueTmp,
                std::vector<int> crankshaftSpeedTmp,
                int overheatTempTmp,
                double HTorqueTmp,
                double HCrankshaftTmp,
                double CollingTmp){
    this->momentInert = momentInertTmp;

    this->torque = torqueTmp;
    this->crankshaftSpeed = crankshaftSpeedTmp;

    this->overheatTemp = overheatTempTmp;
    this->HTorque = HTorqueTmp;
    this->HCrankshaft = HCrankshaftTmp;
    this->Colling = CollingTmp;
}
