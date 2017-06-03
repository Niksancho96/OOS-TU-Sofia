//
//  Core.h
//  Course Project
//
//  Created by Niko Mitov on 5/8/17.
//  Copyright © 2017 Niko Mitov. All rights reserved.
//

#ifndef Core_h
#define Core_h

#include <iostream>
#include <time.h>
#include <fstream>

// Initialising the Core class with all the needen functions for a Stack Library
class Core {
    int stackSize, stackMemorySize, oddNumbers, evenNumbers;
    int* stackValues;
    
public:
    Core(int, bool, bool);
    void printStackValues();
    void printStackSize();
    int StackMemorySize();
    void printOddNumbers();
    void getOddNumbersCounter();
    void printEvenNumbers();
    void getEvenNumbersCounter();
    void sortStackDecend();
    void sortStackAscend();
    void pushElement(int);
    void popElement();
};

// Constructor of the Core Library
Core::Core(int userInputStackSize, bool customNumbers, bool createFile) {
    if (customNumbers == false) {
        // Checks if the user is trying to crash the program
        if (userInputStackSize <= 0) {
            userInputStackSize = 1;
        }
        
        // Generates a new Dynamic Array, with size the user has entered
        stackSize = userInputStackSize;
        stackValues = new int[userInputStackSize];
        
        for (int index = 0; index < stackSize; index ++) {
            stackValues[index] = 0;
        }
    } else {
        // Checks if the user is trying to crash the program
        if (userInputStackSize <= 0) {
            userInputStackSize = 1;
        }
        
        // Generates a new Dynamic Array, with size the user has entered
        stackSize = userInputStackSize;
        stackValues = new int[userInputStackSize];
        
        // Generates the new Stack Array with time.h Library
        srand(time(0));
        for (int index = 0; index < stackSize; index ++) {
            stackValues[index] = std::rand() % 101;
        }
        
        // Checks to see if there are any duplicating numbers in the generated stack
        for (int index = 0; index < stackSize; index ++) {
            if (stackValues[index] == stackValues[index + 1]) {
                stackValues[index + 1] = std::rand() % 101;
            }
        }
    }
    
    if (createFile == true) {
        // Check to see if there is already a file created with the memmory addresses
        if (std::ifstream("/Users/nikomitov/Documents/Course Project/data.txt")) {
            std::remove("/Users/nikomitov/Documents/Course Project/data.txt");
        }
        
        // Creates the new, fresh file for storing the new information
        std::ofstream data("/Users/nikomitov/Documents/Course Project/data.txt", std::ios::in);
        data.open("/Users/nikomitov/Documents/Course Project/data.txt");
        
        // Checks if the file opened up correctly
        if (data.is_open() == true) {
            for (int index = 0; index < stackSize; index ++) {
                data << stackValues[index] << std::endl;
            }
        } else {
            std::cout << "Error retrieving file!" << std::endl;
        }
        
        data.close();
    }
}

void Core::printStackValues() {
    std::cout << "Printing stack values: " << std::endl;
    for (int index = 0; index < stackSize; index ++) {
        std::cout << "Element [" << index << "] = " << stackValues[index] << std::endl;
    }
}

void Core::printStackSize() {
    std::cout << "Stack Size: " << stackSize << std::endl;
}

int Core::StackMemorySize() {
    return sizeof(stackValues);
}

void Core::printOddNumbers() {
    std::cout << "Printing Odd numbers: " << std::endl;
    for (int index = 0; index < stackSize; index ++) {
        if (stackValues[index] % 2 != 0) {
            oddNumbers += 1;
            std::cout << "Element [" << index << "] = " << stackValues[index] << " is Odd." << std::endl;
        }
    }
}

void Core::getOddNumbersCounter() {
    std::cout << "Odd numbers counter: " << oddNumbers << "!" << std::endl;
}

void Core::printEvenNumbers() {
    std::cout << "Printing Even numbers: " << std::endl;
    for (int index = 0; index < stackSize; index ++) {
        if (stackValues[index] % 2 == 0) {
            evenNumbers += 1;
            std::cout << "Element [" << index << "] = " << stackValues[index] << " is Even." << std::endl;
        }
    }
}

void Core::getEvenNumbersCounter() {
    std::cout << "Even numbers coutner: " << evenNumbers << "!" << std::endl;
}

void Core::sortStackAscend() {
    int tempVariable;
    for (int index = 0; index < stackSize - 1; index ++) {
        for (int counter = 0; counter < stackSize - index - 1; counter ++) {
            if (stackValues[counter] > stackValues[counter + 1]) {
                tempVariable = stackValues[counter];
                stackValues[counter] = stackValues[counter + 1];
                stackValues[counter + 1] = tempVariable;
            }
        }
    }
}

void Core::sortStackDecend() {
    int tempVariable;
    for (int index = 0; index < stackSize - 1; index ++) {
        for (int counter = 0; counter < stackSize - index - 1; counter ++) {
            if (stackValues[counter] < stackValues[counter + 1]) {
                tempVariable = stackValues[counter];
                stackValues[counter] = stackValues[counter + 1];
                stackValues[counter + 1] = tempVariable;
            }
        }
    }
}

void Core::pushElement (int newElement) {
    int tempArray[stackSize];
    for (int index = 0; index < stackSize; index ++) {
        tempArray[index] = stackValues[index];
    }
    
    stackSize += 1;
    stackValues = new int[stackSize];
    stackValues[0] = newElement;
    
    for (int index = 1; index < stackSize; index ++) {
        stackValues[index] = tempArray[index - 1];
    }
}


void Core::popElement() {
    int tempArray[stackSize - 1];
    for (int index = 1; index < stackSize; index ++) {
        tempArray[index - 1] = stackValues[index];
    }
    
    stackSize -= 1;
    stackValues = new int[stackSize];
    
    for (int index = 0; index < stackSize; index ++) {
        stackValues[index] = tempArray[index];
    }
}

#endif /* Core_h */
