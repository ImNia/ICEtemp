#ifndef SIMULICE_H
#define SIMULICE_H

#include "init.h"
#include "testICE.h"

#include <cmath>

double accCalc(int torque, int momentTnert);
double heat(int torque, double HTorque, int crankshaftSpeed, double HCrankshaft);
double cooling(double cooling, double tempEnvir, double tempICE);
//double getTempICE(double heat, double acc, double cooling);
#endif
