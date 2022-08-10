#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvADC.h"

void EINT1Callback() 
{
    DrvGPIO_ClrBit(E_GPC, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_ClrBit(E_GPC, 13);
    DrvSYS_Delay(5000);
    DrvGPIO_ClrBit(E_GPC, 14);
    DrvSYS_Delay(5000);
    DrvGPIO_ClrBit(E_GPC, 15);
    DrvSYS_Delay(5000);

    DrvGPIO_SetBit(E_GPC, 12);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPC, 13);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPC, 14);
    DrvSYS_Delay(5000);
    DrvGPIO_SetBit(E_GPC, 15);
    DrvSYS_Delay(5000);
}

void Init_LED() {
    DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC, 12);
    DrvGPIO_SetBit(E_GPC, 13);
    DrvGPIO_SetBit(E_GPC, 14);
    DrvGPIO_SetBit(E_GPC, 15);
}

int main (void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();
    Init_LED();
    DrvGPIO_Open(E_GPB, 15, E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,EINT1Callback);
    while(1)
    {
    }
}
