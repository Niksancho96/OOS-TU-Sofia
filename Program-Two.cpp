#include <iostream>
#include <time.h>
#include "Core.h"

int main(int argc, const char * argv[]) {
    
    // Variable declaration
    Core coreVar(10, false, false);
    int dynamicArrayTwo[10];
    std::ifstream data;
    int index = 0;
    
    // Start reading file and getting values
    data.open("data.txt", std::ios::out);
    
    if (data.is_open()) {
        while (!data.eof()) {
            data >> dynamicArrayTwo[index];
            index += 1;
        }
        std::cout << "Loaded the stack!" << std::endl;
    } else {
        std::cout << "Error in finding file!" << std::endl;
    }
    
    data.close();
    // End reading values, and closes file
    
    // House keeping, removing all zeros from stack
    for (int i = 0; i < 10; i ++) {
        coreVar.pushElement(dynamicArrayTwo[i]);
    }
    
    coreVar.sortStackAscend();
    
    for (int i = 0; i < 10; i ++) {
        coreVar.popElement();
    }
    // End of house keeping
    
    // Start executing last three of the functions int the Library
    std::cout << std::endl;
    coreVar.sortStackDecend();
    coreVar.printStackValues();
    
    std::cout<< std::endl;
    coreVar.sortStackAscend();
    coreVar.printStackValues();
    
    std::cout << std::endl;
    srand(time(0));
    coreVar.pushElement(std::rand() % 101);
    coreVar.printStackValues();
    std::cout << "Pushed One element to stack!" << std::endl;
    
    std::cout << std::endl;
    coreVar.popElement();
    coreVar.printStackValues();
    std::cout << "Popped One element to stack!" << std::endl;
    // End execution
    
    return 0;
}
