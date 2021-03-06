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
