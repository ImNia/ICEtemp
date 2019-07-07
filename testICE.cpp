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

    double tempCurr = tmp.getTempICE(); 

    std::cout << tmp.torqueSize() << std::endl;
    while(tmp.getTempICE() <= tmp.getOverheadTemp()){
        for(int i = 0; i < tmp.torqueSize(); i++){
            tempCurr = getTemp(tmp, i);
            tmp.setTempICE(tempCurr);
            tmp.time++;
        }
    }
    /*    while(tmp.tempICE <= tmp.overheatTemp){
          for(int i = 0; i < (int)tmp.torque.size(); i++){
          acc = accCalc(tmp.torque[i], tmp.momentInert);
          heatT = heat(tmp.torque[i], tmp.HTorque, tmp.crankshaftSpeed[i], tmp.HCrankshaft);
          coolingT = cooling(tmp.Cooling, tmp.tempEnvir, tmp.tempICE);
          tempCurr = (double)getTempICE(heatT, acc, coolingT);
          tmp.tempICE += tempCurr;
          tmp.time++;
          }
    //            std::cout << coolingT << ' ' << tempCurr << std::endl;
    //            std::cout << tmp.tempICE << ' ' << tmp.time << std::endl;
    }*/
    double time = tmp.time;

    return time;
}

double testICE::getTempICE(){
    return this->tempICE;
}
void testICE::setTempICE(double temp){
    this->tempICE += temp;
    std::cout << this->tempICE << std::endl;
}
double testICE::getOverheadTemp(){
    return this->overheatTemp;
}
int testICE::torqueSize(){
    return this->torque.size();
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
