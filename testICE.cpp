#include "testICE.h"

double testStend(int momentInertTmp,
        std::vector<int> torqueTmp,
        std::vector<int> crankshaftSpeedTmp,
        int overheatTempTmp,
        double HTorqueTmp,
        double HCrankshaftTmp,
        double CoolingTmp, double tempEnvirTmp){

    testICE tmp(momentInertTmp, torqueTmp, crankshaftSpeedTmp,
            overheatTempTmp, HTorqueTmp, HCrankshaftTmp, CoolingTmp, tempEnvirTmp);
    simulICE startICE;

    double acc, heatT, coolingT;
    double tempCurr = tmp.tempICE;
    while(tmp.tempICE <= tmp.overheatTemp){
        for(int i = 0; i < (int)tmp.torque.size(); i++){
            acc = startICE.accCalc(tmp.torque[i], tmp.momentInert);
            heatT = startICE.heat(tmp.torque[i], tmp.HTorque, tmp.crankshaftSpeed[i], tmp.HCrankshaft);
            coolingT = startICE.cooling(tmp.Cooling, tmp.tempEnvir, tmp.tempICE);
            tempCurr = (double)startICE.getTempICE(heatT, acc, coolingT);
            tmp.tempICE += tempCurr * 0.01;
            tmp.time++;
        }
//            std::cout << coolingT << ' ' << tempCurr << std::endl;
//            std::cout << tmp.tempICE << ' ' << tmp.time << std::endl;
    }
    double time = tmp.time;

    return time;
}

testICE::testICE(int momentInertTmp,
        std::vector<int> torqueTmp,
        std::vector<int> crankshaftSpeedTmp,
        int overheatTempTmp,
        double HTorqueTmp,
        double HCrankshaftTmp,
        double CoolingTmp, double tempEnvirTmp){
    this->momentInert = momentInertTmp;

    this->torque = torqueTmp;
    this->crankshaftSpeed = crankshaftSpeedTmp;

    this->overheatTemp = overheatTempTmp;
    this->HTorque = HTorqueTmp;
    this->HCrankshaft = HCrankshaftTmp;
    this->Cooling = CoolingTmp;
    this->tempEnvir = tempEnvirTmp;
    this->tempICE = tempEnvir;
    this->time = 0;
}

testICE::~testICE(){
}
