#define BACKWARD_HAS_BFD 1
#define BACKWARD_HAS_DW 1

#include "InvalidInputException.hpp"

#include <iostream>
#include <exception>
using namespace std;
using namespace backward;

int main(void){
    int ite;
    cin >> ite;
    if(ite==0){
        InvalidInputException exc;
        throw exc;
    }

    int a=0;
    int b=1;
    for (int i=0;i<ite;i++){
        int c=a+b;
        a=b;
        b=c;
    }
    return 0;
}