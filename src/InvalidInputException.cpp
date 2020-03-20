#define BACKWARD_HAS_BFD 1
#define BACKWARD_HAS_DW 1
#include "InvalidInputException.hpp"



const char *  InvalidInputException::what() const throw(){
    StackTrace st; 
    Printer p; p.print(st);    
    return "Divide By Zero Exception\n";
}