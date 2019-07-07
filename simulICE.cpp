#include "simulICE.h"

double accCalc(int torque, int momentTnert){
    if(torque == 0)
        return 1;
    return torque / momentTnert;
}

double heat(int torque, double HTorque, int crankshaftSpeed, double HCrankshaft){
    return (torque * HTorque) + pow(crankshaftSpeed, 2) * HCrankshaft;
}

double cooling(double cooling, double tempEnvir, double tempICE){
    return cooling * (tempEnvir - tempICE);
}

double getTempICE(double heat, double acc, double cooling){
    return (heat - cooling) / sqrt(acc);
}

double getTemp(testICE &tmp, int i){
    double acc = accCalc(tmp.torque[i], tmp.momentInert);
    double result = (heat(tmp.torque[i], tmp.HTorque, tmp.crankshaftSpeed[i], tmp.HCrankshaft) -
            cooling(tmp.Cooling, tmp.tempEnvir, tmp.tempICE)) / sqrt(acc);
    return result;
}
