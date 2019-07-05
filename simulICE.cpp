#include "simulICE.h"
/*
   double getTempICE(testICE &obj, double torqueTmp, double crankshaftSpeedTmp){
   double acc = torqueTmp / obj.momentInert;

   double heat = (torqueTmp * obj.HTorque) + (pow(crankshaftSpeedTmp, 2) * obj.HCrankshaft);
   double cooling = obj.Cooling * (obj.tempEnvir - obj.tempICE);
   return heat * cooling / acc;
   }
   */
double simulICE::accCalc(int torque, int momentTnert){
    if(torque == 0)
        return 1;
    return torque / momentTnert;
}

double simulICE::heat(int torque, double HTorque, int crankshaftSpeed, double HCrankshaft){
    return (torque * HTorque) + pow(crankshaftSpeed, 2) * HCrankshaft;
}
double simulICE::cooling(double cooling, double tempEnvir, double tempICE){
    return cooling * (tempEnvir - tempICE);
}
double simulICE::getTempICE(double heat, double acc, double cooling){
    return (heat - cooling) / sqrt(acc);
}

simulICE::simulICE(){
    this->speed = 0;
}

simulICE::~simulICE(){
}
