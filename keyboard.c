#include <stdio.h> 
#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "scankey.h"
#include "NUC1xx-LB_002\LCD_Driver.h"


void main(){
    char text[20] = "KEY BOARD INPUT";
    char text2[20] = "KEY";
    int number;
    UNCLOCKREG();
    DrvSYS_Open(48000000);
    LOCKREG();

    Initial_panel();
    clr_all_panel();

    print_lcd(0,text);
    OpenKeyPad();
    while (1)
    {
        number = ScanKey();
        sprintf(text2+8,"%d",number);
        print_lcd(1,number);
        DrvSYS_Delay(500000);
    }
}