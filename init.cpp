#include "init.h"

void inOutPut::getTemp(){
    std::cout << "Wait enter environment temperature" << std::endl;
    std::cin >> this->envirTemp;
}

void inOutPut::printMaxTime(int maxTime){
    std::cout << "Past time: " << maxTime << std::endl;
}

