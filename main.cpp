#include "init.h"
#include "simulICE.h"
#include "testICE.h"

int main(){
    double tmp;
    tmp = testStend(10, 
            {20, 75, 100, 105, 75, 0},
            {0, 75, 150, 200, 250, 300},
            110, 0.01, 0.0001, 0.1, 22);
    std::cout << tmp << " sec"<< std::endl;

    return 0;
}
