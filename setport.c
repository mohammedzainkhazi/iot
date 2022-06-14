#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvGPIO.h"
#include "Driver\DrvSYS.h"

void Init_LED()
{
    DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 13, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 14, E_IO_OUTPUT);
    DrvGPIO_Open(E_GPC, 15, E_IO_OUTPUT);
}
int main(void)
{
    UNLOCKREG();
    DrvSYS_Open(48000000);

    LOCKREG();
    Init_LED();
    while (1)
    {
        DrvGPIO_SetPortBits(E_GPC, 0xffff0fff);
        DrvSYS_Delay(300000);
        DrvGPIO_SetPortBits(E_GPC, 0xffffffff);
        DrvSYS_Delay(300000);
    }
}