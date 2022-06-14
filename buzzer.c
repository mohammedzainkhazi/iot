#include <iostream>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"
void callback(void){
    DrvGPIO_ClrBit(E_GPB,11);
    DrvSYS_Delay(100000);
    DrvGPIO_SetBit(E_GPB,11);
    DrvSYS_Delay(100000);
}

void main(){
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    DrvGPIO_Open(E_GPB,15,E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,callback);
    while (1)
    {
        /* code */
    }
    
}