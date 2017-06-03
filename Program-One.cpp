#include <iostream>
#include <fstream>
#include "Core.h"

int main(int argc, const char * argv[]) {
    
    // Variable declaration
    Core coreVar(10, false, false);
    int dynamicArray[10];
    std::ifstream data;
    int index = 0;
    
    // Start reading file and getting values
    data.open("data.txt", std::ios::out);
    
    if (data.is_open()) {
        while (!data.eof()) {
            data >> dynamicArray[index];
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
        coreVar.pushElement(dynamicArray[i]);
    }
    
    coreVar.sortStackAscend();
    
    for (int i = 0; i < 10; i ++) {
        coreVar.popElement();
    }
    // End of house keeping
    
    // Start executing the second third of the functions int the Library
    std::cout << std::endl;
    coreVar.printOddNumbers();
    coreVar.getOddNumbersCounter();
    
    std::cout<< std::endl;
    coreVar.printEvenNumbers();
    coreVar.getEvenNumbersCounter();
    // End execution
    
    return 0;
}
