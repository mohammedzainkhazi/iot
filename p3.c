#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"

void callback(){
    DrvGPIO_ClrBit(E_GPA,12);
    DrvSYS_Delay(5000);

    DrvGPIO_SetBit(E_GPA,12);
    DrvSYS_Delay(5000);
}

void Init_LED(){
    DrvGPIO_Open(E_GPA,12,E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPA,12);
}

int main (void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    Init_LED();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,callback);
    while(1)
    {
    }
}
