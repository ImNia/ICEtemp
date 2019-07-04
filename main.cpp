#include "init.h"
#include "testICE.h"

int main(){
    testICE *tmp = new testICE(10, 
            {20, 75, 100, 105, 75, 0},
            {0, 75, 150, 200, 250, 300},
            110, 0.01, 0.0001, 0.1);
    std::cout << tmp->momentInert << std::endl;

    return 0;
}
