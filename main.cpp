#include "init.h"
#include "simulICE.h"
#include "testICE.h"

int main(){
    double tempEnvir = 0;
    std::cout << "Enter Environ temperature: ";
    std::cin >> tempEnvir;
    double tmp;
    tmp = testStend(10, 
            {20, 75, 100, 105, 75, 0},
            {0, 75, 150, 200, 250, 300},
            110, 0.01, 0.0001, 0.1, tempEnvir);
    std::cout << tmp << " sec"<< std::endl;

    return 0;
}
