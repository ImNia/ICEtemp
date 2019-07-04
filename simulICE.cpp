#include "simulICE.h"

void simulICE::calcAcc(){
    double tmp = 0;
    for(int i = 0; i < (int)crankshaftSpeed.size(); i++){
        tmp = crankshaftSpeed[i] / momentInert;
        acc.push_back(tmp);
    }
}

double simulICE::heatICE(int torqueTmp, double HTorqueTmp, int crankshaftSpeedTmp, double HCranckshaftTmp){
    return (torqueTmp * HTorqueTmp) + (pow(crankshaftSpeedTmp, 2) * HCranckshaftTmp);
}

double simulICE::coolingICE(double coolingICETmp, double tempEnvirTmp, double tempICETmp){
    return coolingICETmp * (tempEnvirTmp - tempICETmp);
}

double simulICE::getTempICE(std::vector<double> torqueTmp, double HTorqueTmp, std::vector<double> crankshaftSpeedTmp, double HCranckshaftTmp, double coolingICETmp, double tempEnvirTmp, double tempICETmp){
    double tmp;
    for(int i = 0; i < (int)torqueTmp.size(); i++){
        double heat = heatICE(torqueTmp[i], HTorqueTmp, crankshaftSpeedTmp[i], HCranckshaftTmp);
        double cooling = coolingICE(coolingICETmp, tempEnvirTmp, tempICETmp);
        tmp = heat * cooling / acc[i];
    }
    return sqrt(tmp);
}

