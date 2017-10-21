#include<iostream>
#include "bits.hpp"

using namespace std;
using namespace bits;

void bits::poner1(uchar *byte, int pos){
    if(!consultarBit((*byte),pos)){
        (*byte) ^= (1<<pos);
    }
}

void bits::poner0(uchar *byte, int pos){
    if(consultarBit((*byte),pos)){
        (*byte) ^= (1<<pos);
    }
}

int bits::consultarBit(uchar byte, int pos){
    if((byte)&(1<<pos)){
        return 1;
    }
    return 0;
}

void bits::imprimirByte(uchar byte){
    for(int i = 7 ; i >= 0 ; i--){
        cout << consultarBit(byte,i);
    }
    cout << endl;
}
