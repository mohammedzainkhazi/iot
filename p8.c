#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"

void EINT1Callback() 
{
    DrvGPIO_ClrBit(E_GPC, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPC, 12);
    DrvSYS_Delay(5000);
}

void EINT0Callback() 
{
    DrvGPIO_ClrBit(E_GPA, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPA, 12);
    DrvSYS_Delay(5000);
}

void Init_LED() {
    DrvGPIO_Open(E_GPA, 12, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPA, 12);
    DrvGPIO_SetBit(E_GPC, 12);
}

int main (void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    Init_LED();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_Open(E_GPB, 14, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT1Callback);
    DrvGPIO_EnableEINT0(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT0Callback);
    while(1)
    {
    }
}
