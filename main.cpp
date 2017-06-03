//
//  main.cpp
//  Course Project
//
//  Created by Niko Mitov on 5/8/17.
//  Copyright © 2017 Niko Mitov. All rights reserved.
//

#include <iostream>
#include "Core.h"

int main(int argc, const char * argv[]) {
    
    std::cout << ("Current stack size is 10.") << std::endl;
    
    Core coreVariable (10, true, true);
    std::cout << std::endl;
    
    coreVariable.printStackValues();
    std::cout << std::endl;
    
    coreVariable.printStackSize();
    
    return 0;
}
