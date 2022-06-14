#include<stdio.h>

void callback(void){
    DrvGPIO_ClrBit(E_GPC,13);
    DrvSYS_Delay(300000);
    DrvGPIO_SetBit(E_GPC,13);
    DrvSYS_Delay(300000);
}

void main(){
    UNLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    DrvGPIO_Open(E_GPC,12,E_IO_OUTPUT);
    DrvGPIO_SetBit(E_GPC,12);

    DrvGPIO_Open(E_GPB,15,E_IO_INPUT);
    DrvGPIO_EnableEINT1(E_IO_BOTH_EDGE,E_MODE_EDGE,callback);
    while (1)
    {
        /* code */
    }
    
}