#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"


void EINT0Callback() 
{
    DrvGPIO_ClrBit(E_GPA, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPA, 12);
    DrvSYS_Delay(5000);
}

void EINT1Callback() 
{
    DrvGPIO_ClrBit(E_GPB, 11);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPB, 11);
    DrvSYS_Delay(5000);
}

void Init() {
    DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPA, 12);
    DrvGPIO_SetBit(E_GPB, 11);
}

int main (void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    Init();

    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);

    DrvGPIO_EnableEINT0(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT0Callback);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT1Callback);
    while(1)
    {
    }
}
